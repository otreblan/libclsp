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

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// Represents a reference to a command.
///
/// title: string;
///
/// command: string;
///
/// arguments?: any[];
///
struct Command
{

	const static String titleKey;

	/// Title of the command, like `save`.
	String title;


	const static String commandKey;

	/// The identifier of the actual command handler.
	String command;


	const static String argumentsKey;

	/// Arguments that the command handler should be
	/// invoked with.
	optional<vector<Any>> arguments;


	Command(String title, String command, optional<vector<Any>> arguments);

	Command();

	virtual ~Command();
};

}
