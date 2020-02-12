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

#include <libclsp/types/markupContent.hpp>

namespace clsp
{

using namespace std;

const boost::bimap<MarkupKind::_MarkupKind, String> MarkupKind::kindMap =
	boost::assign::list_of<boost::bimap<_MarkupKind, String>::relation>
		(_MarkupKind::PlainText, "plaintext")
		(_MarkupKind::Markdown, "markdown");

MarkupKind::MarkupKind(_MarkupKind kind):
	kind(kind)
{};

MarkupKind::MarkupKind():
	kind(_MarkupKind::PlainText) // PlainText by default
{};

MarkupKind::MarkupKind(String kind)
{
	auto newKind = kindMap.right.find(kind);

	if(newKind != kindMap.right.end()) // If the kind is in the enum
	{
		this->kind = newKind->second;
	}
	else
	{
		// PlainText by default
		this->kind = _MarkupKind::PlainText;
	}
}

MarkupKind::~MarkupKind(){};

const MarkupKind MarkupKind::PlainText = _MarkupKind::PlainText;
const MarkupKind MarkupKind::Markdown  = _MarkupKind::Markdown;


const String MarkupContent::kindKey  = "kind";
const String MarkupContent::valueKey = "value";


MarkupContent::MarkupContent(MarkupKind kind, String value):
	kind(kind),
	value(value)
{};

MarkupContent::MarkupContent(){};
MarkupContent::~MarkupContent(){};

void MarkupContent::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// kind:
	setterMap.emplace(
		kindKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				kind = str;
				neededMap[kindKey] = true;
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

	// value:
	setterMap.emplace(
		valueKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				value = str;
				neededMap[valueKey] = true;
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
	neededMap.emplace(kindKey, 0);
	neededMap.emplace(valueKey, 0);

	// This
	initializer.object = this;
}

void MarkupContent::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kindKey);
	writer.String(kind);

	// value
	writer.Key(valueKey);
	writer.String(value);
}

}

