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

#include <libclsp/types/textDocumentItem.hpp>

namespace libclsp
{

using namespace std;

const String TextDocumentItem::uriKey        = "uri";
const String TextDocumentItem::languageIdKey = "languageId";
const String TextDocumentItem::versionKey    = "version";
const String TextDocumentItem::textKey       = "text";

TextDocumentItem::TextDocumentItem(DocumentUri uri,
	String languageId,
	Number version,
	String text):
		uri(uri),
		languageId(languageId),
		version(version),
		text(text)
{};

TextDocumentItem::TextDocumentItem(){};
TextDocumentItem::~TextDocumentItem(){};

void TextDocumentItem::fillInitializer(JsonHandler& handler)
{
	auto& topValue = handler.objectStack.top();

	auto& setterMap = topValue.setterMap;
	auto& neededMap = topValue.neededMap;

	// Value setters

	// uri:
	setterMap.emplace(
		uriKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				uri = str;
				neededMap[uriKey] = true;
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

	// languageId:
	setterMap.emplace(
		languageIdKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				languageId = str;
				neededMap[languageIdKey] = true;
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

	// version:
	setterMap.emplace(
		versionKey,
		ValueSetter{
			// String
			{},

			// Number
			[this, &neededMap](Number n)
			{
				version = n;
				neededMap[versionKey] = true;
			},

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
	neededMap.emplace(uriKey, 0);
	neededMap.emplace(languageIdKey, 0);
	neededMap.emplace(versionKey, 0);
	neededMap.emplace(textKey, 0);

	// This
	topValue.object = this;
}

}
