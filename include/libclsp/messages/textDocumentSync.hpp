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

#include <libclsp/messages/didSaveTextDocument.hpp>

namespace libclsp
{

using namespace std;

/// Defines how the host (editor) should sync document changes to
/// the language server.
enum class TextDocumentSyncKind
{

	/// Documents should not be synced at all.
	None = 0,

	/// Documents are synced by always sending the full content
	/// of the document.
	Full = 1,

	/// Documents are synced by sending the full content on open.
	/// After that only incremental updates to the document are
	/// send.
	Incremental = 2
};

/// TextDocumentSync options
///
/// openClose?: Boolean
///
/// change?: TextDocumentSyncKind
///
/// willSave?: Boolean
///
/// willSaveWaitUntil?: Boolean
///
/// save?: SaveOptions
///
struct TextDocumentSyncOptions
{

	const static String openCloseKey;

	/// Open and close notifications are sent to the server. If omitted
	/// open close notification should not be sent.
	optional<Boolean> openClose;


	const static String changeKey;

	/// Change notifications are sent to the server. See TextDocumentSyncKind.None,
	/// TextDocumentSyncKind.Full and TextDocumentSyncKind.Incremental. If omitted
	/// it defaults to TextDocumentSyncKind.None.
	optional<TextDocumentSyncKind> change;


	const static String willSaveKey;

	/// If present will save notifications are sent to the server.
	/// If omitted the notification should not be sent.
	optional<Boolean> willSave;


	const static String willSaveWaitUntilKey;

	/// If present will save wait until requests are sent to the server.
	/// If omitted the request should not be sent.
	optional<Boolean> willSaveWaitUntil;


	const static String saveKey;

	/// If present save notifications are sent to the server.
	/// If omitted the notification should not be sent.
	optional<SaveOptions> save;


	TextDocumentSyncOptions(optional<Boolean> openClose,
		optional<TextDocumentSyncKind> change,
		optional<Boolean> willSave,
		optional<Boolean> willSaveWaitUntil,
		optional<SaveOptions> save);

	TextDocumentSyncOptions();

	virtual ~TextDocumentSyncOptions();
};

/// Client capability for syncing textDocument's
///
/// dynamicRegistration?: Boolean;
///
/// willSave?: Boolean;
///
/// willSaveWaitUntil?: Boolean;
///
/// didSave?: Boolean;
///
struct TextDocumentSyncClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether text document synchronization supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	const static String willSaveKey;

	/// The client supports sending will save notifications.
	optional<Boolean> willSave;


	const static String willSaveWaitUntilKey;

	/// The client supports sending a will save request and
	/// waits for a response providing text edits which will
	/// be applied to the document before it is saved.
	optional<Boolean> willSaveWaitUntil;


	const static String didSaveKey;

	/// The client supports did save notifications.
	optional<Boolean> didSave;


	TextDocumentSyncClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> willSave,
		optional<Boolean> willSaveWaitUntil,
		optional<Boolean> didSave);

	TextDocumentSyncClientCapabilities();

	virtual ~TextDocumentSyncClientCapabilities();
};

}
