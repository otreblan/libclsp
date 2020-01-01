// A C++17 library for language servers.
// Copyright © 2019 otreblan
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

#include <variant>
#include <optional>

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// Options to create a file.
///
/// overwrite?: Boolean
///
/// ignoreIfExists?: Boolean
///
struct CreateFileOptions
{
	const static String overwriteKey;

	/// Overwrite existing file. Overwrite wins over `ignoreIfExists`
	optional<Boolean> overwrite;


	const static String ignoreIfExistsKey;

	/// Ignore if exists.
	optional<Boolean> ignoreIfExists;


	CreateFileOptions(optional<Boolean> overwrite, optional<Boolean> ignoreIfExists);

	virtual ~CreateFileOptions();
};

/// Create file operation
///
/// kind: 'create'
///
/// uri: DocumentUri
///
/// options?: CreateFileOptions
///
struct CreateFile
{

	/// A create
	const static pair<String, String> kind;


	const static String uriKey;

	/// The resource to create.
	DocumentUri uri;


	const static String optionsKey;

	/// Additional options
	optional<CreateFileOptions> options;


	CreateFile(DocumentUri uri, optional<CreateFileOptions> options);

	virtual ~CreateFile();
};

/// Rename file options
///
/// overwrite?: Boolean
///
/// ignoreIfExists?: Boolean
///
struct RenameFileOptions
{
	const static String overwriteKey;

	/// Overwrite existing file. Overwrite wins over `ignoreIfExists`
	optional<Boolean> overwrite;


	const static String ignoreIfExistsKey;

	/// Ignore if exists.
	optional<Boolean> ignoreIfExists;


	RenameFileOptions(optional<Boolean> overwrite, optional<Boolean> ignoreIfExists);

	virtual ~RenameFileOptions();
};

/// Rename file operation
///
/// kind: 'rename'
///
/// oldUri: DocumentUri
///
/// newUri: DocumentUri
///
/// options?: RenameFileOptions
///
struct RenameFile
{
	/// A rename
	const static pair<String, String> kind;


	const static String oldUriKey;

	/// The old (existing) location.
	DocumentUri oldUri;


	const static String newUriKey;

	/// The new location.
	DocumentUri newUri;


	const static String optionsKey;

	/// Rename options.
	optional<RenameFileOptions> options;


	RenameFile(DocumentUri oldUri,
		DocumentUri newUri,
		optional<RenameFileOptions> options);

	virtual ~RenameFile();
};

/// Delete file options
///
/// recursive?: Boolean
///
/// ignoreIfNotExists?: Boolean
///
struct DeleteFileOptions
{

	const static String recursiveKey;

	/// Delete the content recursively if a folder is denoted.
	optional<Boolean> recursive;


	const static String ignoreIfNotExistsKey;

	/// Ignore the operation if the file doesn't exist.
	optional<Boolean> ignoreIfNotExists;


	DeleteFileOptions(optional<Boolean> recursive,
		optional<Boolean> ignoreIfNotExists);

	virtual ~DeleteFileOptions();
};

/// Delete file operation
///
/// kind: 'delete'
///
/// uri: DocumentUri
///
/// options?: DeleteFileOptions
///
struct DeleteFile
{

	/// A delete
	const static pair<String, String> kind;


	const static String uriKey;

	/// The file to delete.
	DocumentUri uri;


	const static String optionsKey;

	/// Delete options.
	optional<DeleteFileOptions> options;


	DeleteFile(DocumentUri uri, optional<DeleteFileOptions> options);

	virtual ~DeleteFile();
};

}
