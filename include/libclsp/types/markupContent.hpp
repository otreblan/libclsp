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

#pragma once

#include <boost/bimap.hpp>
#include <boost/assign.hpp>

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/objectT.hpp>

namespace clsp
{

using namespace std;

/// Describes the content type that a client supports in various
/// result literals like `Hover`, `ParameterInfo` or `CompletionItem`.
class MarkupKind
{
private:
	enum class _MarkupKind
	{
		PlainText,
		Markdown
	};

	static const boost::bimap<_MarkupKind, String> kindMap;

	_MarkupKind kind;

	MarkupKind(_MarkupKind kind);

public:
	/// Plain text is supported as a content format
	const static MarkupKind PlainText;

	/// Markdown is supported as a content format
	const static MarkupKind Markdown;


	MarkupKind();

	MarkupKind(String kind);

	virtual ~MarkupKind();

	operator String()
	{
		return kindMap.left.at(kind);
	}

	bool operator<(MarkupKind& other)
	{
		return this->kind < other.kind;
	}
};


/// A `MarkupContent` literal represents a string value which content is
/// interpreted base on its kind flag. Currently the protocol supports
/// `plaintext` and `markdown` as markup kinds.
///
/// If the kind is `markdown` then the value can contain fenced code blocks
/// like in GitHub issues. See
/// https://help.github.com/articles/creating-and-highlighting-code-blocks/#syntax-highlighting
///
/// kind: MarkupKind
///
/// value: String
///
struct MarkupContent: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String kindKey;
	const static String valueKey;

public:
	/// The type of the Markup
	MarkupKind kind;

	/// The content itself
	String value;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	MarkupContent(MarkupKind kind, String value);

	MarkupContent();

	virtual ~MarkupContent();

};

}
