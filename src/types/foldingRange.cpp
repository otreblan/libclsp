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

#include <libclsp/types/foldingRange.hpp>

namespace clsp
{

using namespace std;

const String FoldingRangeClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String FoldingRangeClientCapabilities::
	rangeLimitKey          = "rangeLimit";

const String FoldingRangeClientCapabilities::
	lineFoldingOnlyKey     = "lineFoldingOnly";

FoldingRangeClientCapabilities::
	FoldingRangeClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Number> rangeLimit,
		optional<Boolean> lineFoldingOnly):
			dynamicRegistration(dynamicRegistration),
			rangeLimit(rangeLimit),
			lineFoldingOnly(lineFoldingOnly)
{};


FoldingRangeClientCapabilities::FoldingRangeClientCapabilities(){};
FoldingRangeClientCapabilities::~FoldingRangeClientCapabilities(){};

void FoldingRangeClientCapabilities::
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

	// rangeLimit?:
	setterMap.emplace(
		rangeLimitKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this](Number n)
			{
				rangeLimit = n;
			},

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// lineFoldingOnly?:
	setterMap.emplace(
		lineFoldingOnlyKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				lineFoldingOnly = b;
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


FoldingRangeRegistrationOptions::
	FoldingRangeRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<String> id):
			TextDocumentRegistrationOptions(documentSelector),
			FoldingRangeOptions(workDoneProgress),
			StaticRegistrationOptions(id)
{};

FoldingRangeRegistrationOptions::FoldingRangeRegistrationOptions(){};
FoldingRangeRegistrationOptions::~FoldingRangeRegistrationOptions(){};


const String FoldingRangeParams::textDocumentKey = "textDocument";

FoldingRangeParams::FoldingRangeParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

FoldingRangeParams::FoldingRangeParams(){};
FoldingRangeParams::~FoldingRangeParams(){};

void FoldingRangeParams::fillInitializer(ObjectInitializer& initializer)
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


FoldingRangeKind::FoldingRangeKind(String kind):
	kind(kind)
{};

FoldingRangeKind::~FoldingRangeKind(){};


const FoldingRangeKind FoldingRangeKind::Comment = "comment"s;
const FoldingRangeKind FoldingRangeKind::Imports = "imports"s;
const FoldingRangeKind FoldingRangeKind::Region  = "region"s;


const String FoldingRange::startLineKey      = "startLine";
const String FoldingRange::startCharacterKey = "startCharacter";
const String FoldingRange::endLineKey        = "endLine";
const String FoldingRange::endCharacterKey   = "endCharacter";
const String FoldingRange::kindKey           = "kind";

FoldingRange::FoldingRange(Number startLine,
	optional<Number> startCharacter,
	Number endLine,
	optional<Number> endCharacter,
	optional<FoldingRangeKind> kind):
		startLine(startLine),
		startCharacter(startCharacter),
		endLine(endLine),
		endCharacter(endCharacter),
		kind(kind)
{};

FoldingRange::FoldingRange(){};
FoldingRange::~FoldingRange(){};

}
