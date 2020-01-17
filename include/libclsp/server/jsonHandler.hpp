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

#pragma once

#include <variant>
#include <optional>
#include <functional>
#include <map>
#include <stack>

#include <rapidjson/reader.h>

#include <libclsp/types/jsonTypes.hpp>

namespace libclsp
{

using namespace std;
using namespace rapidjson;

/// Functions to initialize a json member
struct ValueSetter
{
	/// Sets a String in an object
	optional<function<void(String)>> setString;

	/// Sets a Number in an object
	optional<function<void(Number)>> setNumber;

	/// Sets a Boolean in an object
	optional<function<void(Boolean)>> setBoolean;

	/// Sets Null in an object
	optional<function<void()>> setNull;

	/// Creates an Array in an object
	optional<function<void()>> setArray;

	/// Changes to the next object
	optional<function<void()>> setObject;

};

/// Data for the object initialization
struct ObjectInitializer
{
	/// The key from which the object is the value
	Key key;

	/// A map with the keys of the object and it's initializers
	map<Key, ValueSetter> setterMap;

	/// An optional setter for objects with index signatures
	optional<ValueSetter> extraSetter;

	/// The object or array being initialized
	ObjectT* object;
};

struct JsonHandler: public BaseReaderHandler<UTF8<>, JsonHandler>
{

	/// The top of this stack represents the path of the object being
	/// constructed and the functions to initialize it's members
	stack<ObjectInitializer> objectStack;

	/// Last key obtained by Key()
	libclsp::String lastKey;

	// Functions needed by the RapidJson reader.

	bool Null();
	bool Bool(bool b);

	// Generic number wrapper
	bool Number(libclsp::Number n);

	bool Int(int i);
	bool Uint(unsigned u);
	bool Int64(int64_t i);
	bool Uint64(uint64_t u);
	bool Double(double d);

	bool String(const char* str, SizeType length, bool copy);
	bool StartObject();
	bool Key(const char* str, SizeType length, bool copy);
	bool EndObject(SizeType memberCount);
	bool StartArray();
	bool EndArray(SizeType elementCount);

};

}
