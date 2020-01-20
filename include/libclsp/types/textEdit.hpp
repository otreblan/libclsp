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

#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentIdentifier.hpp>

namespace libclsp
{

using namespace std;

/// A textual edit applicable to a text document.
///
/// range: Range
///
/// newText: String
///
struct TextEdit: public ObjectT
{
private:

	const static String rangeKey;
	const static String newTextKey;

public:

	/// The range of the text document to be manipulated. To insert
	/// text into a document create a range where start == end.
	Range range;

	/// The string to be inserted. For delete operations use an
	/// empty string.
	String newText;


	//====================   Parsing   ======================================//

	/// This fills the ObjectInitializer at the top of the handler stack
	virtual void fillInitializer(JsonHandler& handler);

	// Using default isValid()

	//=======================================================================//


	TextEdit(Range range, String newText);

	TextEdit();

	virtual ~TextEdit();
};

/// Describes textual changes on a single text document.
///
/// textDocument: VersionedTextDocumentIdentifier
///
/// edits: TextEdit[]
///
struct TextDocumentEdit: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String editsKey;

	struct EditsMaker: public ObjectT
	{
		// The object where the array is build
		TextDocumentEdit* parent;

		//====================   Parsing   ==================================//

		/// This fills the ObjectInitializer at the top of the handler stack
		virtual void fillInitializer(JsonHandler& handler);

		// Using default isValid()

		//===================================================================//
	};

public:
	/// The text document to change.
	VersionedTextDocumentIdentifier textDocument;

	/// The edits to be applied.
	vector<TextEdit> edits;


	//====================   Parsing   ======================================//

	/// This fills the ObjectInitializer at the top of the handler stack
	virtual void fillInitializer(JsonHandler& handler);

	// Using default isValid()

	//=======================================================================//


	TextDocumentEdit(VersionedTextDocumentIdentifier textDocument,
		vector<TextEdit> edits);

	TextDocumentEdit();

	virtual ~TextDocumentEdit();

};

}
