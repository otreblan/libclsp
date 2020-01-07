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

#include <libclsp/messages/applyWorkspaceEdit.hpp>

namespace libclsp
{

using namespace std;

const String ApplyWorkspaceEditParams::labelKey = "label";
const String ApplyWorkspaceEditParams::editKey  = "edit";

ApplyWorkspaceEditParams::ApplyWorkspaceEditParams(optional<String> label,
	WorkspaceEdit edit):
		label(label),
		edit(edit)
{};

ApplyWorkspaceEditParams::ApplyWorkspaceEditParams():
		label(),
		edit()
{};

ApplyWorkspaceEditParams::~ApplyWorkspaceEditParams(){};


const String ApplyWorkspaceEditResponse::appliedKey       = "applied";
const String ApplyWorkspaceEditResponse::failureReasonKey = "failureReason";

ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse(Boolean applied,
	optional<String> failureReason):
		applied(applied),
		failureReason(failureReason)
{};

ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse():
	applied(),
	failureReason()
{};

ApplyWorkspaceEditResponse::~ApplyWorkspaceEditResponse(){};

}
