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

namespace libclsp
{

using namespace std;

const String ExecuteCommandClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

ExecuteCommandClientCapabilities::
	ExecuteCommandClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

ExecuteCommandClientCapabilities::ExecuteCommandClientCapabilities():
	dynamicRegistration()
{};

ExecuteCommandClientCapabilities::~ExecuteCommandClientCapabilities(){};


const String ExecuteCommandOptions::commandsKey = "commands";

ExecuteCommandOptions::ExecuteCommandOptions(optional<Boolean> workDoneProgress,
	vector<String> commands):
		WorkDoneProgressOptions(workDoneProgress),
		commands(commands)
{};

ExecuteCommandOptions::ExecuteCommandOptions():
	WorkDoneProgressOptions(),
	commands()
{};

ExecuteCommandOptions::~ExecuteCommandOptions(){};


const String ExecuteCommandParams::commandKey   = "command";
const String ExecuteCommandParams::argumentsKey = "arguments";

ExecuteCommandParams::ExecuteCommandParams(optional<ProgressToken> workDoneToken,
	String command,
	optional<vector<Any>> arguments):
		WorkDoneProgressParams(workDoneToken),
		command(command),
		arguments(arguments)
{};

ExecuteCommandParams::ExecuteCommandParams():
	WorkDoneProgressParams(),
	command(),
	arguments()
{};

ExecuteCommandParams::~ExecuteCommandParams(){};

}
