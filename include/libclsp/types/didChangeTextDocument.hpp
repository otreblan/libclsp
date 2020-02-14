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
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String syncKindKey;

public:
	/// How documents are synced to the server. See TextDocumentSyncKind.Full
	/// and TextDocumentSyncKind.Incremental.
	TextDocumentSyncKind syncKind;

	// No parsing

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
/// rangeLength?: Number
///
/// text: String
///
struct TextDocumentContentChangeEvent: public ObjectT
{
private:
	const static String rangeKey;
	const static String rangeLengthKey;
	const static String textKey;

public:
	/// The range of the document that changed.
	optional<Range> range;

	/// The optional length of the range that got replaced.
	///
	/// @deprecated use range instead.
	[[deprecated("Use range instead")]]
	optional<Number> rangeLength;

	/// The new text for the provided range.
	/// If no range is provided then this is the whole document.
	String text;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	TextDocumentContentChangeEvent(Range range, String text);

	TextDocumentContentChangeEvent(String text);

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
struct DidChangeTextDocumentParams: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String contentChangesKey;

	struct ContentChangesMaker: public ObjectT
	{

		/// The array to make
		vector<TextDocumentContentChangeEvent> &parentArray;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		ContentChangesMaker(vector<TextDocumentContentChangeEvent> &parentArray);

		virtual ~ContentChangesMaker();
	};
public:
	/// The document that did change. The version number points
	/// to the version after all provided content changes have
	/// been applied.
	VersionedTextDocumentIdentifier textDocument;

	/// The actual content changes. The content changes describe single state
	/// changes to the document. So if there are two content changes c1 (at
	/// array index 0) and c2 (at array index 1) for a document in state S then
	/// c1 moves the document from S to S' and c2 from S' to S''. So c1 is
	/// computed on the state S and c2 is computed on the state S'.
	vector<TextDocumentContentChangeEvent> contentChanges;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	DidChangeTextDocumentParams(VersionedTextDocumentIdentifier textDocument,
		vector<TextDocumentContentChangeEvent> contentChanges);

	DidChangeTextDocumentParams();

	virtual ~DidChangeTextDocumentParams();
};

}

