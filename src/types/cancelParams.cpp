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

#include <libclsp/types/cancelParams.hpp>

namespace libclsp
{

using namespace std;

const String CancelParams::idKey = "id";

CancelParams::CancelParams(variant<Number, String> id):
	id(id)
{};

CancelParams::CancelParams(){};
CancelParams::~CancelParams(){};

void CancelParams::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// id:
	setterMap.emplace(
		idKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				id = str;
				neededMap[idKey] = true;
			},

			// Number
			[this, &neededMap](Number n)
			{
				id = n;
				neededMap[idKey] = true;
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(idKey, 0);

	// This
	initializer.object = this;
}

void CancelParams::write(JsonWriter &writer)
{
	writer.StartObject();

	partialWrite(writer);

	writer.EndObject();
}

void CancelParams::partialWrite(JsonWriter &writer)
{
	// id:
	writer.Key(idKey);
	visit(overload(
		[&writer](Number n)
		{
			writer.Number(n);
		},
		[&writer](String &str)
		{
			writer.String(str);
		}
	), id);
}

}
