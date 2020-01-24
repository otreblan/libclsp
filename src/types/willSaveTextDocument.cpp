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

#include <libclsp/types/willSaveTextDocument.hpp>

namespace clsp
{

using namespace std;

const String WillSaveTextDocumentParams::textDocumentKey = "textDocument";
const String WillSaveTextDocumentParams::reasonKey       = "reason";

WillSaveTextDocumentParams::
	WillSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		TextDocumentSaveReason reason):
			textDocument(textDocument),
			reason(reason)
{};

WillSaveTextDocumentParams::WillSaveTextDocumentParams(){};
WillSaveTextDocumentParams::~WillSaveTextDocumentParams(){};

void WillSaveTextDocumentParams::fillInitializer(ObjectInitializer& initializer)
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
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();
				textDocument.fillInitializer(handler->objectStack.top());

				neededMap[textDocumentKey] = true;
			}
		}
	);

	// reason:
	setterMap.emplace(
		reasonKey,
		ValueSetter{
			// String
			{},

			// Number
			[this, &neededMap](Number n)
			{
				if(holds_alternative<int>(n))
				{
					reason = TextDocumentSaveReason(get<int>(n));

					neededMap[reasonKey] = true;
				}
				else
				{
					// TODO
					// Execption or something
				}

			},

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
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(reasonKey, 0);

	// This
	initializer.object = this;
}

}
