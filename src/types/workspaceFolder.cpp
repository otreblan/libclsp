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

#include <libclsp/types/workspaceFolder.hpp>

namespace libclsp
{

using namespace std;

const String WorkspaceFoldersServerCapabilities::
	supportedKey           = "supported";
const String WorkspaceFoldersServerCapabilities::
	changeNotificationsKey = "changeNotifications";

WorkspaceFoldersServerCapabilities::
	WorkspaceFoldersServerCapabilities(optional<Boolean> supported,
		optional<variant<String, Boolean>> changeNotifications):
			supported(supported),
			changeNotifications(changeNotifications)
{};

WorkspaceFoldersServerCapabilities::WorkspaceFoldersServerCapabilities(){};
WorkspaceFoldersServerCapabilities::~WorkspaceFoldersServerCapabilities(){};


const String WorkspaceFolder::uriKey  = "uri";
const String WorkspaceFolder::nameKey = "name";

WorkspaceFolder::WorkspaceFolder(DocumentUri uri, String name):
	uri(uri),
	name(name)
{};

WorkspaceFolder::WorkspaceFolder(){};
WorkspaceFolder::~WorkspaceFolder(){};


void WorkspaceFolder::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// uri:
	setterMap.emplace(
		uriKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				uri = str;
				neededMap[uriKey] = true;
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

	// name:
	setterMap.emplace(
		nameKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				name = str;
				neededMap[nameKey] = true;
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
	neededMap.emplace(uriKey, 0);
	neededMap.emplace(nameKey, 0);

	// This
	initializer.object = this;
}

}
