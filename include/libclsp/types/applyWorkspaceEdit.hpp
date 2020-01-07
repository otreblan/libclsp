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

#include <libclsp/types/workspaceEdit.hpp>

namespace libclsp
{

using namespace std;

/// workspace/applyEdit params
///
/// label?: String
///
/// edit: WorkspaceEdit
///
struct ApplyWorkspaceEditParams
{

	const static String labelKey;

	/// An optional label of the workspace edit. This label is
	/// presented in the user interface for example on an undo
	/// stack to undo the workspace edit.
	optional<String> label;


	const static String editKey;

	/// The edits to apply.
	WorkspaceEdit edit;


	ApplyWorkspaceEditParams(optional<String> label, WorkspaceEdit edit);

	ApplyWorkspaceEditParams();

	virtual ~ApplyWorkspaceEditParams();
};

/// workspace/applyEdit response
///
/// applied: Boolean
///
/// failureReason?: String
///
struct ApplyWorkspaceEditResponse
{
	const static String appliedKey;

	/// Indicates whether the edit was applied or not.
	Boolean applied;


	const static String failureReasonKey;

	/// An optional textual description for why the edit was not applied.
	/// This may be used may be used by the server for diagnostic
	/// logging or to provide a suitable error for a request that
	/// triggered the edit.
	optional<String> failureReason;


	ApplyWorkspaceEditResponse(Boolean applied, optional<String> failureReason);

	ApplyWorkspaceEditResponse();

	virtual ~ApplyWorkspaceEditResponse();
};

}
