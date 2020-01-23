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

#include <libclsp/types/documentFormatting.hpp>

namespace clsp
{

using namespace std;

const String DocumentFormattingClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentFormattingClientCapabilities::
	DocumentFormattingClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

DocumentFormattingClientCapabilities::DocumentFormattingClientCapabilities():
	dynamicRegistration()
{};

DocumentFormattingClientCapabilities::~DocumentFormattingClientCapabilities(){};


DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentFormattingOptions(workDoneProgress)
{};

DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions():
	TextDocumentRegistrationOptions(),
	DocumentFormattingOptions()
{};

DocumentFormattingRegistrationOptions::~DocumentFormattingRegistrationOptions(){};


const String FormattingOptions::
	tabSizeKey                = "tabSize";

const String FormattingOptions::
	insertSpacesKey           = "insertSpaces";

const String FormattingOptions::
	trimTrailingWhitespaceKey = "trimTrailingWhitespace";

const String FormattingOptions::
	insertFinalNewlineKey     = "insertFinalNewline";

const String FormattingOptions::
	trimFinalNewlinesKey      = "trimFinalNewlines";

FormattingOptions::FormattingOptions(Number tabSize,
	Boolean insertSpaces,
	optional<Boolean> trimTrailingWhitespace,
	optional<Boolean> insertFinalNewline,
	optional<Boolean> trimFinalNewlines,
	map<String, variant<Boolean, Number, String>> extras):
		tabSize(tabSize),
		insertSpaces(insertSpaces),
		trimTrailingWhitespace(trimTrailingWhitespace),
		insertFinalNewline(insertFinalNewline),
		trimFinalNewlines(trimFinalNewlines),
		extras(extras)
{};

FormattingOptions::FormattingOptions():
	tabSize(),
	insertSpaces(),
	trimTrailingWhitespace(),
	insertFinalNewline(),
	trimFinalNewlines(),
	extras()
{};

FormattingOptions::~FormattingOptions(){};


const String DocumentFormattingParams::textDocumentKey = "textDocument";
const String DocumentFormattingParams::optionsKey      = "options";

DocumentFormattingParams::DocumentFormattingParams(
	optional<ProgressToken> workDoneToken,
	TextDocumentIdentifier textDocument,
	FormattingOptions options):
		WorkDoneProgressParams(workDoneToken),
		textDocument(textDocument),
		options(options)
{};

DocumentFormattingParams::DocumentFormattingParams():
	WorkDoneProgressParams(),
	textDocument(),
	options()
{};

DocumentFormattingParams::~DocumentFormattingParams(){};


}
