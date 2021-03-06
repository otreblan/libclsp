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
struct ExecuteCommandClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Execute command supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

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
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String commandsKey;

public:
	/// The commands to be executed on the server
	vector<String> commands;

	// No parsing

	ExecuteCommandOptions(optional<Boolean> workDoneProgress,
		vector<String> commands);

	ExecuteCommandOptions();

	virtual ~ExecuteCommandOptions();
};

/// Execute command registration options.
using ExecuteCommandRegistrationOptions = ExecuteCommandOptions; // No parsing

/// workspace/executeCommand params
///
/// command: String
///
/// arguments?: Array
///
struct ExecuteCommandParams: public WorkDoneProgressParams
{
private:
	const static String commandKey;
	const static String argumentsKey;

public:
	/// The identifier of the actual command handler.
	String command;

	/// Arguments that the command should be invoked with.
	optional<Array> arguments;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	ExecuteCommandParams(optional<ProgressToken> workDoneToken,
		String command,
		optional<Array> arguments);

	ExecuteCommandParams();

	virtual ~ExecuteCommandParams();
};

}
