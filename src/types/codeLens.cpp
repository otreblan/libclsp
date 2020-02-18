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

#include <libclsp/types/codeLens.hpp>

namespace clsp
{

using namespace std;

const String CodeLensClientCapabilities::
	dynamicRegistrationKey      = "dynamicRegistration";


CodeLensClientCapabilities::
	CodeLensClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

CodeLensClientCapabilities:: CodeLensClientCapabilities(){};
CodeLensClientCapabilities::~CodeLensClientCapabilities(){};

void CodeLensClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}

const String CodeLensOptions::resolveProviderKey = "resolveProvider";

CodeLensOptions::CodeLensOptions(optional<Boolean> workDoneProgress,
	optional<Boolean> resolveProvider):
		WorkDoneProgressOptions(workDoneProgress),
		resolveProvider(resolveProvider)
{};


CodeLensOptions::CodeLensOptions(){};
CodeLensOptions::~CodeLensOptions(){};


CodeLensRegistrationOptions::CodeLensRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<Boolean> workDoneProgress,
	optional<Boolean> resolveProvider):
		TextDocumentRegistrationOptions(documentSelector),
		CodeLensOptions(workDoneProgress, resolveProvider)
{};

CodeLensRegistrationOptions::CodeLensRegistrationOptions(){};
CodeLensRegistrationOptions::~CodeLensRegistrationOptions(){};


const String CodeLensParams::textDocumentKey = "textDocument";

CodeLensParams::CodeLensParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

CodeLensParams::CodeLensParams(){};
CodeLensParams::~CodeLensParams(){};

void CodeLensParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);

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

const String CodeLens::rangeKey   = "range";
const String CodeLens::commandKey = "command";
const String CodeLens::dataKey    = "data";

CodeLens::CodeLens(Range range,
	optional<Command> command,
	optional<Any> data):
		range(range),
		command(command),
		data(data)
{};

CodeLens::CodeLens(){};
CodeLens::~CodeLens(){};


}
