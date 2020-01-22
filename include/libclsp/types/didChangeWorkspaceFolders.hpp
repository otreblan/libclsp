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
struct WorkspaceFoldersChangeEvent: public ObjectT
{
private:
	const static String addedKey;
	const static String removedKey;;

	struct AddedRemovedMaker: public ObjectT
	{
		/// A reference to the vector to make
		vector<WorkspaceFolder>& parentArray;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		AddedRemovedMaker(vector<WorkspaceFolder>& parentArray);

		virtual ~AddedRemovedMaker();
	};

public:
	/// The array of added workspace folders
	vector<WorkspaceFolder> added;

	/// The array of the removed workspace folders
	vector<WorkspaceFolder> removed;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


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
struct DidChangeWorkspaceFoldersParams: public ObjectT
{
private:
	const static String eventKey;

public:
	/// The actual workspace folder change event.
	WorkspaceFoldersChangeEvent event;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DidChangeWorkspaceFoldersParams(WorkspaceFoldersChangeEvent event);

	DidChangeWorkspaceFoldersParams();

	virtual ~DidChangeWorkspaceFoldersParams();
};


}
