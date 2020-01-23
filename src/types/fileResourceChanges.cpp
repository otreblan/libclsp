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

#include <libclsp/types/fileResourceChanges.hpp>

namespace clsp
{

using namespace std;

const String CreateFileOptions::overwriteKey      = "overwrite";
const String CreateFileOptions::ignoreIfExistsKey = "ignoreIfExists";

CreateFileOptions::CreateFileOptions(optional<Boolean> overwrite,
	optional<Boolean> ignoreIfExists):
		overwrite(overwrite),
		ignoreIfExists(ignoreIfExists)
{};

CreateFileOptions::CreateFileOptions():
	overwrite(),
	ignoreIfExists()
{};

CreateFileOptions::~CreateFileOptions(){};


const pair<String, String> CreateFile::kind = {"kind", "create"};

const String CreateFile::uriKey     = "uri";
const String CreateFile::optionsKey = "options";

CreateFile::CreateFile(DocumentUri uri, optional<CreateFileOptions> options):
	uri(uri),
	options(options)
{};

CreateFile::CreateFile():
	uri(),
	options()
{};

CreateFile::~CreateFile(){};


const String RenameFileOptions::overwriteKey      = "overwrite";
const String RenameFileOptions::ignoreIfExistsKey = "ignoreIfExists";

RenameFileOptions::RenameFileOptions(optional<Boolean> overwrite,
	optional<Boolean> ignoreIfExists):
		overwrite(overwrite),
		ignoreIfExists(ignoreIfExists)
{};

RenameFileOptions::RenameFileOptions():
		overwrite(),
		ignoreIfExists()
{};

RenameFileOptions::~RenameFileOptions(){};


const pair<String, String> RenameFile::kind = {"kind", "rename"};

const String RenameFile::oldUriKey  = "oldUri";
const String RenameFile::newUriKey  = "newUri";
const String RenameFile::optionsKey = "options";

RenameFile::RenameFile(DocumentUri oldUri,
	DocumentUri newUri,
	optional<RenameFileOptions> options):
		oldUri(oldUri),
		newUri(newUri),
		options(options)
{};

RenameFile::RenameFile():
	oldUri(),
	newUri(),
	options()
{};

RenameFile::~RenameFile(){};


const String DeleteFileOptions::recursiveKey         = "recursive";
const String DeleteFileOptions::ignoreIfNotExistsKey = "ignoreIfNotExists";

DeleteFileOptions::DeleteFileOptions(optional<Boolean> recursive,
	optional<Boolean> ignoreIfNotExists):
		recursive(recursive),
		ignoreIfNotExists(ignoreIfNotExists)
{};

DeleteFileOptions::DeleteFileOptions():
	recursive(),
	ignoreIfNotExists()
{};

DeleteFileOptions::~DeleteFileOptions(){};


const pair<String, String> DeleteFile::kind = {"kind", "delete"};

const String DeleteFile::uriKey     = "uri";
const String DeleteFile::optionsKey = "options";

DeleteFile::DeleteFile(DocumentUri uri, optional<DeleteFileOptions> options):
	uri(uri),
	options(options)
{};

DeleteFile::DeleteFile():
	uri(),
	options()
{};

DeleteFile::~DeleteFile(){};

}
