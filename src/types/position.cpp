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

#include <libclsp/types/position.hpp>

namespace clsp
{

using namespace std;

const String Position::lineKey      = "line";
const String Position::characterKey = "character";


Position::Position(Number line, Number character):
	line(line),
	character(character)
{};

Position::Position(){};
Position::~Position(){};

void Position::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// line:
	setterMap.emplace(
		lineKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				line = n;
				neededMap[lineKey] = true;
			},

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// character:
	setterMap.emplace(
		characterKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				character = n;
				neededMap[characterKey] = true;
			},

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(lineKey, 0);
	neededMap.emplace(characterKey, 0);

	// This
	initializer.object = this;
}

void Position::partialWrite(JsonWriter &writer)
{
	// line
	writer.Key(lineKey);
	writer.Number(line);

	// character
	writer.Key(characterKey);
	writer.Number(character);
}

}
