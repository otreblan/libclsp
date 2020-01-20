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

#include <libclsp/types/textDocumentIdentifier.hpp>

namespace libclsp
{

using namespace std;

const String TextDocumentIdentifier::uriKey = "uri";

TextDocumentIdentifier::TextDocumentIdentifier(DocumentUri uri):
	uri(uri)
{};

TextDocumentIdentifier::TextDocumentIdentifier(){};
TextDocumentIdentifier::~TextDocumentIdentifier(){};

void TextDocumentIdentifier::fillInitializer(ObjectInitializer& initializer)
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

	// This
	initializer.object = this;
}


const String VersionedTextDocumentIdentifier::versionKey = "version";

VersionedTextDocumentIdentifier::
	VersionedTextDocumentIdentifier(DocumentUri uri,
		variant<Number, Null> version):
			TextDocumentIdentifier(uri),
			version(version)
{};

VersionedTextDocumentIdentifier::VersionedTextDocumentIdentifier(){};
VersionedTextDocumentIdentifier::~VersionedTextDocumentIdentifier(){};

void VersionedTextDocumentIdentifier::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parent
	TextDocumentIdentifier::fillInitializer(initializer);

	// Value setters

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
			[this, &neededMap]()
			{
				version = Null();
				neededMap[versionKey] = true;
			},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(versionKey, 0);

	// This
	initializer.object = this;
}

}
