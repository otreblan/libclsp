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

#include <libclsp/types/didChangeWatchedFiles.hpp>

namespace clsp
{

using namespace std;

const String DidChangeWatchedFilesClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DidChangeWatchedFilesClientCapabilities::
	DidChangeWatchedFilesClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DidChangeWatchedFilesClientCapabilities::
	DidChangeWatchedFilesClientCapabilities()
{};

DidChangeWatchedFilesClientCapabilities::
	~DidChangeWatchedFilesClientCapabilities()
{};

void DidChangeWatchedFilesClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}


const String FileSystemWatcher::globPatternKey = "globPattern";
const String FileSystemWatcher::kindKey        = "kind";

FileSystemWatcher::FileSystemWatcher(String globPattern, optional<WatchKind> kind):
	globPattern(globPattern),
	kind(kind)
{};

FileSystemWatcher::FileSystemWatcher(){};
FileSystemWatcher::~FileSystemWatcher(){};

void FileSystemWatcher::partialWrite(JsonWriter &writer)
{
	// globPattern
	writer.Key(globPatternKey);
	writer.String(globPattern);

	// kind?
	if(kind.has_value())
	{
		writer.Key(kindKey);
		writer.Int((int)(*kind));
	}
}


const String DidChangeWatchedFilesRegistrationOptions::watchersKey = "watchers";

DidChangeWatchedFilesRegistrationOptions::
	DidChangeWatchedFilesRegistrationOptions(vector<FileSystemWatcher> watchers):
		watchers(watchers)
{};

DidChangeWatchedFilesRegistrationOptions::
	DidChangeWatchedFilesRegistrationOptions()
{};

DidChangeWatchedFilesRegistrationOptions::
	~DidChangeWatchedFilesRegistrationOptions()
{};

void DidChangeWatchedFilesRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// watchers
	writer.Key(watchersKey);
	writer.StartArray();
	for(auto& i: watchers)
	{
		writer.Object(i);
	}
	writer.EndArray();
}


const String FileEvent::uriKey  = "uri";
const String FileEvent::typeKey = "type";

FileEvent::FileEvent(DocumentUri uri, FileChangeType type):
	uri(uri),
	type(type)
{};

FileEvent::FileEvent(){};
FileEvent::~FileEvent(){};

void FileEvent::fillInitializer(ObjectInitializer& initializer)
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
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// type:
	setterMap.emplace(
		typeKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				if(holds_alternative<int>(n))
				{
					int i = get<int>(n);

					type = (FileChangeType)i;
					neededMap[typeKey] = true;
				}
				else
				{
					// TODO: An exception or something
				}
			},

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(uriKey, 0);
	neededMap.emplace(typeKey, 0);

	// This
	initializer.object = this;
}


const String DidChangeWatchedFilesParams::changesKey = "changes";

DidChangeWatchedFilesParams::DidChangeWatchedFilesParams(vector<FileEvent> changes):
	changes(changes)
{};

DidChangeWatchedFilesParams::DidChangeWatchedFilesParams(){};
DidChangeWatchedFilesParams::~DidChangeWatchedFilesParams(){};

void DidChangeWatchedFilesParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// changes:
	setterMap.emplace(
		changesKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				auto *maker = new ChangesMaker(changes);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[changesKey] = true;
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(changesKey, 0);

	// This
	initializer.object = this;
}


DidChangeWatchedFilesParams::ChangesMaker::
	ChangesMaker(vector<FileEvent> &parentArray):
		parentArray(parentArray)
{};

DidChangeWatchedFilesParams::ChangesMaker::~ChangesMaker(){};


void DidChangeWatchedFilesParams::ChangesMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// FileEvent[]
	extraSetter =
	{
		// String
		nullopt,

		// Number
		nullopt,

		// Boolean
		nullopt,

		// Null
		nullopt,

		// Array
		nullopt,

		// Object
		[this, handler]()
		{
			auto& obj = parentArray.emplace_back();

			handler->pushInitializer();
			obj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}

}
