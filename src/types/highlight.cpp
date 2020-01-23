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

#include <libclsp/types/highlight.hpp>

namespace clsp
{

using namespace std;

const String DocumentHighlightClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentHighlightClientCapabilities::
	DocumentHighlightClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

DocumentHighlightClientCapabilities::DocumentHighlightClientCapabilities():
	dynamicRegistration()
{};

DocumentHighlightClientCapabilities::~DocumentHighlightClientCapabilities(){};


DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentHighlightOptions(workDoneProgress)
{};

DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions():
	TextDocumentRegistrationOptions(),
	DocumentHighlightOptions()
{};

DocumentHighlightRegistrationOptions::~DocumentHighlightRegistrationOptions(){};


DocumentHighlightParams::DocumentHighlightParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

DocumentHighlightParams::DocumentHighlightParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams()
{};

DocumentHighlightParams::~DocumentHighlightParams(){};


const String DocumentHighlight::rangeKey = "range";
const String DocumentHighlight::kindKey  = "kind";

DocumentHighlight::DocumentHighlight(Range range,
	optional<DocumentHighlightKind> kind):
		range(range),
		kind(kind)
{};

DocumentHighlight::DocumentHighlight():
	range(),
	kind()
{};

DocumentHighlight::~DocumentHighlight(){};

}
