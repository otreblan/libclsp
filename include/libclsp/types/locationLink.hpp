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

#include <variant>
#include <optional>

#include <libclsp/types/range.hpp>

namespace clsp
{

using namespace std;

/// Represents a link between a source and a target location.
///
/// originSelectionRange?: Range
///
/// targetUri: DocumentUri
///
/// targetRange: Range
///
/// targetSelectionRange: Range
///
struct LocationLink: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String originSelectionRangeKey;
	const static String targetUriKey;
	const static String targetRangeKey;
	const static String targetSelectionRangeKey;

public:
	/// Span of the origin of this link.
	///
	/// Used as the underlined span for mouse interaction.
	/// Defaults to the word range at the mouse position.
	optional<Range> originSelectionRange;

	/// The target resource identifier of this link.
	DocumentUri targetUri;

	/// The full target range of this link. If the target for example is a symbol
	/// then target range is the range enclosing this symbol not including
	/// leading/trailing whitespace but everything else like comments.
	/// This information is typically used to highlight the range in the editor.
	Range targetRange;

	/// The range that should be selected and revealed when this link is being followed,
	/// e.g the name of a function.  Must be contained by the the `targetRange`.
	/// See also `DocumentSymbol#range`
	Range targetSelectionRange;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	LocationLink(optional<Range> originSelectionRange,
		DocumentUri targetUri,
		Range targetRange,
		Range targetSelectionRange);

	LocationLink();

	virtual ~LocationLink();
};

}
