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

DocumentOnTypeFormattingClientCapabilities::DocumentOnTypeFormattingClientCapabilities():
	dynamicRegistration()
{};

DocumentOnTypeFormattingClientCapabilities::~DocumentOnTypeFormattingClientCapabilities(){};


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

DocumentOnTypeFormattingOptions::DocumentOnTypeFormattingOptions():
	firstTriggerCharacter(),
	moreTriggerCharacter()
{};

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
	DocumentOnTypeFormattingRegistrationOptions():
		TextDocumentRegistrationOptions(),
		DocumentOnTypeFormattingOptions()
{};

DocumentOnTypeFormattingRegistrationOptions::
	~DocumentOnTypeFormattingRegistrationOptions()
{};


const String DocumentOnTypeFormattingParams::textDocumentKey = "textDocument";
const String DocumentOnTypeFormattingParams::positionKey     = "position";
const String DocumentOnTypeFormattingParams::chKey           = "ch";
const String DocumentOnTypeFormattingParams::optionsKey      = "options";

DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams(
	TextDocumentIdentifier textDocument,
	Position position,
	String ch,
	FormattingOptions options):
		textDocument(textDocument),
		position(position),
		ch(ch),
		options(options)
{};

DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams():
	textDocument(),
	position(),
	ch(),
	options()
{};

DocumentOnTypeFormattingParams::~DocumentOnTypeFormattingParams(){};

}
