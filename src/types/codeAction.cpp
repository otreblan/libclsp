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

CodeActionClientCapabilities:: CodeActionClientCapabilities(){};
CodeActionClientCapabilities::~CodeActionClientCapabilities(){};

void CodeActionClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

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

	// codeActionLiteralSupport?:
	setterMap.emplace(
		codeActionLiteralSupportKey,
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
			[this, handler]()
			{
				codeActionLiteralSupport.emplace();

				handler->pushInitializer();
				codeActionLiteralSupport->
					fillInitializer(handler->objectStack.top());
			}
		}
	);

	// isPreferredSupport?:
	setterMap.emplace(
		isPreferredSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				isPreferredSupport = b;
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


const String CodeActionClientCapabilities::CodeActionLiteralSupport::
	codeActionKindKey = "codeActionKind";

CodeActionClientCapabilities::CodeActionLiteralSupport::
	CodeActionLiteralSupport(CodeActionKind codeActionKind):
		codeActionKind(codeActionKind)
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::
	CodeActionLiteralSupport()
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::
	~CodeActionLiteralSupport()
{};

void CodeActionClientCapabilities::CodeActionLiteralSupport::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// codeActionKind:
	setterMap.emplace(
		codeActionKindKey,
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

				codeActionKind.fillInitializer(handler->objectStack.top());

				neededMap[codeActionKindKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(codeActionKindKey, 0);

	// This
	initializer.object = this;
}

const String CodeActionClientCapabilities::
	CodeActionLiteralSupport::
	CodeActionKind::
		valueSetKey = "valueSet";

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	CodeActionKind(vector<clsp::CodeActionKind> valueSet):
		valueSet(valueSet)
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	CodeActionKind()
{};

CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	~CodeActionKind()
{};

void CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// valueSet:
	setterMap.emplace(
		valueSetKey,
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
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				auto* maker = new ValueSetMaker(valueSet);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[valueSetKey] = true;
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(valueSetKey, 0);

	// This
	initializer.object = this;
}

CodeActionClientCapabilities::
	CodeActionLiteralSupport::
	CodeActionKind::
	ValueSetMaker::
		ValueSetMaker(vector<clsp::CodeActionKind> &parentArray):
			parentArray(parentArray)
{};

CodeActionClientCapabilities::
	CodeActionLiteralSupport::
	CodeActionKind::
	ValueSetMaker::
		~ValueSetMaker()
{};

void CodeActionClientCapabilities::
	CodeActionLiteralSupport::
	CodeActionKind::
	ValueSetMaker::
		fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// CodeActionKind[]
	extraSetter =
	{
		// String
		[this](String str)
		{
			parentArray.emplace_back(str);
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
	};

	// This
	initializer.object = this;
}


const String CodeActionOptions::codeActionKindsKey = "codeActionKinds";

CodeActionOptions::CodeActionOptions(optional<ProgressToken> workDoneProgress,
	optional<vector<CodeActionKind>> codeActionKinds):
		WorkDoneProgressOptions(workDoneProgress),
		codeActionKinds(codeActionKinds)
{};

CodeActionOptions::CodeActionOptions(){};
CodeActionOptions::~CodeActionOptions(){};


CodeActionRegistrationOptions::CodeActionRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<vector<CodeActionKind>> codeActionKinds):
		TextDocumentRegistrationOptions(documentSelector),
		CodeActionOptions(workDoneProgress, codeActionKinds)
{};

CodeActionRegistrationOptions::CodeActionRegistrationOptions(){};
CodeActionRegistrationOptions::~CodeActionRegistrationOptions(){};


const String CodeActionContext::diagnosticsKey = "diagnostics";
const String CodeActionContext::onlyKey = "only";

CodeActionContext::CodeActionContext(vector<Diagnostic> diagnostics,
	optional<vector<CodeActionKind>> only):
		diagnostics(diagnostics),
		only(only)
{};

CodeActionContext::CodeActionContext(){};
CodeActionContext::~CodeActionContext(){};

void CodeActionContext::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// diagnostics:
	setterMap.emplace(
		diagnosticsKey,
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
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				auto* maker = new DiagnosticsMaker(diagnostics);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[diagnosticsKey] = true;
			},

			// Object
			nullopt
		}
	);

	// only?:
	setterMap.emplace(
		onlyKey,
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
			[this, handler]()
			{
				only.emplace();

				handler->pushInitializer();

				auto* maker = new OnlyMaker(only.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(diagnosticsKey, 0);

	// This
	initializer.object = this;
}

CodeActionContext::DiagnosticsMaker::
	DiagnosticsMaker(vector<Diagnostic> &parentArray):
		parentArray(parentArray)
{};

CodeActionContext::DiagnosticsMaker::
	~DiagnosticsMaker()
{};

void CodeActionContext::DiagnosticsMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// Diagnostic[]
	extraSetter =
	{
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
		[this, handler]()
		{
			auto &obj = parentArray.emplace_back();

			handler->pushInitializer();
			obj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}


CodeActionContext::OnlyMaker::OnlyMaker(vector<CodeActionKind> &parentArray):
	parentArray(parentArray)
{};

CodeActionContext::OnlyMaker::
	~OnlyMaker()
{};

void CodeActionContext::OnlyMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// CodeActionKind[]
	extraSetter =
	{
		// String
		[this](String str)
		{
			parentArray.emplace_back(str);
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
	};

	// This
	initializer.object = this;
}


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

CodeActionParams::CodeActionParams(){};
CodeActionParams::~CodeActionParams(){};

void CodeActionParams::fillInitializer(ObjectInitializer& initializer)
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

	// range:
	setterMap.emplace(
		rangeKey,
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

				range.fillInitializer(handler->objectStack.top());

				neededMap[rangeKey] = true;
			}
		}
	);

	// context:
	setterMap.emplace(
		contextKey,
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

				context.fillInitializer(handler->objectStack.top());

				neededMap[contextKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(rangeKey, 0);
	neededMap.emplace(contextKey, 0);

	// This
	initializer.object = this;
}

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

CodeAction::CodeAction(){};
CodeAction::~CodeAction(){};

}
