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

DocumentSymbolClientCapabilities::DocumentSymbolClientCapabilities(){};
DocumentSymbolClientCapabilities::~DocumentSymbolClientCapabilities(){};

void DocumentSymbolClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

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

	// symbolKind?:
	setterMap.emplace(
		symbolKindKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			[this, handler]()
			{
				symbolKind.emplace();

				handler->pushInitializer();
				symbolKind->fillInitializer(handler->objectStack.top());
			},
		}
	);

	// hierarchicalDocumentSymbolSupport?:
	setterMap.emplace(
		hierarchicalDocumentSymbolSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				hierarchicalDocumentSymbolSupport = b;
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

const String DocumentSymbolClientCapabilities::SymbolKind::
	valueSetKey = "valueSet";

DocumentSymbolClientCapabilities::SymbolKind::
	SymbolKind(optional<vector<clsp::SymbolKind>> valueSet):
		valueSet(valueSet)
{};

DocumentSymbolClientCapabilities::SymbolKind::SymbolKind(){};
DocumentSymbolClientCapabilities::SymbolKind::~SymbolKind(){};

void DocumentSymbolClientCapabilities::SymbolKind::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// valueSet?:
	setterMap.emplace(
		valueSetKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			[this, handler]()
			{
				valueSet.emplace();

				handler->pushInitializer();

				auto* maker = new ValueSetMaker(valueSet.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}


DocumentSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	ValueSetMaker(vector<clsp::SymbolKind> &parentArray):
		parentArray(parentArray)
{};

DocumentSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	~ValueSetMaker()
{};

void DocumentSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// SymbolKind[]
	extraSetter =
	{
		// String
		nullopt,

		// Number
		[this](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				parentArray.emplace_back((clsp::SymbolKind)i);
			}

			// Nothing is added by default

		},

		// Boolean
		nullopt,

		// Null
		nullopt,

		// Array
		nullopt,

		// Object
		nullopt
	};

	// This
	initializer.object = this;
}

DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress):
		TextDocumentRegistrationOptions(documentSelector),
		DocumentSymbolOptions(workDoneProgress)
{};

DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions(){};
DocumentSymbolRegistrationOptions::~DocumentSymbolRegistrationOptions(){};


const String DocumentSymbolParams::textDocumentKey = "textDocument";

DocumentSymbolParams::DocumentSymbolParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

DocumentSymbolParams::DocumentSymbolParams(){};
DocumentSymbolParams::~DocumentSymbolParams(){};

void DocumentSymbolParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);


	// Value setters

	// textDocument:
	setterMap.emplace(
		textDocumentKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				textDocument.fillInitializer(handler->objectStack.top());

				neededMap[textDocumentKey] = true;
			}
		}
	);


	// Needed members
	neededMap.emplace(textDocumentKey, 0);

	// This
	initializer.object = this;
}

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

DocumentSymbol::DocumentSymbol(){};
DocumentSymbol::~DocumentSymbol(){};


const String SymbolInformation::nameKey          = "name";
const String SymbolInformation::kindKey          = "kind";
const String SymbolInformation::deprecatedKey    = "deprecated";
const String SymbolInformation::locationKey      = "location";
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

SymbolInformation::SymbolInformation(){};
SymbolInformation::~SymbolInformation(){};

}
