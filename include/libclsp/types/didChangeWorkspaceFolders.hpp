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

#include <libclsp/types/workspaceFolder.hpp>

namespace libclsp
{

using namespace std;

/// The workspace folder change event.
///
/// added: WorkspaceFolder[]
///
/// removed: WorkspaceFolder[]
///
struct WorkspaceFoldersChangeEvent
{
	const static String addedKey;;

	/// The array of added workspace folders
	vector<WorkspaceFolder> added;


	const static String removedKey;;

	/// The array of the removed workspace folders
	vector<WorkspaceFolder> removed;


	WorkspaceFoldersChangeEvent(vector<WorkspaceFolder> added,
		vector<WorkspaceFolder> removed);

	WorkspaceFoldersChangeEvent();

	virtual ~WorkspaceFoldersChangeEvent();

};

/// The workspace/didChangeWorkspaceFolders notification is sent from the client
/// to the server to inform the server about workspace folder configuration
/// changes
///
/// event: WorkspaceFoldersChangeEvent
///
struct DidChangeWorkspaceFoldersParams
{
	const static String eventKey;

	/// The actual workspace folder change event.
	WorkspaceFoldersChangeEvent event;

	DidChangeWorkspaceFoldersParams(WorkspaceFoldersChangeEvent event);

	DidChangeWorkspaceFoldersParams();

	virtual ~DidChangeWorkspaceFoldersParams();
};


}
