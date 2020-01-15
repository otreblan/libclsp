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

namespace libclsp
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
	optional<FoldingRangeClientCapabilities> foldingRange):
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
		foldingRange(foldingRange)
{};

TextDocumentClientCapabilities::TextDocumentClientCapabilities():
	synchronization(),
	completion(),
	hover(),
	signatureHelp(),
	declaration(),
	definition(),
	typeDefinition(),
	implementation(),
	references(),
	documentHighlight(),
	documentSymbol(),
	codeAction(),
	codeLens(),
	documentLink(),
	colorProvider(),
	formatting(),
	rangeFormatting(),
	onTypeFormatting(),
	rename(),
	publishDiagnostics(),
	foldingRange()
{};

TextDocumentClientCapabilities::~TextDocumentClientCapabilities(){};


const String ClientCapabilities::workspaceKey    = "workspace";
const String ClientCapabilities::textDocumentKey = "textDocument";
const String ClientCapabilities::experimentalKey = "experimental";

ClientCapabilities::ClientCapabilities(optional<Workspace> workspace,
	optional<TextDocumentClientCapabilities> textDocument,
	optional<Any> experimental):
		workspace(workspace),
		textDocument(textDocument),
		experimental(experimental)
{};

ClientCapabilities::ClientCapabilities():
	workspace(),
	textDocument(),
	experimental()
{};

ClientCapabilities::~ClientCapabilities(){};


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

ClientCapabilities::Workspace::Workspace(optional<Boolean> applyEdit,
	optional<WorkspaceEditClientCapabilities> workspaceEdit,
	optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration,
	optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles,
	optional<WorkspaceSymbolClientCapabilities> symbol,
	optional<ExecuteCommandClientCapabilities> executeCommand):
		applyEdit(applyEdit),
		workspaceEdit(workspaceEdit),
		didChangeConfiguration(didChangeConfiguration),
		didChangeWatchedFiles(didChangeWatchedFiles),
		symbol(symbol),
		executeCommand(executeCommand)
{};

ClientCapabilities::Workspace::Workspace():
	applyEdit(),
	workspaceEdit(),
	didChangeConfiguration(),
	didChangeWatchedFiles(),
	symbol(),
	executeCommand()
{};

ClientCapabilities::Workspace::~Workspace(){};


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

TraceKind::TraceKind():
	kind(_TraceKind::Off) // Off by default
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

InitializeParams::InitializeParams(variant<Number, Null> processId,
	optional<ClientInfo> clientInfo,
	optional<variant<String, Null>> rootPath,
	variant<DocumentUri, Null> rootUri,
	optional<Any> initializationOptions,
	ClientCapabilities capabilities,
	optional<TraceKind> trace,
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders):
		processId(processId),
		clientInfo(clientInfo),
		rootPath(rootPath),
		rootUri(rootUri),
		initializationOptions(initializationOptions),
		capabilities(capabilities),
		trace(trace),
		workspaceFolders(workspaceFolders)
{};

InitializeParams::InitializeParams(variant<Number, Null> processId,
	optional<ClientInfo> clientInfo,
	variant<DocumentUri, Null> rootUri,
	optional<Any> initializationOptions,
	ClientCapabilities capabilities,
	optional<TraceKind> trace,
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders):
		processId(processId),
		clientInfo(clientInfo),
		rootUri(rootUri),
		initializationOptions(initializationOptions),
		capabilities(capabilities),
		trace(trace),
		workspaceFolders(workspaceFolders)
{};

InitializeParams::InitializeParams():
	processId(),
	clientInfo(),
	rootPath(),
	rootUri(),
	initializationOptions(),
	capabilities(),
	trace(),
	workspaceFolders()
{};

InitializeParams::~InitializeParams(){};

#pragma GCC diagnostic pop

const String InitializeParams::ClientInfo::nameKey    = "name";
const String InitializeParams::ClientInfo::versionKey = "version";

InitializeParams::ClientInfo::ClientInfo(String name, optional<String> version):
	name(name),
	version(version)
{};

InitializeParams::ClientInfo::ClientInfo():
	name(),
	version()
{};

InitializeParams::ClientInfo::~ClientInfo(){};


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
		workspaceSymbolProvider(workspaceSymbolProvider),
		workspace(workspace),
		experimental(experimental)
{};

ServerCapabilities::ServerCapabilities():
	textDocumentSync(),
	completionProvider(),
	hoverProvider(),
	signatureHelpProvider(),
	declarationProvider(),
	definitionProvider(),
	typeDefinitionProvider(),
	implementationProvider(),
	referencesProvider(),
	documentHighlightProvider(),
	documentSymbolProvider(),
	codeActionProvider(),
	codeLensProvider(),
	documentLinkProvider(),
	colorProvider(),
	documentFormattingProvider(),
	documentRangeFormattingProvider(),
	documentOnTypeFormattingProvider(),
	renameProvider(),
	foldingRangeProvider(),
	executeCommandProvider(),
	workspaceSymbolProvider(),
	workspace(),
	experimental()
{};

ServerCapabilities::~ServerCapabilities(){};


const String ServerCapabilities::Workspace::
	workspaceFoldersKey = "workspaceFolders";

ServerCapabilities::Workspace::
	Workspace(optional<WorkspaceFoldersServerCapabilities> workspaceFolders):
		workspaceFolders(workspaceFolders)
{};

ServerCapabilities::Workspace::Workspace():
	workspaceFolders()
{};

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

InitializeResult::ServerInfo::ServerInfo():
	name(),
	version()
{};

InitializeResult::ServerInfo::~ServerInfo(){};


const String InitializeError::retryKey = "retry";

InitializeError::InitializeError(Boolean retry):
	retry(retry)
{};

InitializeError::InitializeError():
	retry()
{};

InitializeError::~InitializeError(){};

}
