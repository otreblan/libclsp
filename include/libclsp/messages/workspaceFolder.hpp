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

/// workspace/workspaceFolders server capabilities
///
/// supported?: Boolean
///
/// changeNotifications?: String | Boolean
///
struct WorkspaceFoldersServerCapabilities
{

	const static String supportedKey;

	/// The server has support for workspace folders
	optional<Boolean> supported;


	const static String changeNotificationsKey;

	/// Whether the server wants to receive workspace folder
	/// change notifications.
	///
	/// If a strings is provided the string is treated as a ID
	/// under which the notification is registed on the client
	/// side. The ID can be used to unregister for these events
	/// using the `client/unregisterCapability` request.
	optional<variant<String, Boolean>> changeNotifications;


	WorkspaceFoldersServerCapabilities(optional<Boolean> supported,
		optional<variant<String, Boolean>> changeNotifications);

	WorkspaceFoldersServerCapabilities();

	virtual ~WorkspaceFoldersServerCapabilities();
};

/// Response of workspace/workspaceFolders
///
/// uri: DocumentUri
///
/// name: String
///
struct WorkspaceFolder
{

	const static String uriKey;

	/// The associated URI for this workspace folder.
	DocumentUri uri;


	const static String nameKey;

	/// The name of the workspace folder. Used to refer to this
	/// workspace folder in the user interface.
	String name;


	WorkspaceFolder(DocumentUri uri, String name);

	WorkspaceFolder();

	virtual ~WorkspaceFolder();
};

}
