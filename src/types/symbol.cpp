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

#include <libclsp/types/symbol.hpp>

namespace clsp
{

using namespace std;

const String DocumentSymbolClientCapabilities::
	dynamicRegistrationKey               = "dynamicRegistration";

const String DocumentSymbolClientCapabilities::
	symbolKindKey                        = "symbolKind";

const String DocumentSymbolClientCapabilities::
	hierarchicalDocumentSymbolSupportKey = "hierarchicalDocumentSymbolSupport";

DocumentSymbolClientCapabilities::
	DocumentSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind,
		optional<Boolean> hierarchicalDocumentSymbolSupport):
			dynamicRegistration(dynamicRegistration),
			symbolKind(symbolKind),
			hierarchicalDocumentSymbolSupport(hierarchicalDocumentSymbolSupport)
{};

DocumentSymbolClientCapabilities::DocumentSymbolClientCapabilities():
	dynamicRegistration(),
	symbolKind(),
	hierarchicalDocumentSymbolSupport()
{};

DocumentSymbolClientCapabilities::~DocumentSymbolClientCapabilities(){};


const String DocumentSymbolClientCapabilities::SymbolKind::
	valueSetKey = "valueSet";

DocumentSymbolClientCapabilities::SymbolKind::
	SymbolKind(optional<vector<clsp::SymbolKind>> valueSet):
		valueSet(valueSet)
{};

DocumentSymbolClientCapabilities::SymbolKind::SymbolKind():
	valueSet()
{};

DocumentSymbolClientCapabilities::SymbolKind::~SymbolKind(){};


DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentSymbolOptions(workDoneProgress)
{};

DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions():
	TextDocumentRegistrationOptions(),
	DocumentSymbolOptions()
{};

DocumentSymbolRegistrationOptions::~DocumentSymbolRegistrationOptions(){};


const String DocumentSymbolParams::textDocumentKey = "textDocument";

DocumentSymbolParams::DocumentSymbolParams(TextDocumentIdentifier _textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		TextDocumentPositionParams(_textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

DocumentSymbolParams::DocumentSymbolParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument()
{};

DocumentSymbolParams::~DocumentSymbolParams(){};


const String DocumentSymbol::nameKey           = "name";
const String DocumentSymbol::detailKey         = "detail";
const String DocumentSymbol::kindKey           = "kind";
const String DocumentSymbol::deprecatedKey     = "deprecated";
const String DocumentSymbol::rangeKey          = "range";
const String DocumentSymbol::selectionRangeKey = "selectionRange";
const String DocumentSymbol::childrenKey       = "children";

DocumentSymbol::DocumentSymbol(String name,
	optional<String> detail,
	SymbolKind kind,
	optional<Boolean> deprecated,
	Range range,
	Range selectionRange,
	optional<vector<DocumentSymbol>> children):
		name(name),
		detail(detail),
		kind(kind),
		deprecated(deprecated),
		range(range),
		selectionRange(selectionRange),
		children(children)
{};

DocumentSymbol::DocumentSymbol():
	name(),
	detail(),
	kind(),
	deprecated(),
	range(),
	selectionRange(),
	children()
{};

DocumentSymbol::~DocumentSymbol(){};


const String SymbolInformation::nameKey          = "name";
const String SymbolInformation::kindKey          = "kind";
const String SymbolInformation::deprecatedKey    = "deprecated";
const String SymbolInformation::localtionKey     = "location";
const String SymbolInformation::containerNameKey = "containerName";

SymbolInformation::SymbolInformation(String name,
	SymbolKind kind,
	optional<Boolean> deprecated,
	Location location,
	optional<String> containerName):
		name(name),
		kind(kind),
		deprecated(deprecated),
		location(location),
		containerName(containerName)
{};

SymbolInformation::SymbolInformation():
	name(),
	kind(),
	deprecated(),
	location(),
	containerName()
{};

SymbolInformation::~SymbolInformation(){};

}
