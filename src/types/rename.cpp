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

#include <libclsp/types/rename.hpp>

namespace libclsp
{

using namespace std;

const String RenameClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String RenameClientCapabilities::
	prepareSupportKey      = "prepareSupport";

RenameClientCapabilities::
	RenameClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> prepareSupport):
			dynamicRegistration(dynamicRegistration),
			prepareSupport(prepareSupport)
{};

RenameClientCapabilities::RenameClientCapabilities():
	dynamicRegistration(),
	prepareSupport()
{};

RenameClientCapabilities::~RenameClientCapabilities(){};


const String RenameOptions::prepareProviderKey = "prepareProvider";

RenameOptions::RenameOptions(optional<ProgressToken> workDoneProgress,
	optional<Boolean> prepareProvider):
		WorkDoneProgressOptions(workDoneProgress),
		prepareProvider(prepareProvider)
{};

RenameOptions::RenameOptions():
	WorkDoneProgressOptions(),
	prepareProvider()
{};

RenameOptions::~RenameOptions(){};


RenameRegistrationOptions::RenameRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<Boolean> prepareProvider):
		TextDocumentRegistrationOptions(documentSelector),
		RenameOptions(workDoneProgress, prepareProvider)
{};

RenameRegistrationOptions::RenameRegistrationOptions():
	TextDocumentRegistrationOptions(),
	RenameOptions()
{};

RenameRegistrationOptions::~RenameRegistrationOptions(){};


const String RenameParams::textDocumentKey = "textDocument";
const String RenameParams::positionKey     = "position";
const String RenameParams::newNameKey      = "newName";


RenameParams::RenameParams(optional<ProgressToken> workDoneToken,
	TextDocumentIdentifier textDocument,
	Position position,
	String newName):
		WorkDoneProgressParams(workDoneToken),
		textDocument(textDocument),
		position(position),
		newName(newName)
{};

RenameParams::RenameParams():
	WorkDoneProgressParams(),
	textDocument(),
	position(),
	newName()
{};

RenameParams::~RenameParams(){};

}
