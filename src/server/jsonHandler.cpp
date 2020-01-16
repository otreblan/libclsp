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

	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNull.has_value())
		{
			auto& setNull = jsonPair->second.setNull.value();

			setNull();
		}
		else
		{
			// This Key is not a Null
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::Bool(bool b)
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setBoolean.has_value())
		{
			auto& setBoolean = jsonPair->second.setBoolean.value();

			setBoolean(b);
		}
		else
		{
			// This Key is not a Boolean
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::Number(libclsp::Number n)
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNumber.has_value())
		{
			auto& setNumber = jsonPair->second.setNumber.value();

			setNumber(n);
		}
		else
		{
			// This Key is not a Number
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

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
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setString.has_value())
		{
			auto& setString = jsonPair->second.setString.value();

			setString(str);
		}
		else
		{
			// This Key is not a String
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

}
