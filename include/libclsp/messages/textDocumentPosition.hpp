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

#include <libclsp/messages/textDocumentIdentifier.hpp>
#include <libclsp/messages/position.hpp>

namespace libclsp
{

using namespace std;

/// A parameter literal used in requests to pass a text document
/// and a position inside that document.
///
/// textDocument: TextDocumentIdentifier
///
/// position: Position
///
struct TextDocumentPositionParams
{

	const static String textDocumentKey;

	/// The text document.
	TextDocumentIdentifier textDocument;


	const static String positionKey;

	/// The position inside the text document.
	Position position;


	TextDocumentPositionParams(TextDocumentIdentifier textDocument,
		Position position);

	TextDocumentPositionParams();

	virtual ~TextDocumentPositionParams();
};

}
