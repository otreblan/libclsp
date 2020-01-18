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

#include <libclsp/types/location.hpp>

namespace libclsp
{

using namespace std;

const String Location::uriKey   = "uri";
const String Location::rangeKey = "range";

Location::Location(DocumentUri uri, Range range):
	uri(uri),
	range(range)
{};

Location::Location(){};
Location::~Location(){};

void Location::fillInitializer(JsonHandler& handler)
{
	auto& topValue = handler.objectStack.top();

	auto& setterMap = topValue.setterMap;
	auto& neededMap = topValue.neededMap;

	// Value setters

	// uri:
	setterMap.emplace(
		uriKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				uri = str;

				neededMap[uriKey] = true;
			},

			// Number
			{},

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

	// range:
	setterMap.emplace(
		rangeKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, &neededMap, &handler]()
			{
				handler.preFillInitializer();

				range.fillInitializer(handler);

				neededMap[rangeKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(uriKey, 0);
	neededMap.emplace(rangeKey, 0);

	// This
	topValue.object = this;
}

}
