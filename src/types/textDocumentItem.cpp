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

namespace clsp
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

void TextDocumentItem::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

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

	// version:
	setterMap.emplace(
		versionKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				version = n;
				neededMap[versionKey] = true;
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
	neededMap.emplace(uriKey, 0);
	neededMap.emplace(languageIdKey, 0);
	neededMap.emplace(versionKey, 0);
	neededMap.emplace(textKey, 0);

	// This
	initializer.object = this;
}

void TextDocumentItem::partialWrite(JsonWriter &writer)
{
	// uri
	writer.Key(uriKey);
	writer.String(uri);

	// languageId
	writer.Key(languageIdKey);
	writer.String(languageId);

	// version
	writer.Key(versionKey);
	writer.Number(version);

	// text
	writer.Key(textKey);
	writer.String(text);
}

}
