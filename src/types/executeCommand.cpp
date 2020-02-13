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

#include <libclsp/types/executeCommand.hpp>

namespace clsp
{

using namespace std;

const String ExecuteCommandClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

ExecuteCommandClientCapabilities::
	ExecuteCommandClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

ExecuteCommandClientCapabilities::ExecuteCommandClientCapabilities(){};
ExecuteCommandClientCapabilities::~ExecuteCommandClientCapabilities(){};

void ExecuteCommandClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}


const String ExecuteCommandOptions::commandsKey = "commands";

ExecuteCommandOptions::ExecuteCommandOptions(optional<Boolean> workDoneProgress,
	vector<String> commands):
		WorkDoneProgressOptions(workDoneProgress),
		commands(commands)
{};

ExecuteCommandOptions::ExecuteCommandOptions(){};
ExecuteCommandOptions::~ExecuteCommandOptions(){};

void ExecuteCommandOptions::partialWrite(JsonWriter &writer)
{
	// Parent
	WorkDoneProgressOptions::partialWrite(writer);

	// commands
	writer.Key(commandsKey);
	writer.StartArray();
	for(auto& i: commands)
	{
		writer.String(i);
	}
	writer.EndArray();
}


const String ExecuteCommandParams::commandKey   = "command";
const String ExecuteCommandParams::argumentsKey = "arguments";

ExecuteCommandParams::ExecuteCommandParams(optional<ProgressToken> workDoneToken,
	String command,
	optional<Array> arguments):
		WorkDoneProgressParams(workDoneToken),
		command(command),
		arguments(arguments)
{};

ExecuteCommandParams::ExecuteCommandParams(){};
ExecuteCommandParams::~ExecuteCommandParams(){};

void ExecuteCommandParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parent
	WorkDoneProgressParams::fillInitializer(initializer);

	// Value setters

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
	neededMap.emplace(commandKey, 0);

	// This
	initializer.object = this;
}

}
