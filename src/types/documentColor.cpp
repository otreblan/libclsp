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

#include <libclsp/types/documentColor.hpp>

namespace clsp
{

using namespace std;

const String DocumentColorClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentColorClientCapabilities::
	DocumentColorClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DocumentColorClientCapabilities::DocumentColorClientCapabilities(){};
DocumentColorClientCapabilities::~DocumentColorClientCapabilities(){};

void DocumentColorClientCapabilities::
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

DocumentColorRegistrationOptions::DocumentColorRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<String> id,
	optional<Boolean> workDoneProgress):
		TextDocumentRegistrationOptions(documentSelector),
		StaticRegistrationOptions(id),
		DocumentColorOptions(workDoneProgress)
{};


DocumentColorRegistrationOptions::DocumentColorRegistrationOptions(){};
DocumentColorRegistrationOptions::~DocumentColorRegistrationOptions(){};

void DocumentColorRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parents
	TextDocumentRegistrationOptions::partialWrite(writer);
	StaticRegistrationOptions::partialWrite(writer);
	DocumentColorOptions::partialWrite(writer);
}


const String DocumentColorParams::textDocumentKey = "textDocument";

DocumentColorParams::DocumentColorParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

DocumentColorParams::DocumentColorParams(){};
DocumentColorParams::~DocumentColorParams(){};

void DocumentColorParams::fillInitializer(ObjectInitializer& initializer)
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


const String Color::redKey   = "red";
const String Color::greenKey = "green";
const String Color::blueKey  = "blue";
const String Color::alphaKey = "alpha";

Color::Color(Number red, Number green, Number blue, Number alpha):
	red(red),
	green(green),
	blue(blue),
	alpha(alpha)
{};

Color::Color(){};
Color::~Color(){};

void Color::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// red:
	setterMap.emplace(
		redKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				red = n;
				neededMap[redKey] = true;
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

	// green:
	setterMap.emplace(
		greenKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				green = n;
				neededMap[greenKey] = true;
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

	// blue:
	setterMap.emplace(
		blueKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				blue = n;
				neededMap[blueKey] = true;
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

	// alpha:
	setterMap.emplace(
		alphaKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				alpha = n;
				neededMap[alphaKey] = true;
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

	// Needed members
	neededMap.emplace(redKey, 0);
	neededMap.emplace(greenKey, 0);
	neededMap.emplace(blueKey, 0);
	neededMap.emplace(alphaKey, 0);

	// This
	initializer.object = this;
}

void Color::partialWrite(JsonWriter &writer)
{
	// red
	writer.Key(redKey);
	writer.Number(red);

	// green
	writer.Key(greenKey);
	writer.Number(green);

	// blue
	writer.Key(blueKey);
	writer.Number(blue);

	// alpha
	writer.Key(alphaKey);
	writer.Number(alpha);
}


const String ColorInformation::rangeKey = "range";
const String ColorInformation::colorKey = "color";

ColorInformation::ColorInformation(Range range, Color color):
	range(range),
	color(color)
{};

ColorInformation::ColorInformation(){};
ColorInformation::~ColorInformation(){};

void ColorInformation::partialWrite(JsonWriter &writer)
{
	// range
	writer.Key(rangeKey);
	writer.Object(range);

	// color
	writer.Key(colorKey);
	writer.Object(color);
}

}
