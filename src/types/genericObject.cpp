// A C++17 library for language servers.
// Copyright © 2019-2020 otreblan
//
// libclsp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libclsp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

#include <libclsp/types/genericObject.hpp>

namespace libclsp
{

using namespace std;



GenericObject::GenericObject(map<String, Any> children):
	children(children)
{};

GenericObject::GenericObject(){};
GenericObject::~GenericObject(){};

void GenericObject::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// Anything
	extraSetter =
	{
		// String
		[this, handler](String str)
		{
			children[handler->lastKey] = str;
		},

		// Number
		[this, handler](Number n)
		{
			children[handler->lastKey] = n;
		},

		// Boolean
		[this, handler](Boolean b)
		{
			children[handler->lastKey] = b;
		},

		// Null
		[this, handler]()
		{
			children[handler->lastKey] = Null();
		},

		// Array
		[this, handler]()
		{
			auto& newArray = children.emplace(handler->lastKey, Array()).first->second;

			auto* maker = new ArrayMaker(get<Array>(newArray));

			handler->preFillInitializer();
			maker->fillInitializer(handler->objectStack.top());

		},

		// Object
		[this, handler]()
		{
			auto obj = make_shared<GenericObject>();

			children[handler->lastKey] = obj;

			handler->preFillInitializer();
			obj->fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}

ArrayMaker::ArrayMaker(Array& parentArray):
	parentArray(parentArray)
{};

ArrayMaker::~ArrayMaker(){};

void ArrayMaker::fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// Almost anything
	extraSetter =
	{
		// String
		[this](String str)
		{
			parentArray.emplace_back(str);
		},

		// Number
		[this](Number n)
		{
			parentArray.emplace_back(n);
		},

		// Boolean
		[this](Boolean b)
		{
			parentArray.emplace_back(b);
		},

		// Null
		[this]()
		{
			parentArray.emplace_back(Null());
		},

		// Array
		{},

		// Object
		[this, handler]()
		{
			auto obj = make_shared<GenericObject>();

			parentArray.emplace_back(obj);

			handler->preFillInitializer();

			obj->fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}

void GenericObject::write(JsonWriter &writer)
{
	writer.StartObject();

	partialWrite(writer);

	writer.EndObject();
}

void GenericObject::partialWrite(JsonWriter &writer)
{
	for(auto &i: children)
	{
		writer.Key(i.first);
		writer.Any(i.second);
	}
}

void GenericObject::reParse(JsonHandler& handler)
{
	auto reString = [&handler](String& str)
	{
		handler.String(str.c_str(), str.length(), false);
	};

	auto reNumber = [&handler](Number n)
	{
		handler.Number(n);
	};

	auto reBoolean = [&handler](Boolean b)
	{
		handler.Bool(b);
	};

	auto reNull = [&handler](Null)
	{
		handler.Null();
	};

	auto reObject = [&handler](Object obj)
	{

		if(auto gObj = dynamic_pointer_cast<GenericObject>(obj))
		{
			handler.StartObject();

			gObj->reParse(handler);

			handler.EndObject(gObj->children.size());
		}
		else
		{

			// This is why its called reparse

			// First the object is transformed to json

			JsonWriter writer;

			obj->write(writer);

			// Then a new object is made from that json

			GenericObject newObj;

			JsonHandler handler;

			handler.objectStack.emplace().extraSetter =
			{
				{},
				{},
				{},
				{},
				{},
				[&handler, &newObj]()
				{
					handler.preFillInitializer();

					newObj.fillInitializer(handler.objectStack.top());
				}
			};

			Reader r;

			StringStream s(writer.GetString());

			r.Parse(s, handler);


			// And finally from its children the json its reparsed

			handler.StartObject();

			newObj.reParse(handler);

			handler.EndObject(newObj.children.size());
		}

	};

	for(auto &i: children)
	{
		handler.Key(i.first.c_str(), i.first.length(), false);
		visit(overload(
			reString,
			reNumber,
			reBoolean,
			reNull,
			reObject,
			[&](Array& a)
			{
				handler.StartArray();
				for(auto& i: a)
				{
					visit(overload(
						reString,
						reNumber,
						reBoolean,
						reNull,
						reObject
					), i);
				}
				handler.EndArray(a.size());
			}
		), i.second);
	}
}

}
