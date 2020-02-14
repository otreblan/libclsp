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

#include <libclsp/types/didChangeTextDocument.hpp>

namespace clsp
{

using namespace std;

const String TextDocumentChangeRegistrationOptions::syncKindKey = "syncKind";

TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	TextDocumentSyncKind syncKind):
		TextDocumentRegistrationOptions(documentSelector),
		syncKind(syncKind)
{};

TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions()
{};

TextDocumentChangeRegistrationOptions::
	~TextDocumentChangeRegistrationOptions()
{};

void TextDocumentChangeRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parent
	TextDocumentRegistrationOptions::partialWrite(writer);

	// syncKind
	writer.Key(syncKindKey);
	writer.Int((int)syncKind);
}


const String TextDocumentContentChangeEvent::rangeKey       = "range";
const String TextDocumentContentChangeEvent::rangeLengthKey = "rangeLength";
const String TextDocumentContentChangeEvent::textKey        = "text";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

TextDocumentContentChangeEvent::
	TextDocumentContentChangeEvent(Range range, String text):
		range(range),
		text(text)
{};

TextDocumentContentChangeEvent::
	TextDocumentContentChangeEvent(String text):
		text(text)
{};


TextDocumentContentChangeEvent::TextDocumentContentChangeEvent(){};
TextDocumentContentChangeEvent::~TextDocumentContentChangeEvent(){};

void TextDocumentContentChangeEvent::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// range?:
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
			[this, handler]()
			{
				range.emplace();

				handler->pushInitializer();
				range->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// rangeLength?:
	setterMap.emplace(
		rangeLengthKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this](Number n)
			{
				rangeLength = n;
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

	// text:
	setterMap.emplace(
		textKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				text = str;

				neededMap[textKey] = true;
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
		}
	);

	// Needed members
	neededMap.emplace(textKey, 0);

	// This
	initializer.object = this;
}

#pragma GCC diagnostic pop

const String DidChangeTextDocumentParams::textDocumentKey   = "textDocument";
const String DidChangeTextDocumentParams::contentChangesKey = "contentChanges";

DidChangeTextDocumentParams::
	DidChangeTextDocumentParams(VersionedTextDocumentIdentifier textDocument,
		vector<TextDocumentContentChangeEvent> contentChanges):
			textDocument(textDocument),
			contentChanges(contentChanges)
{};

DidChangeTextDocumentParams::DidChangeTextDocumentParams(){};
DidChangeTextDocumentParams::~DidChangeTextDocumentParams(){};

void DidChangeTextDocumentParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

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

	// contentChanges:
	setterMap.emplace(
		contentChangesKey,
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
				auto* maker = new ContentChangesMaker(contentChanges);

				handler->pushInitializer();
				maker->fillInitializer(handler->objectStack.top());

				neededMap[contentChangesKey] = true;
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(contentChangesKey, 0);

	// This
	initializer.object = this;
}


DidChangeTextDocumentParams::ContentChangesMaker::
	ContentChangesMaker(vector<TextDocumentContentChangeEvent> &parentArray):
		parentArray(parentArray)
{};

DidChangeTextDocumentParams::ContentChangesMaker::
	~ContentChangesMaker()
{};

void DidChangeTextDocumentParams::ContentChangesMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// TextDocumentContentChangeEvent[]
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
			auto& newObject = parentArray.emplace_back();

			handler->pushInitializer();
			newObject.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}

}
