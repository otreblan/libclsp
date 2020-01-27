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

namespace clsp
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

HoverClientCapabilities::HoverClientCapabilities(){};
HoverClientCapabilities::~HoverClientCapabilities(){};


void HoverClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// contentFormat?:
	setterMap.emplace(
		contentFormatKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{
				contentFormat.emplace();

				handler->pushInitializer();

				auto* maker = new ContentFormatMaker(contentFormat.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{}
		}
	);

	// This
	initializer.object = this;
}


HoverClientCapabilities::ContentFormatMaker::
	ContentFormatMaker(vector<MarkupKind> &parentArray):
		parentArray(parentArray)
{};

HoverClientCapabilities::ContentFormatMaker::
	~ContentFormatMaker()
{};


void HoverClientCapabilities::ContentFormatMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// MarkupKind[]
	extraSetter =
	{
		// String
		[this](String str)
		{
			parentArray.emplace_back(str);
		},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		{}
	};

	// This
	initializer.object = this;
}

HoverRegistrationOptions::
	HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			HoverOptions(workDoneProgress)
{};

HoverRegistrationOptions::HoverRegistrationOptions(){};
HoverRegistrationOptions::~HoverRegistrationOptions(){};


HoverParams::HoverParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken)
{};

HoverParams::HoverParams(){};
HoverParams::~HoverParams(){};

void HoverParams::fillInitializer(ObjectInitializer& initializer)
{
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);

	// This
	initializer.object = this;
}


const String _MarkedString::languageKey = "language";
const String _MarkedString::valueKey    = "value";

_MarkedString::_MarkedString(String language, String value):
	language(language),
	value(value)
{};

_MarkedString::_MarkedString(){};
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

Hover::Hover(){};
Hover::~Hover(){};

}
