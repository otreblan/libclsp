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

namespace libclsp
{

using namespace std;

/// Describes the content type that a client supports in various
/// result literals like `Hover`, `ParameterInfo` or `CompletionItem`.
///
/// Please note that `MarkupKinds` must not start with a `$`. This kinds
/// are reserved for internal usage.
enum class MarkupKind
{
	/// Plain text is supported as a content format
	PlainText,

	/// Markdown is supported as a content format
	Markdown
};

extern const boost::bimap<MarkupKind, String> MarkupKindMap;

String MarkupKind2String(MarkupKind kind);
MarkupKind String2MarkupKind(String str);


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
struct MarkupContent
{
	const static String kindKey;

	/// The type of the Markup
	MarkupKind kind;


	const static String valueKey;

	/// The content itself
	String value;


	MarkupContent(MarkupKind kind, String value);

	MarkupContent();

	virtual ~MarkupContent();

};

}
