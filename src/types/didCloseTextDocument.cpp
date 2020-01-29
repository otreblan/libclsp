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

#include <libclsp/types/didCloseTextDocument.hpp>

namespace clsp
{

using namespace std;

const String DidCloseTextDocumentParams::textDocumentKey = "textDocument";

DidCloseTextDocumentParams::
	DidCloseTextDocumentParams(TextDocumentIdentifier textDocument):
		textDocument(textDocument)
{};

DidCloseTextDocumentParams::DidCloseTextDocumentParams(){};
DidCloseTextDocumentParams::~DidCloseTextDocumentParams(){};

void DidCloseTextDocumentParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// textDocument:
	setterMap.emplace(
		textDocumentKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();
				textDocument.fillInitializer(handler->objectStack.top());

				neededMap[textDocumentKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);

	// This
	initializer.object = this;
}

}
