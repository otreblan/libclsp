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

#pragma once

#include <boost/bimap.hpp>
#include <boost/assign.hpp>

#include <libclsp/types/textDocumentSync.hpp>
#include <libclsp/types/completion.hpp>
#include <libclsp/types/hover.hpp>
#include <libclsp/types/signatureHelp.hpp>
#include <libclsp/types/declaration.hpp>
#include <libclsp/types/definition.hpp>
#include <libclsp/types/typeDefinition.hpp>
#include <libclsp/types/implementation.hpp>
#include <libclsp/types/reference.hpp>
#include <libclsp/types/highlight.hpp>
#include <libclsp/types/symbol.hpp>
#include <libclsp/types/codeAction.hpp>
#include <libclsp/types/codeLens.hpp>
#include <libclsp/types/documentLink.hpp>
#include <libclsp/types/documentColor.hpp>
#include <libclsp/types/documentFormatting.hpp>
#include <libclsp/types/documentRangeFormatting.hpp>
#include <libclsp/types/documentOnTypeFormatting.hpp>
#include <libclsp/types/rename.hpp>
#include <libclsp/types/publishDiagnostic.hpp>
#include <libclsp/types/foldingRange.hpp>
#include <libclsp/types/didChangeConfiguration.hpp>
#include <libclsp/types/didChangeWatchedFiles.hpp>
#include <libclsp/types/workspaceSymbol.hpp>
#include <libclsp/types/executeCommand.hpp>
#include <libclsp/types/workspaceFolder.hpp>


namespace libclsp
{

using namespace std;

/// Text document specific client capabilities.
///
/// synchronization?: TextDocumentSyncClientCapabilities
///
/// completion?: CompletionClientCapabilities
///
/// hover?: HoverClientCapabilities
///
/// signatureHelp?: SignatureHelpClientCapabilities
///
/// declaration?: DeclarationClientCapabilities
///
/// definition?: DefinitionClientCapabilities
///
/// typeDefinition?: TypeDefinitionClientCapabilities
///
/// implementation?: ImplementationClientCapabilities
///
/// references?: ReferenceClientCapabilities
///
/// documentHighlight?: DocumentHighlightClientCapabilities
///
/// documentSymbol?: DocumentSymbolClientCapabilities
///
/// codeAction?: CodeActionClientCapabilities
///
/// codeLens?: CodeLensClientCapabilities
///
/// documentLink?: DocumentLinkClientCapabilities
///
/// colorProvider?: DocumentColorClientCapabilities
///
/// formatting?: DocumentFormattingClientCapabilities
///
/// rangeFormatting?: DocumentRangeFormattingClientCapabilities
///
/// onTypeFormatting?: DocumentOnTypeFormattingClientCapabilities
///
/// rename?: RenameClientCapabilities
///
/// publishDiagnostics?: PublishDiagnosticsClientCapabilities
///
/// foldingRange?: FoldingRangeClientCapabilities
///
struct TextDocumentClientCapabilities
{

	const static String synchronizationKey;

	optional<TextDocumentSyncClientCapabilities> synchronization;


	const static String completionKey;

	/// Capabilities specific to the `textDocument/completion` request.
	optional<CompletionClientCapabilities> completion;


	const static String hoverKey;

	/// Capabilities specific to the `textDocument/hover` request.
	optional<HoverClientCapabilities> hover;


	const static String signatureHelpKey;

	/// Capabilities specific to the `textDocument/signatureHelp` request.
	optional<SignatureHelpClientCapabilities> signatureHelp;


	const static String declarationKey;

	/// Capabilities specific to the `textDocument/declaration` request.
	///
	/// @since 3.14.0
	optional<DeclarationClientCapabilities> declaration;


	const static String definitionKey;

	/// Capabilities specific to the `textDocument/definition` request.
	optional<DefinitionClientCapabilities> definition;


	const static String typeDefinitionKey;

	/// Capabilities specific to the `textDocument/typeDefinition` request.
	///
	/// @since 3.6.0
	optional<TypeDefinitionClientCapabilities> typeDefinition;


	const static String implementationKey;

	/// Capabilities specific to the `textDocument/implementation` request.
	///
	/// @since 3.6.0
	optional<ImplementationClientCapabilities> implementation;


	const static String referencesKey;

	/// Capabilities specific to the `textDocument/references` request.
	optional<ReferenceClientCapabilities> references;


	const static String documentHighlightKey;

	/// Capabilities specific to the `textDocument/documentHighlight` request.
	optional<DocumentHighlightClientCapabilities> documentHighlight;


	const static String documentSymbolKey;

	/// Capabilities specific to the `textDocument/documentSymbol` request.
	optional<DocumentSymbolClientCapabilities> documentSymbol;


	const static String codeActionKey;

	/// Capabilities specific to the `textDocument/codeAction` request.
	optional<CodeActionClientCapabilities> codeAction;


	const static String codeLensKey;

	/// Capabilities specific to the `textDocument/codeLens` request.
	optional<CodeLensClientCapabilities> codeLens;


	const static String documentLinkKey;

	/// Capabilities specific to the `textDocument/documentLink` request.
	optional<DocumentLinkClientCapabilities> documentLink;


	const static String colorProviderKey;

	/// Capabilities specific to the `textDocument/documentColor` and the
	/// `textDocument/colorPresentation` request.
	///
	/// @since 3.6.0
	optional<DocumentColorClientCapabilities> colorProvider;


	const static String formattingKey;

	/// Capabilities specific to the `textDocument/formatting` request.
	optional<DocumentFormattingClientCapabilities> formatting;


	const static String rangeFormattingKey;

	/// Capabilities specific to the `textDocument/rangeFormatting` request.
	optional<DocumentRangeFormattingClientCapabilities> rangeFormatting;


	const static String onTypeFormattingKey;

	/// Capabilities specific to the `textDocument/onTypeFormatting` request.
	optional<DocumentOnTypeFormattingClientCapabilities> onTypeFormatting;


	const static String renameKey;

	/// Capabilities specific to the `textDocument/rename` request.
	optional<RenameClientCapabilities> rename;


	const static String publishDiagnosticsKey;

	/// Capabilities specific to the `textDocument/publishDiagnostics` notification.
	optional<PublishDiagnosticsClientCapabilities> publishDiagnostics;


	const static String foldingRangeKey;

	/// Capabilities specific to the `textDocument/foldingRange` request.
	///
	/// @since 3.10.0
	optional<FoldingRangeClientCapabilities> foldingRange;


	TextDocumentClientCapabilities(
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
		optional<FoldingRangeClientCapabilities> foldingRange);

	TextDocumentClientCapabilities();

	virtual ~TextDocumentClientCapabilities();
};

/// ClientCapabilities define capabilities for dynamic registration, workspace
/// and text document features the client supports
///
/// workspace?: {
///
/// 	applyEdit?: boolean
///
/// 	workspaceEdit?: WorkspaceEditClientCapabilities
///
/// 	didChangeConfiguration?: DidChangeConfigurationClientCapabilities
///
/// 	didChangeWatchedFiles?: DidChangeWatchedFilesClientCapabilities
///
/// 	symbol?: WorkspaceSymbolClientCapabilities
///
/// 	executeCommand?: ExecuteCommandClientCapabilities
/// }
///
/// textDocument?: TextDocumentClientCapabilities
///
/// experimental?: Any
///
struct ClientCapabilities
{

	const static String workspaceKey;

	/// Workspace specific client capabilities.
	struct Workspace
	{

		const static String applyEditKey;

		/// The client supports applying batch edits
		/// to the workspace by supporting the request
		/// 'workspace/applyEdit'
		optional<Boolean> applyEdit;


		const static String workspaceEditKey;

		/// Capabilities specific to `WorkspaceEdit`s
		optional<WorkspaceEditClientCapabilities> workspaceEdit;


		const static String didChangeConfigurationKey;

		/// Capabilities specific to the `workspace/didChangeConfiguration`
		/// notification.
		optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration;


		const static String didChangeWatchedFilesKey;

		/// Capabilities specific to the `workspace/didChangeWatchedFiles`
		/// notification.
		optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles;


		const static String symbolKey;

		/// Capabilities specific to the `workspace/symbol` request.
		optional<WorkspaceSymbolClientCapabilities> symbol;


		const static String executeCommandKey;

		/// Capabilities specific to the `workspace/executeCommand` request.
		optional<ExecuteCommandClientCapabilities> executeCommand;


		Workspace(optional<Boolean> applyEdit,
			optional<WorkspaceEditClientCapabilities> workspaceEdit,
			optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration,
			optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles,
			optional<WorkspaceSymbolClientCapabilities> symbol,
			optional<ExecuteCommandClientCapabilities> executeCommand);

		Workspace();

		virtual ~Workspace();
	};

	/// Workspace specific client capabilities.
	optional<Workspace> workspace;


	const static String textDocumentKey;

	/// Text document specific client capabilities.
	optional<TextDocumentClientCapabilities> textDocument;


	const static String experimentalKey;

	/// Experimental client capabilities.
	optional<Any> experimental;


	ClientCapabilities(optional<Workspace> workspace,
		optional<TextDocumentClientCapabilities> textDocument,
		optional<Any> experimental);

	ClientCapabilities();

	virtual ~ClientCapabilities();
};

/// Trace used by the server
class TraceKind
{
private:

	enum class _TraceKind
	{
		Off,
		Messages,
		Verbose
	};

	_TraceKind kind;

	const static boost::bimap<_TraceKind, String> kindMap;

	TraceKind(_TraceKind kind);

public:
	TraceKind(String kind);

	TraceKind();


	const static TraceKind Off;
	const static TraceKind Messages;
	const static TraceKind Verbose;

	virtual ~TraceKind();

	operator String()
	{
		return kindMap.left.at(kind);
	}

	bool operator<(TraceKind& other)
	{
		return this->kind < other.kind;
	}
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/// Initialize request parameters
///
/// processId: Number | Null
///
/// clientInfo?: {
///
/// 	name: String
///
/// 	version?: String
/// }
///
/// rootPath?: String | Null
///
/// rootUri: DocumentUri | Null
///
/// initializationOptions?: Any
///
/// capabilities: ClientCapabilities
///
/// trace?: TraceKind
///
/// workspaceFolders?: WorkspaceFolder[] | Null
///
struct InitializeParams
{

	const static String processIdKey;

	/// The process Id of the parent process that started
	/// the server. Is null if the process has not been started by another
	/// process.
	/// If the parent process is not alive then the server should exit
	/// (see exit notification) its process.
	variant<Number, Null> processId;


	const static String clientInfoKey;

	/// Information about the client
	///
	/// @since 3.15.0
	struct ClientInfo
	{

		const static String nameKey;

		/// The name of the client as defined by the client.
		String name;


		const static String versionKey;

		/// The client's version as defined by the client.
		optional<String> version;


		ClientInfo(String name, optional<String> version);

		ClientInfo();

		virtual ~ClientInfo();
	};

	/// Information about the client
	///
	/// @since 3.15.0
	optional<ClientInfo> clientInfo;


	const static String rootPathKey;

	/// The rootPath of the workspace. Is null
	/// if no folder is open.
	///
	/// @deprecated in favour of rootUri.
	[[deprecated("Deprecated in favour of rootUri")]]
	optional<variant<String, Null>> rootPath;


	const static String rootUriKey;

	/// The rootUri of the workspace. Is null if no
	/// folder is open. If both `rootPath` and `rootUri` are set
	/// `rootUri` wins.
	variant<DocumentUri, Null> rootUri;


	const static String initializationOptionsKey;

	/// User provided initialization options.
	optional<Any> initializationOptions;


	const static String capabilitiesKey;

	/// The capabilities provided by the client (editor or tool)
	ClientCapabilities capabilities;


	const static String traceKey;

	/// The initial trace setting. If omitted trace is disabled ('off').
	optional<TraceKind> trace;


	const static String workspaceFoldersKey;

	/// The workspace folders configured in the client when the server starts.
	/// This property is only available if the client supports workspace
	/// folders.  It can be `null` if the client supports workspace folders
	/// but none are configured.
	///
	/// @since 3.6.0
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders;


	InitializeParams(variant<Number, Null> processId,
		optional<ClientInfo> clientInfo,
		optional<variant<String, Null>> rootPath,
		variant<DocumentUri, Null> rootUri,
		optional<Any> initializationOptions,
		ClientCapabilities capabilities,
		optional<TraceKind> trace,
		optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders);

	InitializeParams(variant<Number, Null> processId,
		optional<ClientInfo> clientInfo,
		variant<DocumentUri, Null> rootUri,
		optional<Any> initializationOptions,
		ClientCapabilities capabilities,
		optional<TraceKind> trace,
		optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders);

	InitializeParams();

	virtual ~InitializeParams();
};

#pragma GCC diagnostic pop

/// Server capabilities
///
/// textDocumentSync?: TextDocumentSyncOptions | Number
///
/// completionProvider?: CompletionOptions
///
/// hoverProvider?: Boolean | HoverOptions
///
/// signatureHelpProvider?: SignatureHelpOptions
///
/// declarationProvider?: Boolean | DeclarationOptions | DeclarationRegistrationOptions
///
/// definitionProvider?: Boolean | DefinitionOptions
///
/// typeDefinitionProvider?: Boolean | TypeDefinitionOptions | TypeDefinitionRegistrationOptions
///
/// implementationProvider?: Boolean | ImplementationOptions | ImplementationRegistrationOptions
///
/// referencesProvider?: Boolean | ReferenceOptions
///
/// documentHighlightProvider?: Boolean | DocumentHighlightOptions
///
/// documentSymbolProvider?: Boolean | DocumentSymbolOptions
///
/// codeActionProvider?: Boolean | CodeActionOptions
///
/// codeLensProvider?: CodeLensOptions
///
/// documentLinkProvider?: DocumentLinkOptions
///
/// colorProvider?: Boolean | DocumentColorOptions | DocumentColorRegistrationOptions
///
/// documentFormattingProvider?: Boolean | DocumentFormattingOptions
///
/// documentRangeFormattingProvider?: Boolean | DocumentRangeFormattingOptions
///
/// documentOnTypeFormattingProvider?: DocumentOnTypeFormattingOptions
///
/// renameProvider?: Boolean | RenameOptions
///
/// foldingRangeProvider?: Boolean | FoldingRangeOptions | FoldingRangeRegistrationOptions
///
/// executeCommandProvider?: ExecuteCommandOptions
///
/// workspaceSymbolProvider?: Boolean
///
/// workspace?: {
///
/// 	workspaceFolders?: WorkspaceFoldersServerCapabilities
/// }
///
/// experimental?: Any
struct ServerCapabilities
{

	const static String textDocumentSyncKey;

	/// Defines how text documents are synced. Is either a detailed structure
	/// defining each notification or for backwards compatibility the
	/// TextDocumentSyncKind number. If omitted it defaults to
	/// `TextDocumentSyncKind.None`.
	optional<variant<TextDocumentSyncOptions, Number>> textDocumentSync;


	const static String completionProviderKey;

	/// The server provides completion support.
	optional<CompletionOptions> completionProvider;


	const static String hoverProviderKey;

	/// The server provides hover support.
	optional<variant<Boolean, HoverOptions>> hoverProvider;


	const static String signatureHelpProviderKey;

	/// The server provides signature help support.
	optional<SignatureHelpOptions> signatureHelpProvider;


	const static String declarationProviderKey;

	/// The server provides go to declaration support.
	///
	/// @since 3.14.0
	optional<variant<Boolean,
		DeclarationOptions,
		DeclarationRegistrationOptions>> declarationProvider;


	const static String definitionProviderKey;

	/// The server provides goto definition support.
	optional<variant<Boolean, DefinitionOptions>> definitionProvider;


	const static String typeDefinitionProviderKey;

	/// The server provides goto type definition support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		TypeDefinitionOptions,
		TypeDefinitionRegistrationOptions>> typeDefinitionProvider;


	const static String implementationProviderKey;

	/// The server provides goto implementation support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		ImplementationOptions,
		ImplementationRegistrationOptions>> implementationProvider;


	const static String referencesProviderKey;

	/// The server provides find references support.
	optional<variant<Boolean, ReferenceOptions>> referencesProvider;


	const static String documentHighlightProviderKey;

	/// The server provides document highlight support.
	optional<variant<Boolean,
		DocumentHighlightOptions>> documentHighlightProvider;


	const static String documentSymbolProviderKey;

	/// The server provides document symbol support.
	optional<variant<Boolean, DocumentSymbolOptions>> documentSymbolProvider;


	const static String codeActionProviderKey;

	/// The server provides code actions. The `CodeActionOptions` return type
	/// is only valid if the client signals code action literal support via the
	/// property `textDocument.codeAction.codeActionLiteralSupport`.
	optional<variant<Boolean, CodeActionOptions>> codeActionProvider;


	const static String codeLensProviderKey;

	/// The server provides code lens.
	optional<CodeLensOptions> codeLensProvider;


	const static String documentLinkProviderKey;

	/// The server provides document link support.
	optional<DocumentLinkOptions> documentLinkProvider;


	const static String colorProviderKey;

	/// The server provides color provider support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		DocumentColorOptions,
		DocumentColorRegistrationOptions>> colorProvider;


	const static String documentFormattingProviderKey;

	/// The server provides document formatting.
	optional<variant<Boolean,
		DocumentFormattingOptions>> documentFormattingProvider;


	const static String documentRangeFormattingProviderKey;

	/// The server provides document range formatting.
	optional<variant<Boolean,
		DocumentRangeFormattingOptions>> documentRangeFormattingProvider;


	const static String documentOnTypeFormattingProviderKey;

	/// The server provides document formatting on typing.
	optional<DocumentOnTypeFormattingOptions> documentOnTypeFormattingProvider;


	const static String renameProviderKey;

	/// The server provides rename support. RenameOptions may only be
	/// specified if the client states that it supports
	/// `prepareSupport` in its initial `initialize` request.
	optional<variant<Boolean, RenameOptions>> renameProvider;


	const static String foldingRangeProviderKey;

	/// The server provides folding provider support.
	///
	/// @since 3.10.0
	optional<variant<Boolean,
		FoldingRangeOptions,
		FoldingRangeRegistrationOptions>> foldingRangeProvider;


	const static String executeCommandProviderKey;

	/// The server provides execute command support.
	optional<ExecuteCommandOptions> executeCommandProvider;


	const static String workspaceSymbolProviderKey;

	/// The server provides workspace symbol support.
	optional<Boolean> workspaceSymbolProvider;


	const static String workspaceKey;

	/// Workspace specific server capabilities
	struct Workspace
	{

		const static String workspaceFoldersKey;

		/// The server supports workspace folder.
		///
		/// @since 3.6.0
		optional<WorkspaceFoldersServerCapabilities> workspaceFolders;


		Workspace(optional<WorkspaceFoldersServerCapabilities> workspaceFolders);

		Workspace();

		virtual ~Workspace();
	};

	/// Workspace specific server capabilities
	optional<Workspace> workspace;


	const static String experimentalKey;

	/// Experimental server capabilities.
	optional<Any> experimental;


	ServerCapabilities(
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
		optional<Any> experimental);

	ServerCapabilities();

	virtual ~ServerCapabilities();
};

struct InitializedParams
{
	InitializedParams();

	virtual ~InitializedParams();
};

/// Initialization response result
///
/// capabilities: ServerCapabilities
///
/// serverInfo?: {
///
/// 	name: String
///
/// 	version?: String
/// }
///
struct InitializeResult
{

	const static String capabilitiesKey;

	/// The capabilities the language server provides.
	ServerCapabilities capabilities;


	const static String serverInfoKey;

	/// Information about the server.
	///
	/// @since 3.15.0
	struct ServerInfo
	{

		const static String nameKey;

		/// The name of the server as defined by the server.
		String name;


		const static String versionKey;

		/// The servers's version as defined by the server.
		optional<String> version;


		ServerInfo(String name, optional<String> version);

		ServerInfo();

		virtual ~ServerInfo();
	};

	/// Information about the server.
	///
	/// @since 3.15.0
	optional<ServerInfo> serverInfo;


	InitializeResult(ServerCapabilities capabilities,
		optional<ServerInfo> serverInfo);

	InitializeResult();

	virtual ~InitializeResult();
};

/// Posible error.data as a response for the initialization
///
/// retry: Boolean
///
struct InitializeError
{

	const static String retryKey;

	/// Indicates whether the client execute the following retry logic:
	/// (1) show the message provided by the ResponseError to the user
	/// (2) user selects retry or cancel
	/// (3) if user selected retry the initialize method is sent again.
	Boolean retry;


	InitializeError(Boolean retry);

	InitializeError();

	virtual ~InitializeError();
};

}
