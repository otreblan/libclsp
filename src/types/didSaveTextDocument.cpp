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

#include <libclsp/types/didSaveTextDocument.hpp>

namespace clsp
{

using namespace std;

const String SaveOptions::includeTextKey = "includeText";

SaveOptions::SaveOptions(optional<Boolean> includeText):
	includeText(includeText)
{};

SaveOptions::SaveOptions():
	includeText()
{};

SaveOptions::~SaveOptions(){};


const String TextDocumentSaveRegistrationOptions::includeTextKey = "includeText";

TextDocumentSaveRegistrationOptions::TextDocumentSaveRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<Boolean> includeText):
		TextDocumentRegistrationOptions(documentSelector),
		includeText(includeText)
{};

TextDocumentSaveRegistrationOptions::TextDocumentSaveRegistrationOptions():
	TextDocumentRegistrationOptions(),
	includeText()
{};

TextDocumentSaveRegistrationOptions::~TextDocumentSaveRegistrationOptions(){};


const String DidSaveTextDocumentParams::textDocumentKey = "textDocument";
const String DidSaveTextDocumentParams::textKey         = "text";

DidSaveTextDocumentParams::
	DidSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		optional<String> text):
			textDocument(textDocument),
			text(text)
{};

DidSaveTextDocumentParams::DidSaveTextDocumentParams():
	textDocument(),
	text()
{};

DidSaveTextDocumentParams::~DidSaveTextDocumentParams(){};

}
