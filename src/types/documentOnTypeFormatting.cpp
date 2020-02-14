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

#include <libclsp/types/documentOnTypeFormatting.hpp>

namespace clsp
{

using namespace std;

const String DocumentOnTypeFormattingClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentOnTypeFormattingClientCapabilities::
	DocumentOnTypeFormattingClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DocumentOnTypeFormattingClientCapabilities::
	DocumentOnTypeFormattingClientCapabilities()
{};

DocumentOnTypeFormattingClientCapabilities::
	~DocumentOnTypeFormattingClientCapabilities()
{};

void DocumentOnTypeFormattingClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
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


const String DocumentOnTypeFormattingOptions::
	firstTriggerCharacterKey = "firstTriggerCharacter";

const String DocumentOnTypeFormattingOptions::
	moreTriggerCharacterKey  = "moreTriggerCharacter";

DocumentOnTypeFormattingOptions::
	DocumentOnTypeFormattingOptions(String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter):
			firstTriggerCharacter(firstTriggerCharacter),
			moreTriggerCharacter(moreTriggerCharacter)
{};

DocumentOnTypeFormattingOptions::DocumentOnTypeFormattingOptions(){};
DocumentOnTypeFormattingOptions::~DocumentOnTypeFormattingOptions(){};


DocumentOnTypeFormattingRegistrationOptions::
	DocumentOnTypeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter):
			TextDocumentRegistrationOptions(documentSelector),
			DocumentOnTypeFormattingOptions(firstTriggerCharacter,
				moreTriggerCharacter)
{};

DocumentOnTypeFormattingRegistrationOptions::
	DocumentOnTypeFormattingRegistrationOptions()
{};

DocumentOnTypeFormattingRegistrationOptions::
	~DocumentOnTypeFormattingRegistrationOptions()
{};


const String DocumentOnTypeFormattingParams::chKey           = "ch";
const String DocumentOnTypeFormattingParams::optionsKey      = "options";

DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams(
	TextDocumentIdentifier textDocument,
	Position position,
	String ch,
	FormattingOptions options):
		TextDocumentPositionParams(textDocument, position),
		ch(ch),
		options(options)
{};

DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams(){};
DocumentOnTypeFormattingParams::~DocumentOnTypeFormattingParams(){};

void DocumentOnTypeFormattingParams::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parent
	TextDocumentPositionParams::fillInitializer(initializer);

	// Value setters

	// ch:
	setterMap.emplace(
		chKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				ch = str;
				neededMap[chKey] = true;
			},

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// options:
	setterMap.emplace(
		optionsKey,
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

				options.fillInitializer(handler->objectStack.top());

				neededMap[optionsKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(chKey, 0);
	neededMap.emplace(optionsKey, 0);

	// This
	initializer.object = this;
}

}
