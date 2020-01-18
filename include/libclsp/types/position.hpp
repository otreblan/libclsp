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

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;

/// A position in a text document
///
/// line: Number
///
/// character: Number
///
struct Position: public ObjectT
{
private:
	const static String lineKey;
	const static String characterKey;

public:


	/// Line position in a document (zero-based).
	Number line;


	/// Character offset on a line in a document (zero-based). Assuming that the line is
	/// represented as a string, the `character` value represents the gap between the
	/// `character` and `character + 1`.
	///
	/// If the character value is greater than the line length it defaults back to the
	/// line length.
	Number character;


	//====================   Parsing   ======================================//

	/// This fills the ObjectInitializer at the top of the handler stack
	virtual void fillInitializer(JsonHandler& handler);

	// Using default isValid()

	//=======================================================================//


	Position(Number line, Number character);

	Position();

	virtual ~Position();
};

}
