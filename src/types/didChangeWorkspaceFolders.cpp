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

#include <libclsp/types/didChangeWorkspaceFolders.hpp>

namespace libclsp
{

using namespace std;

const String WorkspaceFoldersChangeEvent::addedKey   = "added";
const String WorkspaceFoldersChangeEvent::removedKey = "removed";

WorkspaceFoldersChangeEvent::WorkspaceFoldersChangeEvent(
	vector<WorkspaceFolder> added,
	vector<WorkspaceFolder> removed):
		added(added),
		removed(removed)
{};

WorkspaceFoldersChangeEvent::WorkspaceFoldersChangeEvent(){};
WorkspaceFoldersChangeEvent::~WorkspaceFoldersChangeEvent(){};

void WorkspaceFoldersChangeEvent::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// added:
	setterMap.emplace(
		addedKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler, &neededMap]()
			{
				auto* maker = new AddedRemovedMaker(added);

				handler->preFillInitializer();
				maker->fillInitializer(handler->objectStack.top());

				neededMap[addedKey] = true;
			},

			// Object
			{}
		}
	);

	// removed:
	setterMap.emplace(
		removedKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler, &neededMap]()
			{
				auto* maker = new AddedRemovedMaker(removed);

				handler->preFillInitializer();
				maker->fillInitializer(handler->objectStack.top());

				neededMap[removedKey] = true;
			},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(addedKey, 0);
	neededMap.emplace(removedKey, 0);

	// This
	initializer.object = this;
}


WorkspaceFoldersChangeEvent::AddedRemovedMaker::
	AddedRemovedMaker(vector<WorkspaceFolder>& parentArray):
		parentArray(parentArray)
{};

WorkspaceFoldersChangeEvent::AddedRemovedMaker::~AddedRemovedMaker(){};

void WorkspaceFoldersChangeEvent::AddedRemovedMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// WorkspaceFolder[]
	extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		[this, handler]()
		{
			auto& newObj = parentArray.emplace_back();

			handler->preFillInitializer();

			newObj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;

	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);
}


const String DidChangeWorkspaceFoldersParams::eventKey = "event";

DidChangeWorkspaceFoldersParams::
	DidChangeWorkspaceFoldersParams(WorkspaceFoldersChangeEvent event):
		event(event)
{};

DidChangeWorkspaceFoldersParams::DidChangeWorkspaceFoldersParams(){};
DidChangeWorkspaceFoldersParams::~DidChangeWorkspaceFoldersParams(){};

void DidChangeWorkspaceFoldersParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// event:
	setterMap.emplace(
		eventKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->preFillInitializer();
				event.fillInitializer(handler->objectStack.top());

				neededMap[eventKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(eventKey, 0);

	// This
	initializer.object = this;
}

}
