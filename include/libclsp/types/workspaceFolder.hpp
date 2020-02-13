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

/// workspace/workspaceFolders server capabilities
///
/// supported?: Boolean
///
/// changeNotifications?: String | Boolean
///
struct WorkspaceFoldersServerCapabilities: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String supportedKey;
	const static String changeNotificationsKey;

public:
	/// The server has support for workspace folders
	optional<Boolean> supported;

	/// Whether the server wants to receive workspace folder
	/// change notifications.
	///
	/// If a string is provided the string is treated as an ID
	/// under which the notification is registered on the client
	/// side. The ID can be used to unregister for these events
	/// using the `client/unregisterCapability` request.
	optional<variant<String, Boolean>> changeNotifications;

	// No parsing

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
struct WorkspaceFolder: public ObjectT
{
private:
	const static String uriKey;
	const static String nameKey;

public:
	/// The associated URI for this workspace folder.
	DocumentUri uri;

	/// The name of the workspace folder. Used to refer to this
	/// workspace folder in the user interface.
	String name;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	WorkspaceFolder(DocumentUri uri, String name);

	WorkspaceFolder();

	virtual ~WorkspaceFolder();
};

}
