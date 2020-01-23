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

#include <optional>

#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// workspace/executeCommand client capabilities
///
/// dynamicRegistration?: Boolean
///
struct ExecuteCommandClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Execute command supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	ExecuteCommandClientCapabilities(optional<Boolean> dynamicRegistration);

	ExecuteCommandClientCapabilities();

	virtual ~ExecuteCommandClientCapabilities();
};

/// workspace/executeCommand options
///
/// commands: String[]
///
struct ExecuteCommandOptions: public WorkDoneProgressOptions
{

	const static String commandsKey;

	/// The commands to be executed on the server
	vector<String> commands;


	ExecuteCommandOptions(optional<Boolean> workDoneProgress,
		vector<String> commands);

	ExecuteCommandOptions();

	virtual ~ExecuteCommandOptions();
};

/// Execute command registration options.
using ExecuteCommandRegistrationOptions = ExecuteCommandOptions;

/// workspace/executeCommand params
///
/// command: String
///
/// arguments?: Any[]
///
struct ExecuteCommandParams: public WorkDoneProgressParams
{

	const static String commandKey;

	/// The identifier of the actual command handler.
	String command;


	const static String argumentsKey;

	/// Arguments that the command should be invoked with.
	optional<vector<Any>> arguments;


	ExecuteCommandParams(optional<ProgressToken> workDoneToken,
		String command,
		optional<vector<Any>> arguments);

	ExecuteCommandParams();

	virtual ~ExecuteCommandParams();
};

}
