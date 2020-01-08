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

#include <libclsp/types/definition.hpp>

namespace libclsp
{

using namespace std;

const String DefinitionClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String DefinitionClientCapabilities::
	linkSupportKey         = "linkSupport";

DefinitionClientCapabilities::
	DefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport):
			dynamicRegistration(dynamicRegistration),
			linkSupport(linkSupport)
{};

DefinitionClientCapabilities::DefinitionClientCapabilities():
	dynamicRegistration(),
	linkSupport()
{};

DefinitionClientCapabilities::~DefinitionClientCapabilities(){};


DefinitionRegistrationOptions::
	DefinitionRegistrationOptions(optional<ProgressToken> workDoneProgress,
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id):
			DefinitionOptions(workDoneProgress),
			TextDocumentRegistrationOptions(documentSelector),
			StaticRegistrationOptions(id)
{};

DefinitionRegistrationOptions::DefinitionRegistrationOptions():
	DefinitionOptions(),
	TextDocumentRegistrationOptions(),
	StaticRegistrationOptions()
{};

DefinitionRegistrationOptions::~DefinitionRegistrationOptions(){};


DefinitionParams::DefinitionParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

DefinitionParams::DefinitionParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams()
{};

DefinitionParams::~DefinitionParams(){};

}
