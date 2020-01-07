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

#include <libclsp/messages/textDocumentSync.hpp>

namespace libclsp
{

using namespace std;

const String TextDocumentSyncOptions::openCloseKey         = "openClose";
const String TextDocumentSyncOptions::changeKey            = "change";
const String TextDocumentSyncOptions::willSaveKey          = "willSave";
const String TextDocumentSyncOptions::willSaveWaitUntilKey = "willSaveWaitUntil";
const String TextDocumentSyncOptions::saveKey              = "save";


TextDocumentSyncOptions::TextDocumentSyncOptions(optional<Boolean> openClose,
	optional<TextDocumentSyncKind> change,
	optional<Boolean> willSave,
	optional<Boolean> willSaveWaitUntil,
	optional<SaveOptions> save):
		openClose(openClose),
		change(change),
		willSave(willSave),
		willSaveWaitUntil(willSaveWaitUntil),
		save(save)
{};


TextDocumentSyncOptions::TextDocumentSyncOptions():
	openClose(),
	change(),
	willSave(),
	willSaveWaitUntil(),
	save()
{};

TextDocumentSyncOptions::~TextDocumentSyncOptions(){};


const String TextDocumentSyncClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String TextDocumentSyncClientCapabilities::
	willSaveKey            = "willSave";

const String TextDocumentSyncClientCapabilities::
	willSaveWaitUntilKey   = "willSaveWaitUntil";

const String TextDocumentSyncClientCapabilities::
	didSaveKey             = "didSave";


TextDocumentSyncClientCapabilities::
	TextDocumentSyncClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> willSave,
		optional<Boolean> willSaveWaitUntil,
		optional<Boolean> didSave):
			dynamicRegistration(dynamicRegistration),
			willSave(willSave),
			willSaveWaitUntil(willSaveWaitUntil),
			didSave(didSave)
{};

TextDocumentSyncClientCapabilities::TextDocumentSyncClientCapabilities():
	dynamicRegistration(),
	willSave(),
	willSaveWaitUntil(),
	didSave()
{};

TextDocumentSyncClientCapabilities::~TextDocumentSyncClientCapabilities(){};

}
