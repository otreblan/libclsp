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

#include <libclsp/types/colorPresentation.hpp>

namespace clsp
{

using namespace std;

const String ColorPresentationParams::textDocumentKey = "textDocument";
const String ColorPresentationParams::colorKey        = "color";
const String ColorPresentationParams::rangeKey        = "range";

ColorPresentationParams::ColorPresentationParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument,
	Color color,
	Range range):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument),
		color(color),
		range(range)
{};

ColorPresentationParams::ColorPresentationParams(){};
ColorPresentationParams::~ColorPresentationParams(){};

void ColorPresentationParams::fillInitializer(ObjectInitializer& initializer)
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

	// color:
	setterMap.emplace(
		colorKey,
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

				color.fillInitializer(handler->objectStack.top());

				neededMap[colorKey] = true;
			}
		}
	);

	// range:
	setterMap.emplace(
		rangeKey,
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

				range.fillInitializer(handler->objectStack.top());

				neededMap[rangeKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(colorKey, 0);
	neededMap.emplace(rangeKey, 0);

	// This
	initializer.object = this;
}


const String ColorPresentation::labelKey               = "label";
const String ColorPresentation::textEditKey            = "textEdit";
const String ColorPresentation::additionalTextEditsKey = "additionalTextEdits";

ColorPresentation::ColorPresentation(String label,
	optional<TextEdit> textEdit,
	optional<vector<TextEdit>> additionalTextEdits):
		label(label),
		textEdit(textEdit),
		additionalTextEdits(additionalTextEdits)
{};

ColorPresentation::ColorPresentation(){};
ColorPresentation::~ColorPresentation(){};

void ColorPresentation::partialWrite(JsonWriter &writer)
{
	// label
	writer.Key(labelKey);
	writer.String(label);

	// textEdit?
	if(textEdit.has_value())
	{
		writer.Key(textEditKey);
		writer.Object(*textEdit);
	}

	// additionalTextEdits?
	if(additionalTextEdits.has_value())
	{
		writer.Key(additionalTextEditsKey);
		writer.StartArray();
		for(auto& i: *additionalTextEdits)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}
}

}
