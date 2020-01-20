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

#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;

/// Text documents are identified using a URI.
///
/// uri: DocumentUri
///
struct TextDocumentIdentifier: public ObjectT
{
private:
	const static String uriKey;

public:

	/// The text document's URI.
	DocumentUri uri;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	TextDocumentIdentifier(DocumentUri uri);

	TextDocumentIdentifier();

	virtual ~TextDocumentIdentifier();
};

/// An identifier to denote a specific version of a text document.
///
/// version: Number | Null
///
struct VersionedTextDocumentIdentifier: public TextDocumentIdentifier
{
private:
	const static String versionKey;

public:

	/// The version number of this document. If a versioned text document identifier
	/// is sent from the server to the client and the file is not open in the editor
	/// (the server has not received an open notification before) the server can send
	/// `null` to indicate that the version is known and the content on disk is the
	/// master (as speced with document content ownership).
	///
	/// The version number of a document will increase after each change, including
	/// undo/redo. The number doesn't need to be consecutive.
	variant<Number, Null> version;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	VersionedTextDocumentIdentifier(DocumentUri uri, variant<Number, Null> version);

	VersionedTextDocumentIdentifier();

	virtual ~VersionedTextDocumentIdentifier();

};

}
