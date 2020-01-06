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
#include <map>

#include <libclsp/messages/textEdit.hpp>
#include <libclsp/messages/fileResourceChanges.hpp>

namespace libclsp
{

using namespace std;

/// A workspace edit represents changes to many resources
/// managed in the workspace.
//
/// changes?: { [uri: DocumentUri]: TextEdit[]; }
///
/// documentChanges?: (TextDocumentEdit[] | (TextDocumentEdit | CreateFile | RenameFile | DeleteFile)[])
///
struct WorkspaceEdit
{

	const static String changesKey;

	/// Holds changes to existing resources.
	optional<map<DocumentUri, vector<TextEdit>>> changes;


	const static String documentChangesKey;

	/// Depending on the client capability `workspace.workspaceEdit.resourceOperations`
	/// document changes are either an array of `TextDocumentEdit`s to express
	/// changes to n different text documents where each text document edit
	/// addresses a specific version of a text document. Or it can contain
	/// above `TextDocumentEdit`s mixed with create, rename and delete
	/// file / folder operations.
	///
	/// Whether a client supports versioned document edits is expressed via
	/// `workspace.workspaceEdit.documentChanges` client capability.
	///
	/// If a client neither supports `documentChanges` nor
	/// `workspace.workspaceEdit.resourceOperations` then only plain
	/// `TextEdit`s using the `changes` property are supported.
	optional<
		variant<
			vector<TextDocumentEdit>,
			vector<
				variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>
			>
		>
	> documentChanges;


	WorkspaceEdit(optional<map<DocumentUri, vector<TextEdit>>> changes,
		optional<
			variant<
				vector<TextDocumentEdit>,
				vector<
					variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>
				>
			>
		> documentChanges);

	WorkspaceEdit();

	virtual ~WorkspaceEdit();
};

enum class ResourceOperationKind
{
	/// Supports creating new files and folders.
	///
	/// 'create'
	Create,

	/// Supports renaming existing files and folders.
	///
	/// 'rename'
	Rename,

	/// Supports deleting existing files and folders.
	///
	/// 'delete'
	Delete
};

enum class FailureHandlingKind
{
	/// Applying the workspace change is simply aborted if one of the changes
	/// provided fails.
	/// All operations executed before the failing operation stay executed.
	///
	/// 'abort'
	Abort,

	/// All operations are executed transactionally. That means they either all
	/// succeed or no changes at all are applied to the workspace.
	///
	/// 'transactional'
	Transactional,

	/// If the workspace edit contains only textual file changes they are
	/// executed transactionally.
	/// If resource changes (create, rename or delete file) are part of the
	/// change the failure handling strategy is abort.
	///
	/// 'textOnlyTransactional'
	TextOnlyTransactional,

	/// The client tries to undo the operations already executed. But there is
	/// no guarantee that this succeeds.
	///
	/// 'undo'
	Undo
};

struct WorkspaceEditClientCapabilities
{

	const static String documentChangesKey;

	/// The client supports versioned document changes in `WorkspaceEdit`s
	optional<Boolean> documentChanges;


	const static String resourceOperationsKey;

	/// The resource operations the client supports. Clients should at least
	/// support 'create', 'rename' and 'delete' files and folders.
	///
	/// @since 3.13.0
	optional<vector<ResourceOperationKind>> resourceOperations;


	const static String failureHandlingKey;

	/// The failure handling strategy of a client if applying the workspace
	/// edit fails.
	///
	/// @since 3.13.0
	optional<FailureHandlingKind> failureHandling;


	WorkspaceEditClientCapabilities(optional<Boolean> documentChanges,
		optional<vector<ResourceOperationKind>> resourceOperations,
		optional<FailureHandlingKind> failureHandling);

	WorkspaceEditClientCapabilities();

	virtual ~WorkspaceEditClientCapabilities();

};

}
