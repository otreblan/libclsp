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

#include <libclsp/types/reference.hpp>

namespace libclsp
{

using namespace std;

const String ReferenceClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

ReferenceClientCapabilities::
	ReferenceClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

ReferenceClientCapabilities::ReferenceClientCapabilities():
	dynamicRegistration()
{};

ReferenceClientCapabilities::~ReferenceClientCapabilities(){};


ReferenceRegistrationOptions::ReferenceRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			ReferenceOptions(workDoneProgress)
{};

ReferenceRegistrationOptions::ReferenceRegistrationOptions():
	TextDocumentRegistrationOptions(),
	ReferenceOptions()
{};

ReferenceRegistrationOptions::~ReferenceRegistrationOptions(){};


const String ReferenceContext::includeDeclarationKey = "includeDeclaration";

ReferenceContext::ReferenceContext(Boolean includeDeclaration):
	includeDeclaration(includeDeclaration)
{};

ReferenceContext::ReferenceContext():
	includeDeclaration()
{};

ReferenceContext::~ReferenceContext(){};


const String ReferenceParams::contextKey = "context";

ReferenceParams::ReferenceParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	ReferenceContext context):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		context(context)
{};

ReferenceParams::ReferenceParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams(),
	context()
{};

ReferenceParams::~ReferenceParams(){};

}
