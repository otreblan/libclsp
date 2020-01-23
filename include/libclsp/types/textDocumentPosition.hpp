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

#include <libclsp/types/textDocumentIdentifier.hpp>
#include <libclsp/types/position.hpp>

namespace clsp
{

using namespace std;

/// A parameter literal used in requests to pass a text document
/// and a position inside that document.
///
/// textDocument: TextDocumentIdentifier
///
/// position: Position
///
struct TextDocumentPositionParams: public virtual ObjectT
{
private:
	const static String textDocumentKey;
	const static String positionKey;

public:
	/// The text document.
	TextDocumentIdentifier textDocument;

	/// The position inside the text document.
	Position position;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	TextDocumentPositionParams(TextDocumentIdentifier textDocument,
		Position position);

	TextDocumentPositionParams();

	virtual ~TextDocumentPositionParams();
};

}
