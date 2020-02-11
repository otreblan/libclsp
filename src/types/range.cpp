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

#include <libclsp/types/range.hpp>

namespace clsp
{

using namespace std;

const String Range::startKey = "start";
const String Range::endKey   = "end";


Range::Range(Position start, Position end):
	start(start),
	end(end)
{};

Range::Range(){};
Range::~Range(){};

void Range::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// start:
	setterMap.emplace(
		startKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();
				start.fillInitializer(handler->objectStack.top());

				neededMap[startKey] = true;
			}
		}
	);

	// end:
	setterMap.emplace(
		endKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();
				end.fillInitializer(handler->objectStack.top());

				neededMap[endKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(startKey, 0);
	neededMap.emplace(endKey, 0);

	// This
	initializer.object = this;
}

void Range::partialWrite(JsonWriter &writer)
{
	// start
	writer.Key(startKey);
	writer.Object(start);

	// end
	writer.Key(endKey);
	writer.Object(end);
}

}
