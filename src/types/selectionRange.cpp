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

#include <libclsp/types/selectionRange.hpp>

namespace clsp
{

using namespace std;

const String SelectionRangeClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

SelectionRangeClientCapabilities::
	SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

SelectionRangeClientCapabilities::SelectionRangeClientCapabilities(){};
SelectionRangeClientCapabilities::~SelectionRangeClientCapabilities(){};

void SelectionRangeClientCapabilities::
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

SelectionRangeRegistrationOptions::
	SelectionRangeRegistrationOptions(optional<Boolean> workDoneProgress,
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id):
			SelectionRangeOptions(workDoneProgress),
			TextDocumentRegistrationOptions(documentSelector),
			StaticRegistrationOptions(id)
{};

SelectionRangeRegistrationOptions::SelectionRangeRegistrationOptions(){};
SelectionRangeRegistrationOptions::~SelectionRangeRegistrationOptions(){};

void SelectionRangeRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parents
	SelectionRangeOptions::partialWrite(writer);
	TextDocumentRegistrationOptions::partialWrite(writer);
	StaticRegistrationOptions::partialWrite(writer);
}


const String SelectionRangeParams::textDocumentKey = "textDocument";
const String SelectionRangeParams::positionsKey    = "positions";

SelectionRangeParams::SelectionRangeParams(
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument,
	vector<Position> positions):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument),
		positions(positions)
{};

SelectionRangeParams::SelectionRangeParams(){};
SelectionRangeParams::~SelectionRangeParams(){};

void SelectionRangeParams::fillInitializer(ObjectInitializer& initializer)
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

	// positions:
	setterMap.emplace(
		positionsKey,
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
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				auto* maker = new PositionsMaker(positions);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[positionsKey] = true;
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(positionsKey, 0);

	// This
	initializer.object = this;
}

SelectionRangeParams::PositionsMaker::
	PositionsMaker(vector<Position> &parentArray):
		parentArray(parentArray)
{};

SelectionRangeParams::PositionsMaker::
	~PositionsMaker()
{};

void SelectionRangeParams::PositionsMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// Position[]
	extraSetter =
	{
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
			auto &obj = parentArray.emplace_back();

			handler->pushInitializer();
			obj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}


const String SelectionRange::rangeKey  = "range";
const String SelectionRange::parentKey = "parent";

SelectionRange::SelectionRange(Range range,
	optional<shared_ptr<SelectionRange>> parent):
		range(range),
		parent(parent)
{};

SelectionRange::SelectionRange(Range range, SelectionRange parent):
	range(range),
	parent(make_shared<SelectionRange>(parent))
{};

SelectionRange::SelectionRange(){};
SelectionRange::~SelectionRange(){};

void SelectionRange::partialWrite(JsonWriter &writer)
{
	// range
	writer.Key(rangeKey);
	writer.Object(range);

	// parent?
	if(parent.has_value())
	{
		writer.Key(parentKey);
		writer.Object(**parent);
	}
}

}
