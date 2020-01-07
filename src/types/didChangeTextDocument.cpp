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

#include <libclsp/types/didChangeTextDocument.hpp>

namespace libclsp
{

using namespace std;

const String TextDocumentChangeRegistrationOptions::syncKindKey = "syncKind";

TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	TextDocumentSyncKind syncKind):
		TextDocumentRegistrationOptions(documentSelector),
		syncKind(syncKind)
{};

TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions():
	TextDocumentRegistrationOptions(),
	syncKind()
{};

TextDocumentChangeRegistrationOptions::
	~TextDocumentChangeRegistrationOptions()
{};


const String TextDocumentContentChangeEvent::rangeKey       = "range";
const String TextDocumentContentChangeEvent::rangeLengthKey = "rangeLength";
const String TextDocumentContentChangeEvent::textKey        = "text";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

TextDocumentContentChangeEvent::
	TextDocumentContentChangeEvent(optional<Range> range, String text):
		range(range),
		text(text)
{};

TextDocumentContentChangeEvent::TextDocumentContentChangeEvent():
	range(),
	text()
{};

TextDocumentContentChangeEvent::~TextDocumentContentChangeEvent(){};

#pragma GCC diagnostic pop

const String DidChangeTextDocumentParams::textDocumentKey   = "textDocument";
const String DidChangeTextDocumentParams::contentChangesKey = "contentChanges";

DidChangeTextDocumentParams::
	DidChangeTextDocumentParams(VersionedTextDocumentIdentifier textDocument,
		vector<TextDocumentContentChangeEvent> contentChanges):
			textDocument(textDocument),
			contentChanges(contentChanges)
{};

DidChangeTextDocumentParams::DidChangeTextDocumentParams():
	textDocument(),
	contentChanges()
{};

DidChangeTextDocumentParams::~DidChangeTextDocumentParams(){};

}
