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
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/textDocumentSync.hpp>

namespace clsp
{

using namespace std;

/// The document change notification is sent from the client to
/// the server to signal changes to a text document.
///
/// syncKind: TextDocumentSyncKind
///
struct TextDocumentChangeRegistrationOptions:
	public TextDocumentRegistrationOptions
{
	const static String syncKindKey;

	/// How documents are synced to the server. See TextDocumentSyncKind.Full
	/// and TextDocumentSyncKind.Incremental.
	TextDocumentSyncKind syncKind;


	TextDocumentChangeRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		TextDocumentSyncKind syncKind);

	TextDocumentChangeRegistrationOptions();

	virtual ~TextDocumentChangeRegistrationOptions();
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/// An event describing a change to a text document. If range and rangeLength
/// are omitted the new text is considered to be the full content
/// of the document.
///
/// range?: Range
///
/// rangeLength?: number
///
/// text: String
///
struct TextDocumentContentChangeEvent
{

	const static String rangeKey;

	/// The range of the document that changed.
	optional<Range> range;


	const static String rangeLengthKey;

	/// The optional length of the range that got replaced.
	///
	/// @deprecated use range instead.
	[[deprecated("Use range instead")]]
	optional<Number> rangeLength;


	const static String textKey;

	/// The new text for the provided range.
	/// If no range is provided then this is the whole document.
	String text;


	TextDocumentContentChangeEvent(optional<Range> range, String text);

	TextDocumentContentChangeEvent();

	virtual ~TextDocumentContentChangeEvent();
};

#pragma GCC diagnostic pop

/// DidChangeTextDocument params
///
/// textDocument: VersionedTextDocumentIdentifier
///
/// contentChanges: TextDocumentContentChangeEvent[]
///
struct DidChangeTextDocumentParams
{

	const static String textDocumentKey;

	/// The document that did change. The version number points
	/// to the version after all provided content changes have
	/// been applied.
	VersionedTextDocumentIdentifier textDocument;


	const static String contentChangesKey;

	/// The actual content changes. The content changes describe single state
	/// changes to the document. So if there are two content changes c1 (at
	/// array index 0) and c2 (at array index 1) for a document in state S then
	/// c1 moves the document from S to S' and c2 from S' to S''. So c1 is
	/// computed on the state S and c2 is computed on the state S'.
	vector<TextDocumentContentChangeEvent> contentChanges;


	DidChangeTextDocumentParams(VersionedTextDocumentIdentifier textDocument,
		vector<TextDocumentContentChangeEvent> contentChanges);

	DidChangeTextDocumentParams();

	virtual ~DidChangeTextDocumentParams();
};

}

