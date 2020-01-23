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


FoldingRangeClientCapabilities::FoldingRangeClientCapabilities():
	dynamicRegistration(),
	rangeLimit(),
	lineFoldingOnly()
{};

FoldingRangeClientCapabilities::~FoldingRangeClientCapabilities(){};


FoldingRangeRegistrationOptions::
	FoldingRangeRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<String> id):
			TextDocumentRegistrationOptions(documentSelector),
			FoldingRangeOptions(workDoneProgress),
			StaticRegistrationOptions(id)
{};

FoldingRangeRegistrationOptions::FoldingRangeRegistrationOptions():
	TextDocumentRegistrationOptions(),
	FoldingRangeOptions(),
	StaticRegistrationOptions()
{};

FoldingRangeRegistrationOptions::~FoldingRangeRegistrationOptions(){};


FoldingRangeParams::FoldingRangeParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

FoldingRangeParams::FoldingRangeParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument()
{};

FoldingRangeParams::~FoldingRangeParams(){};


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

FoldingRange::FoldingRange():
	startLine(),
	startCharacter(),
	endLine(),
	endCharacter(),
	kind()
{};

FoldingRange::~FoldingRange(){};

}
