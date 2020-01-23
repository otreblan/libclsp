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

#include <libclsp/types/signatureHelp.hpp>

namespace clsp
{

using namespace std;

const String SignatureHelpClientCapabilities::
	dynamicRegistrationKey  = "dynamicRegistration";

const String SignatureHelpClientCapabilities::
	signatureInformationKey = "signatureInformation";

const String SignatureHelpClientCapabilities::
	contextSupportKey       = "contextSupport";

SignatureHelpClientCapabilities::
	SignatureHelpClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SignatureInformation> signatureInformation,
		optional<Boolean> contextSupport):
			dynamicRegistration(dynamicRegistration),
			signatureInformation(signatureInformation),
			contextSupport(contextSupport)
{};

SignatureHelpClientCapabilities::SignatureHelpClientCapabilities():
	dynamicRegistration(),
	signatureInformation(),
	contextSupport()
{};

SignatureHelpClientCapabilities::~SignatureHelpClientCapabilities(){};


const String SignatureHelpClientCapabilities::SignatureInformation::
	documentationFormatKey  = "documentationFormat";

const String SignatureHelpClientCapabilities::SignatureInformation::
	parameterInformationKey = "parameterInformation";

SignatureHelpClientCapabilities::SignatureInformation::
	SignatureInformation(optional<vector<MarkupKind>> documentationFormat,
			optional<ParameterInformation> parameterInformation):
				documentationFormat(documentationFormat),
				parameterInformation(parameterInformation)
{};

SignatureHelpClientCapabilities::SignatureInformation::SignatureInformation():
	documentationFormat(),
	parameterInformation()
{};

SignatureHelpClientCapabilities::SignatureInformation::~SignatureInformation()
{};

const String SignatureHelpClientCapabilities::
	SignatureInformation::
	ParameterInformation::
		labelOffsetSupportKey = "labelOffsetSupport";

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	ParameterInformation(optional<Boolean> labelOffsetSupport):
		labelOffsetSupport(labelOffsetSupport)
{};

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	ParameterInformation():
		labelOffsetSupport()
{};

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	~ParameterInformation()
{};


const String SignatureHelpOptions::
	triggerCharactersKey   = "triggerCharacters";

const String SignatureHelpOptions::
	retriggerCharactersKey = "retriggerCharacters";

SignatureHelpOptions::
	SignatureHelpOptions(optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> retriggerCharacters):
			WorkDoneProgressOptions(workDoneProgress),
			triggerCharacters(triggerCharacters),
			retriggerCharacters(retriggerCharacters)
{};

SignatureHelpOptions::SignatureHelpOptions():
	WorkDoneProgressOptions(),
	triggerCharacters(),
	retriggerCharacters()
{};

SignatureHelpOptions::~SignatureHelpOptions(){};


SignatureHelpRegistrationOptions::SignatureHelpRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<vector<String>> triggerCharacters,
	optional<vector<String>> retriggerCharacters):
		TextDocumentRegistrationOptions(documentSelector),
		SignatureHelpOptions(workDoneProgress,
			triggerCharacters,
			retriggerCharacters)
{};

SignatureHelpRegistrationOptions::SignatureHelpRegistrationOptions():
	TextDocumentRegistrationOptions(),
	SignatureHelpOptions()
{};

SignatureHelpRegistrationOptions::~SignatureHelpRegistrationOptions(){};


const String ParameterInformation::labelKey         = "label";
const String ParameterInformation::documentationKey = "documentation";

ParameterInformation::
	ParameterInformation(variant<String, array<Number, 2>> label,
		optional<variant<String, MarkupContent>> documentation):
			label(label),
			documentation(documentation)
{};

ParameterInformation::ParameterInformation():
	label(),
	documentation()
{};

ParameterInformation::~ParameterInformation(){};


const String SignatureInformation::labelKey         = "label";
const String SignatureInformation::documentationKey = "documentation";
const String SignatureInformation::parametersKey    = "parameters";

SignatureInformation::SignatureInformation(String label,
	optional<variant<String, MarkupContent>> documentation,
	optional<vector<ParameterInformation>> parameters):
		label(label),
		documentation(documentation),
		parameters(parameters)
{};

SignatureInformation::SignatureInformation():
		label(),
		documentation(),
		parameters()
{};

SignatureInformation::~SignatureInformation(){};


const String SignatureHelp::signaturesKey      = "signatures";
const String SignatureHelp::activeSignatureKey = "activeSignature";
const String SignatureHelp::activeParameterKey = "activeParameter";

SignatureHelp::SignatureHelp(vector<SignatureInformation> signatures,
	optional<Number> activeSignature,
	optional<Number> activeParameter):
		signatures(signatures),
		activeSignature(activeSignature),
		activeParameter(activeParameter)
{};

SignatureHelp::SignatureHelp():
	signatures(),
	activeSignature(),
	activeParameter()
{};

SignatureHelp::~SignatureHelp(){};


const String SignatureHelpContext::
	triggerKindKey         = "triggerKind";

const String SignatureHelpContext::
	triggerCharacterKey    = "triggerCharacter";

const String SignatureHelpContext::
	isRetriggerKey         = "isRetrigger";

const String SignatureHelpContext::
	activeSignatureHelpKey = "activeSignatureHelp";

SignatureHelpContext::
	SignatureHelpContext(SignatureHelpTriggerKind triggerKind,
		optional<String> triggerCharacter,
		Boolean isRetrigger,
		optional<SignatureHelp> activeSignatureHelp):
			triggerKind(triggerKind),
			triggerCharacter(triggerCharacter),
			isRetrigger(isRetrigger),
			activeSignatureHelp(activeSignatureHelp)
{};

SignatureHelpContext::SignatureHelpContext():
	triggerKind(),
	triggerCharacter(),
	isRetrigger(),
	activeSignatureHelp()
{};

SignatureHelpContext::~SignatureHelpContext(){};


const String SignatureHelpParams::contextKey = "context";

SignatureHelpParams::SignatureHelpParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<SignatureHelpContext> context):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		context(context)
{};

SignatureHelpParams::SignatureHelpParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	context()
{};

SignatureHelpParams::~SignatureHelpParams(){};

}
