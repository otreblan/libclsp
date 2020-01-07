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

#include <libclsp/types/hover.hpp>

namespace libclsp
{

using namespace std;

const String HoverClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String HoverClientCapabilities::
	contentFormatKey       = "contentFormat";

HoverClientCapabilities::
	HoverClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<vector<MarkupKind>> contentFormat):
			dynamicRegistration(dynamicRegistration),
			contentFormat(contentFormat)
{};

HoverClientCapabilities::HoverClientCapabilities():
	dynamicRegistration(),
	contentFormat()
{};

HoverClientCapabilities::~HoverClientCapabilities(){};


HoverRegistrationOptions::
	HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			HoverOptions(workDoneProgress)
{};

HoverRegistrationOptions::HoverRegistrationOptions():
	TextDocumentRegistrationOptions(),
	HoverOptions()
{};

HoverRegistrationOptions::~HoverRegistrationOptions(){};


HoverParams::HoverParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken)
{};

HoverParams::HoverParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams()
{};

HoverParams::~HoverParams(){};


const String _MarkedString::languageKey = "language";
const String _MarkedString::valueKey    = "value";

_MarkedString::_MarkedString(String language, String value):
	language(language),
	value(value)
{};

_MarkedString::_MarkedString():
	language(),
	value()
{};

_MarkedString::~_MarkedString(){};


const String Hover::contentsKey = "contents";
const String Hover::rangeKey    = "range";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

Hover::
	Hover(variant<MarkedString, vector<MarkedString>, MarkupContent> contents,
	optional<Range> range):
		contents(contents),
		range(range)
{};

#pragma GCC diagnostic pop

Hover::Hover(MarkupContent contents, optional<Range> range):
	contents(contents),
	range(range)
{};

Hover::Hover():
	contents(),
	range()
{};

Hover::~Hover(){};

}
