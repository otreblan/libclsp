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

#include <libclsp/types/selectionRange.hpp>

namespace libclsp
{

using namespace std;

const String SelectionRangeClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

SelectionRangeClientCapabilities::
	SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

SelectionRangeClientCapabilities::SelectionRangeClientCapabilities():
	dynamicRegistration()
{};

SelectionRangeClientCapabilities::~SelectionRangeClientCapabilities(){};


SelectionRangeRegistrationOptions::
	SelectionRangeRegistrationOptions(optional<ProgressToken> workDoneProgress,
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id):
			SelectionRangeOptions(workDoneProgress),
			TextDocumentRegistrationOptions(documentSelector),
			StaticRegistrationOptions(id)
{};

SelectionRangeRegistrationOptions::SelectionRangeRegistrationOptions():
	SelectionRangeOptions(),
	TextDocumentRegistrationOptions(),
	StaticRegistrationOptions()
{};

SelectionRangeRegistrationOptions::~SelectionRangeRegistrationOptions(){};


const String SelectionRangeParams::textDocumentKey = "textDocument";
const String SelectionRangeParams::positionsKey    = "positions";

SelectionRangeParams::SelectionRangeParams(
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument,
	vector<Position> positions):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument),
		positions(positions)
{};

SelectionRangeParams::SelectionRangeParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument(),
	positions()
{};

SelectionRangeParams::~SelectionRangeParams(){};


const String SelectionRange::rangeKey  = "range";
const String SelectionRange::parentKey = "parent";

SelectionRange::SelectionRange(Range range,
	optional<reference_wrapper<SelectionRange>> parent):
		range(range),
		parent(parent)
{};

SelectionRange::SelectionRange():
	range(),
	parent()
{};

SelectionRange::~SelectionRange(){};

}
