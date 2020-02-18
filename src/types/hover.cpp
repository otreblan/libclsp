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

	// contentFormat?:
	setterMap.emplace(
		contentFormatKey,
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
				contentFormat.emplace();

				handler->pushInitializer();

				auto* maker = new ContentFormatMaker(contentFormat.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
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
		nullopt,

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

HoverRegistrationOptions::
	HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			HoverOptions(workDoneProgress)
{};

HoverRegistrationOptions::HoverRegistrationOptions(){};
HoverRegistrationOptions::~HoverRegistrationOptions(){};

void HoverRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parents
	TextDocumentRegistrationOptions::partialWrite(writer);
	HoverOptions::partialWrite(writer);
}


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
	// Parents
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

void _MarkedString::partialWrite(JsonWriter &writer)
{
	// language
	writer.Key(languageKey);
	writer.String(language);

	// value
	writer.Key(valueKey);
	writer.String(value);
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

const String Hover::contentsKey = "contents";
const String Hover::rangeKey    = "range";

Hover::
	Hover(variant<MarkedString, vector<MarkedString>, MarkupContent> contents,
	optional<Range> range):
		contents(contents),
		range(range)
{};


Hover::Hover(MarkupContent contents, optional<Range> range):
	contents(contents),
	range(range)
{};

Hover::Hover(){};
Hover::~Hover(){};

void MarkedStringWriter(JsonWriter& writer, MarkedString& obj)
{
	visit(overload(
		[&writer](String& str)
		{
			writer.String(str);
		},
		[&writer](_MarkedString& obj)
		{
			writer.Object(obj);
		}
	), obj);
}

void Hover::partialWrite(JsonWriter &writer)
{
	// contents
	writer.Key(contentsKey);
	visit(overload(
		[&writer](MarkedString &obj)
		{
			MarkedStringWriter(writer, obj);
		},
		[&writer](vector<MarkedString> &arr)
		{
			writer.StartArray();
			for(auto& i: arr)
			{
				MarkedStringWriter(writer, i);
			}
			writer.EndArray();
		},
		[&writer](MarkupContent &obj)
		{
			writer.Object(obj);
		}
	), contents);

	// range?
	if(range.has_value())
	{
		writer.Key(rangeKey);
		writer.Object(*range);
	}
}

#pragma GCC diagnostic pop

}
