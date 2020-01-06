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

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// An item to transfer a text document from the client to the server.
///
/// uri: DocumentUri
///
/// languageId: String
///
/// version: Number
///
/// text: String
///
struct TextDocumentItem
{

	const static String uriKey;

	/// The text document's URI.
	DocumentUri uri;


	const static String languageIdKey;

	/// The text document's language identifier.
	String languageId;


	const static String versionKey;

	/// The version number of this document (it will increase after each
	/// change, including undo/redo).
	Number version;


	const static String textKey;

	/// The content of the opened text document.
	String text;


	TextDocumentItem(DocumentUri uri,
		String languageId,
		Number version,
		String text);

	TextDocumentItem();

	virtual ~TextDocumentItem();
};

}
