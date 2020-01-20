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

#include <libclsp/types/textEdit.hpp>

namespace libclsp
{

using namespace std;

const String TextEdit::rangeKey   = "range";
const String TextEdit::newTextKey = "newText";

TextEdit::TextEdit(Range range, String newText):
	range(range),
	newText(newText)
{};

TextEdit::TextEdit(){};
TextEdit::~TextEdit(){};

void TextEdit::fillInitializer(JsonHandler& handler)
{
	auto& topValue = handler.objectStack.top();

	auto& setterMap = topValue.setterMap;
	auto& neededMap = topValue.neededMap;

	// Value setters

	// range:
	setterMap.emplace(
		rangeKey,
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
			{},

			// Object
			[this, &handler, &neededMap]()
			{
				handler.preFillInitializer();

				range.fillInitializer(handler);

				neededMap[rangeKey] = true;
			}
		}
	);

	// newText:
	setterMap.emplace(
		newTextKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				newText = str;
				neededMap[newTextKey] = true;
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
		}
	);

	// Needed members
	neededMap.emplace(rangeKey, 0);
	neededMap.emplace(newTextKey, 0);

	// This
	topValue.object = this;
}

const String TextDocumentEdit::textDocumentKey = "textDocument";
const String TextDocumentEdit::editsKey        = "edits";

TextDocumentEdit::TextDocumentEdit(VersionedTextDocumentIdentifier textDocument,
	vector<TextEdit> edits):
		textDocument(textDocument),
		edits(edits)
{};

TextDocumentEdit::TextDocumentEdit(){};
TextDocumentEdit::~TextDocumentEdit(){};

void TextDocumentEdit::fillInitializer(JsonHandler& handler)
{
	auto& topValue = handler.objectStack.top();

	auto& setterMap = topValue.setterMap;
	auto& neededMap = topValue.neededMap;

	// Value setters

	// textDocument:
	setterMap.emplace(
		textDocumentKey,
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
			{},

			// Object
			[this, &handler, &neededMap]()
			{
				handler.preFillInitializer();
				textDocument.fillInitializer(handler);

				neededMap[textDocumentKey] = true;
			}
		}
	);

	// edits:
	setterMap.emplace(
		editsKey,
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
			[this, &handler, &neededMap]()
			{
				auto* maker = new EditsMaker;
				maker->parent = this;

				handler.preFillInitializer();
				maker->fillInitializer(handler);

				neededMap[editsKey] = true;
			},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(editsKey, 0);

	// This
	topValue.object = this;
}

void TextDocumentEdit::EditsMaker::fillInitializer(JsonHandler& handler)
{
	auto& topValue = handler.objectStack.top();

	auto& extraSetter = topValue.extraSetter;
	auto& Vector = parent->edits;

	// Value setters

	// TextEdit[]
	extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		[&Vector, &handler]()
		{
			auto& obj = Vector.emplace_back();

			handler.preFillInitializer();
			obj.fillInitializer(handler);
		}
	};

	// This
	topValue.object = this;

	// ObjectMaker
	topValue.objectMaker = unique_ptr<ObjectT>(this);
}

}
