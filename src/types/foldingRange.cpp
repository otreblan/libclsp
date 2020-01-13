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

namespace libclsp
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


FoldingRangeKind::FoldingRangeKind(String kind)
{
	auto newKind = kindMap.right.find(kind);

	// If the kind is in the enum
	if(newKind != kindMap.right.end())
	{
		this->kind = newKind->second;
	}
	else
	{
		this->kind = kind;
	}
}

FoldingRangeKind::FoldingRangeKind(_FoldingRangeKind kind):
	kind(kind)
{};

FoldingRangeKind::~FoldingRangeKind(){};

const boost::bimap<FoldingRangeKind::_FoldingRangeKind, String>
	FoldingRangeKind::kindMap =
	boost::assign::list_of<boost::bimap<_FoldingRangeKind, String>::relation>
		(_FoldingRangeKind::Comment, "comment")
		(_FoldingRangeKind::Imports, "imports")
		(_FoldingRangeKind::Region, "region");

FoldingRangeKind::operator String()
{
	String ret;

	visit(overload(
		[&ret](_FoldingRangeKind kind)
		{
			ret = kindMap.left.at(kind);
		},
		[&ret](String kind)
		{
			ret = kind;
		}
	), kind);

	return ret;
}

const FoldingRangeKind FoldingRangeKind::Comment = _FoldingRangeKind::Comment;
const FoldingRangeKind FoldingRangeKind::Imports = _FoldingRangeKind::Imports;
const FoldingRangeKind FoldingRangeKind::Region  = _FoldingRangeKind::Region;


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
