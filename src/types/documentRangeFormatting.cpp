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

#include <libclsp/types/documentRangeFormatting.hpp>

namespace libclsp
{

using namespace std;

const String DocumentRangeFormattingClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentRangeFormattingClientCapabilities::
	DocumentRangeFormattingClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

DocumentRangeFormattingClientCapabilities::DocumentRangeFormattingClientCapabilities():
	dynamicRegistration()
{};

DocumentRangeFormattingClientCapabilities::~DocumentRangeFormattingClientCapabilities(){};


DocumentRangeFormattingRegistrationOptions::DocumentRangeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentRangeFormattingOptions(workDoneProgress)
{};

DocumentRangeFormattingRegistrationOptions::DocumentRangeFormattingRegistrationOptions():
	TextDocumentRegistrationOptions(),
	DocumentRangeFormattingOptions()
{};

DocumentRangeFormattingRegistrationOptions::~DocumentRangeFormattingRegistrationOptions(){};


const String DocumentRangeFormattingParams::textDocumentKey = "textDocument";
const String DocumentRangeFormattingParams::rangeKey        = "range";
const String DocumentRangeFormattingParams::optionsKey      = "options";

DocumentRangeFormattingParams::DocumentRangeFormattingParams(
	optional<ProgressToken> workDoneToken,
	TextDocumentIdentifier textDocument,
	Range range,
	FormattingOptions options):
		WorkDoneProgressParams(workDoneToken),
		textDocument(textDocument),
		range(range),
		options(options)
{};

DocumentRangeFormattingParams::DocumentRangeFormattingParams():
	WorkDoneProgressParams(),
	textDocument(),
	range(),
	options()
{};

DocumentRangeFormattingParams::~DocumentRangeFormattingParams(){};

}
