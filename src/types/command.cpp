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

#include <libclsp/types/command.hpp>
#include <libclsp/types/genericObject.hpp>

namespace clsp
{

using namespace std;

const String Command::titleKey     = "title";
const String Command::commandKey   = "command";
const String Command::argumentsKey = "arguments";

Command::Command(String title, String command, optional<Array> arguments):
	title(title),
	command(command),
	arguments(arguments)
{};

Command::Command(){};
Command::~Command(){};

void Command::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// title:
	setterMap.emplace(
		titleKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				title = str;
				neededMap[titleKey] = true;
			},

			// Number
			nullopt,

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

	// command:
	setterMap.emplace(
		commandKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				command = str;
				neededMap[commandKey] = true;
			},

			// Number
			nullopt,

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

	// arguments?:
	setterMap.emplace(
		argumentsKey,
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
			[this, handler]()
			{
				arguments.emplace();

				handler->pushInitializer();

				auto* maker = new ArrayMaker(arguments.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(titleKey, 0);
	neededMap.emplace(commandKey, 0);

	// This
	initializer.object = this;
}

}
