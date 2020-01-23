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

#include <libclsp/types/applyWorkspaceEdit.hpp>

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

ApplyWorkspaceEditParams::ApplyWorkspaceEditParams(){};
ApplyWorkspaceEditParams::~ApplyWorkspaceEditParams(){};


const String ApplyWorkspaceEditResponse::appliedKey       = "applied";
const String ApplyWorkspaceEditResponse::failureReasonKey = "failureReason";

ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse(Boolean applied,
	optional<String> failureReason):
		applied(applied),
		failureReason(failureReason)
{};

ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse(){};
ApplyWorkspaceEditResponse::~ApplyWorkspaceEditResponse(){};

void ApplyWorkspaceEditResponse::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// applied:
	setterMap.emplace(
		appliedKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this, &neededMap](Boolean b)
			{
				applied = b;
				neededMap[appliedKey] = true;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// failureReason?:
	setterMap.emplace(
		failureReasonKey,
		ValueSetter{
			// String
			[this](String str)
			{
				failureReason = str;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(appliedKey, 0);

	// This
	initializer.object = this;
}

}
