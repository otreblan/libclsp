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

#include <libclsp/messages/range.hpp>
#include <libclsp/messages/textDocumentIdentifier.hpp>

namespace libclsp
{

using namespace std;

/// A textual edit applicable to a text document.
///
/// range: Range
///
/// newText: String
///
struct TextEdit
{

	const static String rangeKey;

	/// The range of the text document to be manipulated. To insert
	/// text into a document create a range where start == end.
	Range range;


	const static String newTextKey;

	/// The string to be inserted. For delete operations use an
	/// empty string.
	String newText;

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
struct TextDocumentEdit
{
	const static String textDocumentKey;

	/// The text document to change.
	VersionedTextDocumentIdentifier textDocument;


	const static String editsKey;

	/// The edits to be applied.
	vector<TextEdit> edits;


	TextDocumentEdit(VersionedTextDocumentIdentifier textDocument,
		vector<TextEdit> edits);

	TextDocumentEdit();

	virtual ~TextDocumentEdit();

};

}
