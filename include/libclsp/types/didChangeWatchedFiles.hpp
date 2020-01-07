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

#include <libclsp/types/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// DidChangeWatchedFiles notification capabilities
///
/// dynamicRegistration?: Boolean
///
struct DidChangeWatchedFilesClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Did change watched files notification supports dynamic registration.
	/// Please note that the current protocol doesn't support static
	/// configuration for file changes from the server side.
	optional<Boolean> dynamicRegistration;


	DidChangeWatchedFilesClientCapabilities(optional<Boolean> dynamicRegistration);

	DidChangeWatchedFilesClientCapabilities();

	virtual ~DidChangeWatchedFilesClientCapabilities();
};

namespace WatchKind
{
	/// Interested in create events.
	[[maybe_unused]] const Number Create = 1;

	/// Interested in change events
	[[maybe_unused]] const Number Change = 2;

	/// Interested in delete events
	[[maybe_unused]] const Number Delete = 4;
};

/// Watcher of file changes
///
/// globPattern: String
///
/// kind?: Number
///
struct FileSystemWatcher
{
	const static String globPatternKey;

	/// The  glob pattern to watch.
	///
	/// Glob patterns can have the following syntax:
	/// - `*` to match one or more characters in a path segment
	/// - `?` to match on one character in a path segment
	/// - `**` to match any number of path segments, including none
	/// - `{}` to group conditions
	/// - `[]` to declare a range of characters to match in a path segment
	/// - `[!...]` to negate a range of characters to match in a path segment
	String globPattern;


	const static String kindKey;

	/// The kind of events of interest. If omitted it defaults
	/// to WatchKind::Create | WatchKind::Change | WatchKind::Delete
	/// which is 7.
	optional<Number> key;


	FileSystemWatcher(String globPattern, optional<Number> key);

	FileSystemWatcher();

	virtual ~FileSystemWatcher();

};

/// Describe options to be used when registering for file system change events.
///
/// watchers: FileSystemWatcher[]
///
struct DidChangeWatchedFilesRegistrationOptions
{

	const static String watchersKey;

	/// The watchers to register.
	vector<FileSystemWatcher> watchers;

	DidChangeWatchedFilesRegistrationOptions(vector<FileSystemWatcher> watchers);

	DidChangeWatchedFilesRegistrationOptions();

	virtual ~DidChangeWatchedFilesRegistrationOptions();
};

/// The file event type.
enum class FileChangeType
{
	/// The file got created.
	Created = 1,

	/// The file got changed.
	Changed = 2,

	/// The file got deleted.
	Deleted = 3
};

/// An event describing a file change.
///
/// uri: DocumentUri
///
/// type: Number
///
struct FileEvent
{

	const static String uriKey;

	/// The file's URI.
	DocumentUri uri;


	const static String typeKey;

	/// The change type.
	FileChangeType type;


	FileEvent(DocumentUri uri, FileChangeType type);

	FileEvent();

	virtual ~FileEvent();
};

/// DidChangeWatchedFiles params
///
/// changes: FileEvent[]
///
struct DidChangeWatchedFilesParams
{
	const static String changesKey;

	/// The actual file events.
	vector<FileEvent> changes;


	DidChangeWatchedFilesParams(vector<FileEvent> changes);

	DidChangeWatchedFilesParams();

	virtual ~DidChangeWatchedFilesParams();
};

}
