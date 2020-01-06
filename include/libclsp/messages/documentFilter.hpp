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

#include <optional>

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// A document filter denotes a document through properties
/// like language, scheme or pattern
///
/// language?: String
///
/// scheme?: String
///
/// pattern?: String
///
struct DocumentFilter
{

	const static String languageKey;

	/// A language id, like `typescript`.
	optional<String> language;


	const static String schemeKey;

	/// A Uri [scheme](#Uri.scheme), like `file` or `untitled`.
	optional<String> scheme;


	const static String patternKey;

	/// A glob pattern, like `*.{ts,js}`.
	///
	/// Glob patterns can have the following syntax:
	/// - `*` to match one or more characters in a path segment
	/// - `?` to match on one character in a path segment
	/// - `**` to match any number of path segments, including none
	/// - `{}` to group conditions
	/// - `[]` to declare a range of characters to match in a path segment
	/// - `[!...]` to negate a range of characters to match in a path segment
	optional<String> pattern;

	DocumentFilter(optional<String> language,
		optional<String> scheme,
		optional<String> pattern);

	DocumentFilter();

	virtual ~DocumentFilter();
};

/// A document selector is the combination of one or more document filters.
using DocumentSelector = vector<DocumentFilter>;

}
