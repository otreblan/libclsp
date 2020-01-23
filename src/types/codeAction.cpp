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

#include <libclsp/types/codeAction.hpp>

namespace clsp
{

using namespace std;

CodeActionKind::CodeActionKind(String kind):
	kind(kind)
{};

const CodeActionKind
	CodeActionKind::Empty                 = ""s,
	CodeActionKind::QuickFix              = "quickfix"s,
	CodeActionKind::Refactor              = "refactor"s,
	CodeActionKind::RefactorExtract       = "refactor.extract"s,
	CodeActionKind::RefactorInline        = "refactor.inline"s,
	CodeActionKind::RefactorRewrite       = "refactor.rewrite"s,
	CodeActionKind::Source                = "source"s,
	CodeActionKind::SourceOrganizeImports = "source.organizeImports"s;


const String CodeActionClientCapabilities::
	dynamicRegistrationKey      = "dynamicRegistration";

const String CodeActionClientCapabilities::
	codeActionLiteralSupportKey = "codeActionLiteralSupport";

const String CodeActionClientCapabilities::
	isPreferredSupportKey       = "isPreferredSupport";

CodeActionClientCapabilities::
	CodeActionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<CodeActionLiteralSupport> codeActionLiteralSupport,
		optional<Boolean> isPreferredSupport):
			dynamicRegistration(dynamicRegistration),
			codeActionLiteralSupport(codeActionLiteralSupport),
			isPreferredSupport(isPreferredSupport)
{};

CodeActionClientCapabilities:: CodeActionClientCapabilities():
	dynamicRegistration(),
	codeActionLiteralSupport(),
	isPreferredSupport()
{};

CodeActionClientCapabilities::~CodeActionClientCapabilities(){};


const String CodeActionClientCapabilities::CodeActionLiteralSupport::
	codeActionKindKey = "codeActionKind";

CodeActionClientCapabilities::CodeActionLiteralSupport::
	CodeActionLiteralSupport(CodeActionKind codeActionKind):
		codeActionKind(codeActionKind)
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::
	CodeActionLiteralSupport():
		codeActionKind()
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::
	~CodeActionLiteralSupport()
{};


const String CodeActionClientCapabilities::
	CodeActionLiteralSupport::
	CodeActionKind::
		valueSetKey = "valueSet";

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	CodeActionKind(vector<clsp::CodeActionKind> valueSet):
		valueSet(valueSet)
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	CodeActionKind():
		valueSet()
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	~CodeActionKind()
{};


const String CodeActionOptions::codeActionKindsKey = "codeActionKinds";

CodeActionOptions::CodeActionOptions(optional<ProgressToken> workDoneProgress,
	optional<vector<CodeActionKind>> codeActionKinds):
		WorkDoneProgressOptions(workDoneProgress),
		codeActionKinds(codeActionKinds)
{};

CodeActionOptions::CodeActionOptions():
	WorkDoneProgressOptions(),
	codeActionKinds()
{};

CodeActionOptions::~CodeActionOptions(){};


CodeActionRegistrationOptions::CodeActionRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<vector<CodeActionKind>> codeActionKinds):
		TextDocumentRegistrationOptions(documentSelector),
		CodeActionOptions(workDoneProgress, codeActionKinds)
{};

CodeActionRegistrationOptions::CodeActionRegistrationOptions():
	TextDocumentRegistrationOptions(),
	CodeActionOptions()
{};

CodeActionRegistrationOptions::~CodeActionRegistrationOptions(){};


const String CodeActionContext::diagnosticsKey = "diagnostics";
const String CodeActionContext::onlyKey = "only";

CodeActionContext::CodeActionContext(vector<Diagnostic> diagnostics,
	optional<vector<CodeActionKind>> only):
		diagnostics(diagnostics),
		only(only)
{};

CodeActionContext::CodeActionContext():
	diagnostics(),
	only()
{};

CodeActionContext::~CodeActionContext(){};


const String CodeActionParams::textDocumentKey = "textDocument";
const String CodeActionParams::rangeKey        = "range";
const String CodeActionParams::contextKey      = "context";

CodeActionParams::CodeActionParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument,
	Range range,
	CodeActionContext context):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument),
		range(range),
		context(context)
{};

CodeActionParams::CodeActionParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument(),
	range(),
	context()
{};

CodeActionParams::~CodeActionParams(){};


CodeAction::CodeAction(String title,
	optional<CodeActionKind> kind,
	optional<vector<Diagnostic>> diagnostics,
	optional<Boolean> isPreferred,
	optional<WorkspaceEdit> edit,
	optional<Command> command):
		title(title),
		kind(kind),
		diagnostics(diagnostics),
		isPreferred(isPreferred),
		edit(edit),
		command(command)
{};

CodeAction::CodeAction():
	title(),
	kind(),
	diagnostics(),
	isPreferred(),
	edit(),
	command()
{};

CodeAction::~CodeAction(){};

}
