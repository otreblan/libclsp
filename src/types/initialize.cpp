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

#include <libclsp/types/initialize.hpp>

namespace clsp
{

using namespace std;

const String TextDocumentClientCapabilities::
	synchronizationKey    = "synchronization";

const String TextDocumentClientCapabilities::
	completionKey         = "completion";

const String TextDocumentClientCapabilities::
	hoverKey              = "hover";

const String TextDocumentClientCapabilities::
	signatureHelpKey      = "signatureHelp";

const String TextDocumentClientCapabilities::
	declarationKey        = "declaration";

const String TextDocumentClientCapabilities::
	definitionKey         = "definition";

const String TextDocumentClientCapabilities::
	typeDefinitionKey     = "typeDefinition";

const String TextDocumentClientCapabilities::
	implementationKey     = "implementation";

const String TextDocumentClientCapabilities::
	referencesKey         = "references";

const String TextDocumentClientCapabilities::
	documentHighlightKey  = "documentHighlight";

const String TextDocumentClientCapabilities::
	documentSymbolKey     = "documentSymbol";

const String TextDocumentClientCapabilities::
	codeActionKey         = "codeAction";

const String TextDocumentClientCapabilities::
	codeLensKey           = "codeLens";

const String TextDocumentClientCapabilities::
	documentLinkKey       = "documentLink";

const String TextDocumentClientCapabilities::
	colorProviderKey      = "colorProvider";

const String TextDocumentClientCapabilities::
	formattingKey         = "formatting";

const String TextDocumentClientCapabilities::
	rangeFormattingKey    = "rangeFormatting";

const String TextDocumentClientCapabilities::
	onTypeFormattingKey   = "onTypeFormatting";

const String TextDocumentClientCapabilities::
	renameKey             = "rename";

const String TextDocumentClientCapabilities::
	publishDiagnosticsKey = "publishDiagnostics";

const String TextDocumentClientCapabilities::
	foldingRangeKey       = "foldingRange";

const String TextDocumentClientCapabilities::
	selectionRangeKey     = "selectionRange";

TextDocumentClientCapabilities::TextDocumentClientCapabilities(
	optional<TextDocumentSyncClientCapabilities> synchronization,
	optional<CompletionClientCapabilities> completion,
	optional<HoverClientCapabilities> hover,
	optional<SignatureHelpClientCapabilities> signatureHelp,
	optional<DeclarationClientCapabilities> declaration,
	optional<DefinitionClientCapabilities> definition,
	optional<TypeDefinitionClientCapabilities> typeDefinition,
	optional<ImplementationClientCapabilities> implementation,
	optional<ReferenceClientCapabilities> references,
	optional<DocumentHighlightClientCapabilities> documentHighlight,
	optional<DocumentSymbolClientCapabilities> documentSymbol,
	optional<CodeActionClientCapabilities> codeAction,
	optional<CodeLensClientCapabilities> codeLens,
	optional<DocumentLinkClientCapabilities> documentLink,
	optional<DocumentColorClientCapabilities> colorProvider,
	optional<DocumentFormattingClientCapabilities> formatting,
	optional<DocumentRangeFormattingClientCapabilities> rangeFormatting,
	optional<DocumentOnTypeFormattingClientCapabilities> onTypeFormatting,
	optional<RenameClientCapabilities> rename,
	optional<PublishDiagnosticsClientCapabilities> publishDiagnostics,
	optional<FoldingRangeClientCapabilities> foldingRange,
	optional<SelectionRangeClientCapabilities> selectionRange):
		synchronization(synchronization),
		completion(completion),
		hover(hover),
		signatureHelp(signatureHelp),
		declaration(declaration),
		definition(definition),
		typeDefinition(typeDefinition),
		implementation(implementation),
		references(references),
		documentHighlight(documentHighlight),
		documentSymbol(documentSymbol),
		codeAction(codeAction),
		codeLens(codeLens),
		documentLink(documentLink),
		colorProvider(colorProvider),
		formatting(formatting),
		rangeFormatting(rangeFormatting),
		onTypeFormatting(onTypeFormatting),
		rename(rename),
		publishDiagnostics(publishDiagnostics),
		foldingRange(foldingRange),
		selectionRange(selectionRange)
{};

TextDocumentClientCapabilities::TextDocumentClientCapabilities(){};
TextDocumentClientCapabilities::~TextDocumentClientCapabilities(){};

void TextDocumentClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// synchronization?:
	setterMap.emplace(
		synchronizationKey,
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
				synchronization.emplace();

				handler->pushInitializer();
				synchronization->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// completion?:
	setterMap.emplace(
		completionKey,
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
				completion.emplace();

				handler->pushInitializer();
				completion->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// hover?:
	setterMap.emplace(
		hoverKey,
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
				hover.emplace();

				handler->pushInitializer();
				hover->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// signatureHelp?:
	setterMap.emplace(
		signatureHelpKey,
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
				signatureHelp.emplace();

				handler->pushInitializer();
				signatureHelp->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// declaration?:
	setterMap.emplace(
		declarationKey,
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
				declaration.emplace();

				handler->pushInitializer();
				declaration->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// definition?:
	setterMap.emplace(
		definitionKey,
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
				definition.emplace();

				handler->pushInitializer();
				definition->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// typeDefinition?:
	setterMap.emplace(
		typeDefinitionKey,
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
				typeDefinition.emplace();

				handler->pushInitializer();
				typeDefinition->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// implementation?:
	setterMap.emplace(
		implementationKey,
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
				implementation.emplace();

				handler->pushInitializer();
				implementation->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// references?:
	setterMap.emplace(
		referencesKey,
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
				references.emplace();

				handler->pushInitializer();
				references->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// documentHighlight?:
	setterMap.emplace(
		documentHighlightKey,
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
				documentHighlight.emplace();

				handler->pushInitializer();
				documentHighlight->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// documentSymbol?:
	setterMap.emplace(
		documentSymbolKey,
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
				documentSymbol.emplace();

				handler->pushInitializer();
				documentSymbol->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// codeAction?:
	setterMap.emplace(
		codeActionKey,
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
				codeAction.emplace();

				handler->pushInitializer();
				codeAction->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// codeLens?:
	setterMap.emplace(
		codeLensKey,
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
				codeLens.emplace();

				handler->pushInitializer();
				codeLens->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// documentLink?:
	setterMap.emplace(
		documentLinkKey,
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
				documentLink.emplace();

				handler->pushInitializer();
				documentLink->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// colorProvider?:
	setterMap.emplace(
		colorProviderKey,
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
				colorProvider.emplace();

				handler->pushInitializer();
				colorProvider->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// formatting?:
	setterMap.emplace(
		formattingKey,
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
				formatting.emplace();

				handler->pushInitializer();
				formatting->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// rangeFormatting?:
	setterMap.emplace(
		rangeFormattingKey,
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
				rangeFormatting.emplace();

				handler->pushInitializer();
				rangeFormatting->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// onTypeFormatting?:
	setterMap.emplace(
		onTypeFormattingKey,
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
				onTypeFormatting.emplace();

				handler->pushInitializer();
				onTypeFormatting->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// rename?:
	setterMap.emplace(
		renameKey,
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
				rename.emplace();

				handler->pushInitializer();
				rename->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// publishDiagnostics?:
	setterMap.emplace(
		publishDiagnosticsKey,
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
				publishDiagnostics.emplace();

				handler->pushInitializer();
				publishDiagnostics->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// foldingRange?:
	setterMap.emplace(
		foldingRangeKey,
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
				foldingRange.emplace();

				handler->pushInitializer();
				foldingRange->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// selectionRange?:
	setterMap.emplace(
		selectionRangeKey,
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
				selectionRange.emplace();

				handler->pushInitializer();
				selectionRange->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// This
	initializer.object = this;
}


const String ClientCapabilities::workspaceKey    = "workspace";
const String ClientCapabilities::textDocumentKey = "textDocument";
const String ClientCapabilities::experimentalKey = "experimental";

ClientCapabilities::ClientCapabilities(optional<Workspace> workspace,
	optional<TextDocumentClientCapabilities> textDocument,
	optional<Any> experimental,
	map<Key, Any> extra):
		workspace(workspace),
		textDocument(textDocument),
		experimental(experimental),
		extra(extra)
{};

ClientCapabilities::ClientCapabilities(){};
ClientCapabilities::~ClientCapabilities(){};

void ClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;
	auto& setterMap = initializer.setterMap;

	// Value setters

	// workspace?:
	setterMap.emplace(
		workspaceKey,
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
				workspace.emplace();

				handler->pushInitializer();
				workspace->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// textDocument?:
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
			[this, handler]()
			{
				textDocument.emplace();

				handler->pushInitializer();
				textDocument->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// experimental?:
	setterMap.emplace(
		experimentalKey,
		ValueSetter{
			// String
			[this](String str)
			{
				experimental = str;
			},

			// Number
			[this](Number n)
			{
				experimental = n;
			},

			// Boolean
			[this](Boolean b)
			{
				experimental = b;
			},

			// Null
			[this]()
			{
				experimental = Null();
			},

			// Array
			[this, handler]()
			{
				auto& arr = experimental.emplace().emplace<Array>();

				handler->pushInitializer();

				auto* maker = new ArrayMaker(arr);

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			[this, handler]()
			{
				auto& obj = experimental.emplace().
					emplace<Object>(make_shared<GenericObject>());

				handler->pushInitializer();
				obj->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// Extra
	extraSetter =
	{
		// String
		[this, handler](String str)
		{
			extra.emplace(handler->lastKey, str);
		},

		// Number
		[this, handler](Number n)
		{
			extra.emplace(handler->lastKey, n);
		},

		// Boolean
		[this, handler](Boolean b)
		{
			extra.emplace(handler->lastKey, b);
		},

		// Null
		[this, handler]()
		{
			extra.emplace(handler->lastKey, Null());
		},

		// Array
		[this, handler]()
		{
			auto& arr = get<Array>(
				extra.emplace(handler->lastKey, Array()).first->second);

			handler->pushInitializer();

			auto* maker = new ArrayMaker(arr);

			maker->fillInitializer(handler->objectStack.top());
		},

		// Object
		[this, handler]()
		{
			auto& obj = get<Object>(extra.emplace(
				handler->lastKey, make_shared<GenericObject>()).first->second);

			handler->pushInitializer();
			obj->fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}

const String ClientCapabilities::Workspace::
	applyEditKey              = "applyEdit";

const String ClientCapabilities::Workspace::
	workspaceEditKey          = "workspaceEdit";

const String ClientCapabilities::Workspace::
	didChangeConfigurationKey = "didChangeConfiguration";

const String ClientCapabilities::Workspace::
	didChangeWatchedFilesKey  = "didChangeWatchedFiles";

const String ClientCapabilities::Workspace::
	symbolKey                 = "symbol";

const String ClientCapabilities::Workspace::
	executeCommandKey         = "executeCommand";

const String ClientCapabilities::Workspace::
	workspaceFoldersKey       = "workspaceFolders";

const String ClientCapabilities::Workspace::
	configurationKey          = "configuration";

ClientCapabilities::Workspace::Workspace(optional<Boolean> applyEdit,
	optional<WorkspaceEditClientCapabilities> workspaceEdit,
	optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration,
	optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles,
	optional<WorkspaceSymbolClientCapabilities> symbol,
	optional<ExecuteCommandClientCapabilities> executeCommand,
	optional<Boolean> workspaceFolders,
	optional<Boolean> configuration):
		applyEdit(applyEdit),
		workspaceEdit(workspaceEdit),
		didChangeConfiguration(didChangeConfiguration),
		didChangeWatchedFiles(didChangeWatchedFiles),
		symbol(symbol),
		executeCommand(executeCommand),
		workspaceFolders(workspaceFolders),
		configuration(configuration)
{};

ClientCapabilities::Workspace::Workspace(){};
ClientCapabilities::Workspace::~Workspace(){};

void ClientCapabilities::Workspace::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// applyEdit?:
	setterMap.emplace(
		applyEditKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				applyEdit = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// workspaceEdit?:
	setterMap.emplace(
		workspaceEditKey,
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
				workspaceEdit.emplace();

				handler->pushInitializer();
				workspaceEdit->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// didChangeConfiguration?:
	setterMap.emplace(
		didChangeConfigurationKey,
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
				didChangeConfiguration.emplace();

				handler->pushInitializer();
				didChangeConfiguration->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// didChangeWatchedFiles?:
	setterMap.emplace(
		didChangeWatchedFilesKey,
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
				didChangeWatchedFiles.emplace();

				handler->pushInitializer();
				didChangeWatchedFiles->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// symbol?:
	setterMap.emplace(
		symbolKey,
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
				symbol.emplace();

				handler->pushInitializer();
				symbol->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// executeCommand?:
	setterMap.emplace(
		executeCommandKey,
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
				executeCommand.emplace();

				handler->pushInitializer();
				executeCommand->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// workspaceFolders?:
	setterMap.emplace(
		workspaceFoldersKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				workspaceFolders = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// configuration?:
	setterMap.emplace(
		configurationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				configuration = b;
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


TraceKind::TraceKind(String kind)
{
	auto newKind = kindMap.right.find(kind);

	// If the string is in the enum
	if(newKind != kindMap.right.end())
	{
		this->kind = newKind->second;
	}
	else
	{
		// Off by default
		this->kind = _TraceKind::Off;
	}
}

TraceKind::TraceKind(_TraceKind kind):
	kind(kind)
{};

TraceKind::~TraceKind(){};

const boost::bimap<TraceKind::_TraceKind, String> TraceKind::kindMap =
	boost::assign::list_of<boost::bimap<_TraceKind, String>::relation>
		(_TraceKind::Off,      "off")
		(_TraceKind::Messages, "messages")
		(_TraceKind::Verbose,  "verbose");


const TraceKind TraceKind::Off      = _TraceKind::Off;
const TraceKind TraceKind::Messages = _TraceKind::Messages;
const TraceKind TraceKind::Verbose  = _TraceKind::Verbose;


const String InitializeParams::processIdKey             = "processId";
const String InitializeParams::clientInfoKey            = "clientInfo";
const String InitializeParams::rootPathKey              = "rootPath";
const String InitializeParams::rootUriKey               = "rootUri";
const String InitializeParams::initializationOptionsKey = "initializationOptions";
const String InitializeParams::capabilitiesKey          = "capabilities";
const String InitializeParams::traceKey                 = "trace";
const String InitializeParams::workspaceFoldersKey      = "workspaceFolders";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

InitializeParams::InitializeParams(optional<ProgressToken> workDoneToken,
	variant<Number, Null> processId,
	optional<ClientInfo> clientInfo,
	optional<variant<String, Null>> rootPath,
	variant<DocumentUri, Null> rootUri,
	optional<Any> initializationOptions,
	ClientCapabilities capabilities,
	optional<TraceKind> trace,
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders):
		WorkDoneProgressParams(workDoneToken),
		processId(processId),
		clientInfo(clientInfo),
		rootPath(rootPath),
		rootUri(rootUri),
		initializationOptions(initializationOptions),
		capabilities(capabilities),
		trace(trace),
		workspaceFolders(workspaceFolders)
{};

InitializeParams::InitializeParams(optional<ProgressToken> workDoneToken,
	variant<Number, Null> processId,
	optional<ClientInfo> clientInfo,
	variant<DocumentUri, Null> rootUri,
	optional<Any> initializationOptions,
	ClientCapabilities capabilities,
	optional<TraceKind> trace,
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders):
		WorkDoneProgressParams(workDoneToken),
		processId(processId),
		clientInfo(clientInfo),
		rootUri(rootUri),
		initializationOptions(initializationOptions),
		capabilities(capabilities),
		trace(trace),
		workspaceFolders(workspaceFolders)
{};

InitializeParams::InitializeParams(){};
InitializeParams::~InitializeParams(){};

void InitializeParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parent
	WorkDoneProgressParams::fillInitializer(initializer);

	// Value setters

	// processId:
	setterMap.emplace(
		processIdKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				processId = n;
				neededMap[processIdKey] = true;
			},

			// Boolean
			nullopt,

			// Null
			[this, &neededMap]()
			{
				processId = Null();
				neededMap[processIdKey] = true;
			},

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// clientInfo?:
	setterMap.emplace(
		clientInfoKey,
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
				clientInfo.emplace();

				handler->pushInitializer();
				clientInfo->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// rootPath?:
	setterMap.emplace(
		rootPathKey,
		ValueSetter{
			// String
			[this](String str)
			{
				rootPath = str;
			},

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			[this]()
			{
				rootPath = Null();
			},

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// rootUri:
	setterMap.emplace(
		rootUriKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				rootUri = str;
				neededMap[rootUriKey] = true;
			},

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			[this, &neededMap]()
			{
				rootUri = Null();
				neededMap[rootUriKey] = true;
			},

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// initializationOptions?:
	setterMap.emplace(
		initializationOptionsKey,
		ValueSetter{
			// String
			[this](String str)
			{
				initializationOptions = str;
			},

			// Number
			[this](Number n)
			{
				initializationOptions = n;
			},

			// Boolean
			[this](Boolean b)
			{
				initializationOptions = b;
			},

			// Null
			[this]()
			{
				initializationOptions = Null();
			},

			// Array
			[this, handler]()
			{
				auto& arr = initializationOptions.emplace().emplace<Array>();

				handler->pushInitializer();

				auto* maker = new ArrayMaker(arr);

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			[this, handler]()
			{
				auto& obj = initializationOptions.emplace().
					emplace<Object>(make_shared<GenericObject>());

				handler->pushInitializer();
				obj->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// capabilities:
	setterMap.emplace(
		capabilitiesKey,
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
				capabilities.fillInitializer(handler->objectStack.top());

				neededMap[capabilitiesKey] = true;
			}
		}
	);

	// trace?:
	setterMap.emplace(
		traceKey,
		ValueSetter{
			// String
			[this](String str)
			{
				trace = TraceKind(str);
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

	// workspaceFolders?:
	setterMap.emplace(
		workspaceFoldersKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			[this]()
			{
				workspaceFolders = Null();
			},

			// Array
			[this, handler]()
			{
				auto& arr = workspaceFolders.emplace().emplace<vector<WorkspaceFolder>>();

				handler->pushInitializer();

				auto* maker = new WorkspaceFoldersMaker(arr);

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(processIdKey, 0);
	neededMap.emplace(rootUriKey, 0);
	neededMap.emplace(capabilitiesKey, 0);

	// This
	initializer.object = this;
}

#pragma GCC diagnostic pop

InitializeParams::WorkspaceFoldersMaker::
	WorkspaceFoldersMaker(vector<WorkspaceFolder> &parentArray):
		parentArray(parentArray)
{};

InitializeParams::WorkspaceFoldersMaker::
	~WorkspaceFoldersMaker()
{};

void InitializeParams::WorkspaceFoldersMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// WorkspaceFolder[]
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
			auto& obj = parentArray.emplace_back();

			handler->pushInitializer();
			obj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;
}


const String InitializeParams::ClientInfo::nameKey    = "name";
const String InitializeParams::ClientInfo::versionKey = "version";

InitializeParams::ClientInfo::ClientInfo(String name, optional<String> version):
	name(name),
	version(version)
{};

InitializeParams::ClientInfo::ClientInfo(){};
InitializeParams::ClientInfo::~ClientInfo(){};

void InitializeParams::ClientInfo::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// name:
	setterMap.emplace(
		nameKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				name = str;
				neededMap[nameKey] = true;
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

	// version?:
	setterMap.emplace(
		versionKey,
		ValueSetter{
			// String
			[this](String str)
			{
				version = str;
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

	// Needed members
	neededMap.emplace(nameKey, 0);

	// This
	initializer.object = this;
}

const String ServerCapabilities::
	textDocumentSyncKey                 = "textDocumentSync";

const String ServerCapabilities::
	completionProviderKey               = "completionProvider";

const String ServerCapabilities::
	hoverProviderKey                    = "hoverProvider";

const String ServerCapabilities::
	signatureHelpProviderKey            = "signatureHelpProvider";

const String ServerCapabilities::
	declarationProviderKey              = "declarationProvider";

const String ServerCapabilities::
	definitionProviderKey               = "definitionProvider";

const String ServerCapabilities::
	typeDefinitionProviderKey           = "typeDefinitionProvider";

const String ServerCapabilities::
	implementationProviderKey           = "implementationProvider";

const String ServerCapabilities::
	referencesProviderKey               = "referencesProvider";

const String ServerCapabilities::
	documentHighlightProviderKey        = "documentHighlightProvider";

const String ServerCapabilities::
	documentSymbolProviderKey           = "documentSymbolProvider";

const String ServerCapabilities::
	codeActionProviderKey               = "codeActionProvider";

const String ServerCapabilities::
	codeLensProviderKey                 = "codeLensProvider";

const String ServerCapabilities::
	documentLinkProviderKey             = "documentLinkProvider";

const String ServerCapabilities::
	colorProviderKey                    = "colorProvider";

const String ServerCapabilities::
	documentFormattingProviderKey       = "documentFormattingProvider";

const String ServerCapabilities::
	documentRangeFormattingProviderKey  = "documentRangeFormattingProvider";

const String ServerCapabilities::
	documentOnTypeFormattingProviderKey = "documentOnTypeFormattingProvider";

const String ServerCapabilities::
	renameProviderKey                   = "renameProvider";

const String ServerCapabilities::
	foldingRangeProviderKey             = "foldingRangeProvider";

const String ServerCapabilities::
	executeCommandProviderKey           = "executeCommandProvider";

const String ServerCapabilities::
	selectionRangeProviderKey           = "selectionRangeProvider";

const String ServerCapabilities::
	workspaceSymbolProviderKey          = "workspaceSymbolProvider";

const String ServerCapabilities::
	workspaceKey                        = "workspace";

const String ServerCapabilities::
	experimentalKey                     = "experimental";

ServerCapabilities::ServerCapabilities(
	optional<variant<TextDocumentSyncOptions, Number>> textDocumentSync,
	optional<CompletionOptions> completionProvider,
	optional<variant<Boolean, HoverOptions>> hoverProvider,
	optional<SignatureHelpOptions> signatureHelpProvider,
	optional<variant<Boolean,
		DeclarationOptions,
		DeclarationRegistrationOptions>> declarationProvider,
	optional<variant<Boolean, DefinitionOptions>> definitionProvider,
	optional<variant<Boolean,
		TypeDefinitionOptions,
		TypeDefinitionRegistrationOptions>> typeDefinitionProvider,
	optional<variant<Boolean,
		ImplementationOptions,
		ImplementationRegistrationOptions>> implementationProvider,
	optional<variant<Boolean, ReferenceOptions>> referencesProvider,
	optional<variant<Boolean,
		DocumentHighlightOptions>> documentHighlightProvider,
	optional<variant<Boolean, DocumentSymbolOptions>> documentSymbolProvider,
	optional<variant<Boolean, CodeActionOptions>> codeActionProvider,
	optional<CodeLensOptions> codeLensProvider,
	optional<DocumentLinkOptions> documentLinkProvider,
	optional<variant<Boolean,
		DocumentColorOptions,
		DocumentColorRegistrationOptions>> colorProvider,
	optional<variant<Boolean,
		DocumentFormattingOptions>> documentFormattingProvider,
	optional<variant<Boolean,
		DocumentRangeFormattingOptions>> documentRangeFormattingProvider,
	optional<DocumentOnTypeFormattingOptions> documentOnTypeFormattingProvider,
	optional<variant<Boolean, RenameOptions>> renameProvider,
	optional<variant<Boolean,
		FoldingRangeOptions,
		FoldingRangeRegistrationOptions>> foldingRangeProvider,
	optional<ExecuteCommandOptions> executeCommandProvider,
	optional<variant<Boolean,
		SelectionRangeOptions,
		SelectionRangeRegistrationOptions>> selectionRangeProvider,
	optional<Boolean> workspaceSymbolProvider,
	optional<Workspace> workspace,
	optional<Any> experimental):
		textDocumentSync(textDocumentSync),
		completionProvider(completionProvider),
		hoverProvider(hoverProvider),
		signatureHelpProvider(signatureHelpProvider),
		declarationProvider(declarationProvider),
		definitionProvider(definitionProvider),
		typeDefinitionProvider(typeDefinitionProvider),
		implementationProvider(implementationProvider),
		referencesProvider(referencesProvider),
		documentHighlightProvider(documentHighlightProvider),
		documentSymbolProvider(documentSymbolProvider),
		codeActionProvider(codeActionProvider),
		codeLensProvider(codeLensProvider),
		documentLinkProvider(documentLinkProvider),
		colorProvider(colorProvider),
		documentFormattingProvider(documentFormattingProvider),
		documentRangeFormattingProvider(documentRangeFormattingProvider),
		documentOnTypeFormattingProvider(documentOnTypeFormattingProvider),
		renameProvider(renameProvider),
		foldingRangeProvider(foldingRangeProvider),
		executeCommandProvider(executeCommandProvider),
		selectionRangeProvider(selectionRangeProvider),
		workspaceSymbolProvider(workspaceSymbolProvider),
		workspace(workspace),
		experimental(experimental)
{};

ServerCapabilities::ServerCapabilities(){};
ServerCapabilities::~ServerCapabilities(){};


const String ServerCapabilities::Workspace::
	workspaceFoldersKey = "workspaceFolders";

ServerCapabilities::Workspace::
	Workspace(optional<WorkspaceFoldersServerCapabilities> workspaceFolders):
		workspaceFolders(workspaceFolders)
{};

ServerCapabilities::Workspace::Workspace(){};
ServerCapabilities::Workspace::~Workspace(){};


InitializedParams::InitializedParams(){};
InitializedParams::~InitializedParams(){};


const String InitializeResult::capabilitiesKey = "capabilities";
const String InitializeResult::serverInfoKey   = "serverInfo";

InitializeResult::InitializeResult(ServerCapabilities capabilities,
	optional<ServerInfo> serverInfo):
		capabilities(capabilities),
		serverInfo(serverInfo)
{};

InitializeResult::InitializeResult():
	capabilities(),
	serverInfo()
{};

InitializeResult::~InitializeResult(){};


const String InitializeResult::ServerInfo::nameKey    = "name";
const String InitializeResult::ServerInfo::versionKey = "version";

InitializeResult::ServerInfo::
	ServerInfo(String name, optional<String> version):
		name(name),
		version(version)
{};

InitializeResult::ServerInfo::ServerInfo(){};
InitializeResult::ServerInfo::~ServerInfo(){};


const String InitializeError::retryKey = "retry";

InitializeError::InitializeError(Boolean retry):
	retry(retry)
{};

InitializeError::InitializeError(){};
InitializeError::~InitializeError(){};

}
