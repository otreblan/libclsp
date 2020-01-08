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

#include <libclsp/types/implementation.hpp>

namespace libclsp
{

using namespace std;

const String ImplementationClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String ImplementationClientCapabilities::
	linkSupportKey         = "linkSupport";

ImplementationClientCapabilities::
	ImplementationClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport):
			dynamicRegistration(dynamicRegistration),
			linkSupport(linkSupport)
{};

ImplementationClientCapabilities::ImplementationClientCapabilities():
	dynamicRegistration(),
	linkSupport()
{};

ImplementationClientCapabilities::~ImplementationClientCapabilities(){};


ImplementationRegistrationOptions::
	ImplementationRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<String> id):
			TextDocumentRegistrationOptions(documentSelector),
			ImplementationOptions(workDoneProgress),
			StaticRegistrationOptions(id)
{};

ImplementationRegistrationOptions::ImplementationRegistrationOptions():
	TextDocumentRegistrationOptions(),
	ImplementationOptions(),
	StaticRegistrationOptions()
{};

ImplementationRegistrationOptions::~ImplementationRegistrationOptions(){};


ImplementationParams::ImplementationParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

ImplementationParams::ImplementationParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams()
{};

ImplementationParams::~ImplementationParams(){};

}
