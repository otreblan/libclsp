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

#include <libclsp/types/documentHighlight.hpp>

namespace clsp
{

using namespace std;

const String DocumentHighlightClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentHighlightClientCapabilities::
	DocumentHighlightClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

DocumentHighlightClientCapabilities::DocumentHighlightClientCapabilities(){};
DocumentHighlightClientCapabilities::~DocumentHighlightClientCapabilities(){};

void DocumentHighlightClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}

DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentHighlightOptions(workDoneProgress)
{};

DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions(){};
DocumentHighlightRegistrationOptions::~DocumentHighlightRegistrationOptions(){};


DocumentHighlightParams::DocumentHighlightParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

DocumentHighlightParams::DocumentHighlightParams(){};
DocumentHighlightParams::~DocumentHighlightParams(){};

void DocumentHighlightParams::fillInitializer(ObjectInitializer& initializer)
{
	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);
}


const String DocumentHighlight::rangeKey = "range";
const String DocumentHighlight::kindKey  = "kind";

DocumentHighlight::DocumentHighlight(Range range,
	optional<DocumentHighlightKind> kind):
		range(range),
		kind(kind)
{};

DocumentHighlight::DocumentHighlight(){};
DocumentHighlight::~DocumentHighlight(){};

}
