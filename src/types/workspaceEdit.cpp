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

#include <libclsp/types/workspaceEdit.hpp>

namespace libclsp
{

using namespace std;

const String WorkspaceEdit::changesKey         = "changes";
const String WorkspaceEdit::documentChangesKey = "documentChangesKey";

WorkspaceEdit::WorkspaceEdit(optional<Changes> changes,
	optional<
		variant<
			vector<TextDocumentEdit>,
			vector<
				variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>
			>
		>
	> documentChanges):
		changes(changes),
		documentChanges(documentChanges)
{};

WorkspaceEdit::WorkspaceEdit():
	changes(),
	documentChanges()
{};

WorkspaceEdit::~WorkspaceEdit(){};


WorkspaceEdit::Changes::Changes(map<DocumentUri, vector<TextEdit>> changes):
	changes(changes)
{};

WorkspaceEdit::Changes::Changes():
	changes()
{};

WorkspaceEdit::Changes::~Changes(){};


const String WorkspaceEditClientCapabilities::
	documentChangesKey    = "documentChanges";

const String WorkspaceEditClientCapabilities::
	resourceOperationsKey = "resourceOperations";

const String WorkspaceEditClientCapabilities::
	failureHandlingKey    = "failureHandling";

WorkspaceEditClientCapabilities::
	WorkspaceEditClientCapabilities(optional<Boolean> documentChanges,
		optional<vector<ResourceOperationKind>> resourceOperations,
		optional<FailureHandlingKind> failureHandling):
			documentChanges(documentChanges),
			resourceOperations(resourceOperations),
			failureHandling(failureHandling)
{};

WorkspaceEditClientCapabilities::WorkspaceEditClientCapabilities():
	documentChanges(),
	resourceOperations(),
	failureHandling()
{};

WorkspaceEditClientCapabilities::~WorkspaceEditClientCapabilities(){};

}
