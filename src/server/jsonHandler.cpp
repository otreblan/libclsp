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

#include <libclsp/server/jsonHandler.hpp>
#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;

bool JsonHandler::Null()
{

	function<void()> setNull;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNull.has_value())
		{
			setNull = jsonPair->second.setNull.value();
		}
		else
		{
			// This Key is not a Null
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setNull = extraSetter->setNull.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setNull();

	return true;
}

bool JsonHandler::Bool(bool b)
{
	function<void(bool)> setBoolean;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setBoolean.has_value())
		{
			setBoolean = jsonPair->second.setBoolean.value();
		}
		else
		{
			// This Key is not a Boolean
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setBoolean = extraSetter->setBoolean.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setBoolean(b);

	return true;
}

bool JsonHandler::Number(libclsp::Number n)
{
	function<void(libclsp::Number)> setNumber;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNumber.has_value())
		{
			setNumber = jsonPair->second.setNumber.value();
		}
		else
		{
			// This Key is not a Number
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setNumber = extraSetter->setNumber.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setNumber(n);

	return true;
}

bool JsonHandler::Int(int i)
{
	return Number(i);
}

bool JsonHandler::Uint(unsigned u)
{
	return Number((int)u);
}

bool JsonHandler::Int64(int64_t i)
{
	return Number((int)i);
}

bool JsonHandler::Uint64(uint64_t u)
{
	return Number((int)u);
}

bool JsonHandler::Double(double d)
{
	return Number(d);
}

bool JsonHandler::String(const char* str, SizeType, bool)
{
	function<void(libclsp::String)> setString;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setString.has_value())
		{
			setString = jsonPair->second.setString.value();
		}
		else
		{
			// This Key is not a String
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setString = extraSetter->setString.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setString(str);

	return true;
}

bool JsonHandler::StartObject()
{
	function<void()> setObject;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setObject.has_value())
		{
			setObject = jsonPair->second.setObject.value();
		}
		else
		{
			// This Key is not a Object
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setObject = extraSetter->setObject.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setObject();

	return true;
}

bool JsonHandler::Key(const char* str, SizeType, bool)
{
	lastKey = str;

	return true;
}

bool JsonHandler::EndObject(SizeType)
{
	if(objectStack.top().object->isValid(*this))
	{
		objectStack.pop();

		// The key returns to the last Object/Array
		lastKey = objectStack.top().key;

		return true;
	}
	else
	{
		return false;
	}
}

bool JsonHandler::StartArray()
{
	function<void()> setArray;


	auto topArray = objectStack.top();

	auto& setterMap = topArray.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setArray.has_value())
		{
			setArray = jsonPair->second.setArray.value();
		}
		else
		{
			// This Key is not a Array
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topArray.extraSetter;

		if(extraSetter.has_value())
		{
			setArray = extraSetter->setArray.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setArray();

	return true;
}

bool JsonHandler::EndArray(SizeType elementCount)
{
	// ObjectT is also used by array makers
	return EndObject(elementCount);
}

void JsonHandler::preFillInitializer()
{
	objectStack.emplace(ObjectInitializer{
		lastKey,
		{},
		{},
		{},
		nullptr
	});
}

}
