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
			auto* maker = new ArrayMaker(*this, handler->lastKey);

			children[handler->lastKey] = Array();

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

GenericObject::ArrayMaker::ArrayMaker(GenericObject& parent, string key):
	parent(parent),
	key(key)
{};

GenericObject::ArrayMaker::~ArrayMaker(){};

void GenericObject::ArrayMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;
	auto& Vector = get<Array>(parent.children[key]);

	// Value setters

	// Almost anything
	extraSetter =
	{
		// String
		[&Vector](String str)
		{
			Vector.emplace_back(str);
		},

		// Number
		[&Vector](Number n)
		{
			Vector.emplace_back(n);
		},

		// Boolean
		[&Vector](Boolean b)
		{
			Vector.emplace_back(b);
		},

		// Null
		[&Vector]()
		{
			Vector.emplace_back(Null());
		},

		// Array
		{},

		// Object
		[&Vector, handler]()
		{
			auto obj = make_shared<GenericObject>();

			Vector.emplace_back(obj);

			handler->preFillInitializer();

			obj->fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;

	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);
}

}
