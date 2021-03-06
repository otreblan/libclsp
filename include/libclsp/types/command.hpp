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

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/objectT.hpp>

namespace clsp
{

using namespace std;

/// Represents a reference to a command.
///
/// title: String
///
/// command: String
///
/// arguments?: Array
///
struct Command: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String titleKey;
	const static String commandKey;
	const static String argumentsKey;

public:
	/// Title of the command, like `save`.
	String title;

	/// The identifier of the actual command handler.
	String command;

	/// Arguments that the command handler should be
	/// invoked with.
	optional<Array> arguments;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	Command(String title, String command, optional<Array> arguments);

	Command();

	virtual ~Command();
};

}
