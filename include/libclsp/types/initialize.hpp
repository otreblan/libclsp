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


namespace clsp
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
struct TextDocumentClientCapabilities: public ObjectT
{
private:
	const static String synchronizationKey;
	const static String completionKey;
	const static String hoverKey;
	const static String signatureHelpKey;
	const static String declarationKey;
	const static String definitionKey;
	const static String typeDefinitionKey;
	const static String implementationKey;
	const static String referencesKey;
	const static String documentHighlightKey;
	const static String documentSymbolKey;
	const static String codeActionKey;
	const static String codeLensKey;
	const static String documentLinkKey;
	const static String colorProviderKey;
	const static String formattingKey;
	const static String rangeFormattingKey;
	const static String onTypeFormattingKey;
	const static String renameKey;
	const static String publishDiagnosticsKey;
	const static String foldingRangeKey;

public:
	optional<TextDocumentSyncClientCapabilities> synchronization;

	/// Capabilities specific to the `textDocument/completion` request.
	optional<CompletionClientCapabilities> completion;

	/// Capabilities specific to the `textDocument/hover` request.
	optional<HoverClientCapabilities> hover;

	/// Capabilities specific to the `textDocument/signatureHelp` request.
	optional<SignatureHelpClientCapabilities> signatureHelp;

	/// Capabilities specific to the `textDocument/declaration` request.
	///
	/// @since 3.14.0
	optional<DeclarationClientCapabilities> declaration;

	/// Capabilities specific to the `textDocument/definition` request.
	optional<DefinitionClientCapabilities> definition;

	/// Capabilities specific to the `textDocument/typeDefinition` request.
	///
	/// @since 3.6.0
	optional<TypeDefinitionClientCapabilities> typeDefinition;

	/// Capabilities specific to the `textDocument/implementation` request.
	///
	/// @since 3.6.0
	optional<ImplementationClientCapabilities> implementation;

	/// Capabilities specific to the `textDocument/references` request.
	optional<ReferenceClientCapabilities> references;

	/// Capabilities specific to the `textDocument/documentHighlight` request.
	optional<DocumentHighlightClientCapabilities> documentHighlight;

	/// Capabilities specific to the `textDocument/documentSymbol` request.
	optional<DocumentSymbolClientCapabilities> documentSymbol;

	/// Capabilities specific to the `textDocument/codeAction` request.
	optional<CodeActionClientCapabilities> codeAction;

	/// Capabilities specific to the `textDocument/codeLens` request.
	optional<CodeLensClientCapabilities> codeLens;

	/// Capabilities specific to the `textDocument/documentLink` request.
	optional<DocumentLinkClientCapabilities> documentLink;

	/// Capabilities specific to the `textDocument/documentColor` and the
	/// `textDocument/colorPresentation` request.
	///
	/// @since 3.6.0
	optional<DocumentColorClientCapabilities> colorProvider;

	/// Capabilities specific to the `textDocument/formatting` request.
	optional<DocumentFormattingClientCapabilities> formatting;

	/// Capabilities specific to the `textDocument/rangeFormatting` request.
	optional<DocumentRangeFormattingClientCapabilities> rangeFormatting;

	/// Capabilities specific to the `textDocument/onTypeFormatting` request.
	optional<DocumentOnTypeFormattingClientCapabilities> onTypeFormatting;

	/// Capabilities specific to the `textDocument/rename` request.
	optional<RenameClientCapabilities> rename;

	/// Capabilities specific to the `textDocument/publishDiagnostics` notification.
	optional<PublishDiagnosticsClientCapabilities> publishDiagnostics;

	/// Capabilities specific to the `textDocument/foldingRange` request.
	///
	/// @since 3.10.0
	optional<FoldingRangeClientCapabilities> foldingRange;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


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
/// [String: key]: extra
///
struct ClientCapabilities: public ObjectT
{
private:
	const static String workspaceKey;
	const static String textDocumentKey;
	const static String experimentalKey;

public:
	/// Workspace specific client capabilities.
	struct Workspace: public ObjectT
	{
	private:
		const static String applyEditKey;
		const static String workspaceEditKey;
		const static String didChangeConfigurationKey;
		const static String didChangeWatchedFilesKey;
		const static String symbolKey;
		const static String executeCommandKey;

	public:
		/// The client supports applying batch edits
		/// to the workspace by supporting the request
		/// 'workspace/applyEdit'
		optional<Boolean> applyEdit;

		/// Capabilities specific to `WorkspaceEdit`s
		optional<WorkspaceEditClientCapabilities> workspaceEdit;

		/// Capabilities specific to the `workspace/didChangeConfiguration`
		/// notification.
		optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration;

		/// Capabilities specific to the `workspace/didChangeWatchedFiles`
		/// notification.
		optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles;

		/// Capabilities specific to the `workspace/symbol` request.
		optional<WorkspaceSymbolClientCapabilities> symbol;

		/// Capabilities specific to the `workspace/executeCommand` request.
		optional<ExecuteCommandClientCapabilities> executeCommand;


		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//


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

	/// Text document specific client capabilities.
	optional<TextDocumentClientCapabilities> textDocument;

	/// Experimental client capabilities.
	optional<Any> experimental;

	/// Extra capabilities
	map<Key, Any> extra;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	ClientCapabilities(optional<Workspace> workspace,
		optional<TextDocumentClientCapabilities> textDocument,
		optional<Any> experimental,
		map<Key, Any> extra);

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
struct InitializeParams: public WorkDoneProgressParams
{
private:
	const static String processIdKey;
	const static String clientInfoKey;
	const static String rootPathKey;
	const static String rootUriKey;
	const static String initializationOptionsKey;
	const static String capabilitiesKey;
	const static String traceKey;
	const static String workspaceFoldersKey;

	struct WorkspaceFoldersMaker: public ObjectT
	{
		vector<WorkspaceFolder> &parentArray;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		WorkspaceFoldersMaker(vector<WorkspaceFolder> &parentArray);

		virtual ~WorkspaceFoldersMaker();
	};
public:
	/// The process Id of the parent process that started
	/// the server. Is null if the process has not been started by another
	/// process.
	/// If the parent process is not alive then the server should exit
	/// (see exit notification) its process.
	variant<Number, Null> processId;

	/// Information about the client
	///
	/// @since 3.15.0
	struct ClientInfo: public ObjectT
	{
	private:
		const static String nameKey;
		const static String versionKey;

	public:
		/// The name of the client as defined by the client.
		String name;

		/// The client's version as defined by the client.
		optional<String> version;


		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//


		ClientInfo(String name, optional<String> version);

		ClientInfo();

		virtual ~ClientInfo();
	};

	/// Information about the client
	///
	/// @since 3.15.0
	optional<ClientInfo> clientInfo;

	/// The rootPath of the workspace. Is null
	/// if no folder is open.
	///
	/// @deprecated in favour of rootUri.
	[[deprecated("Deprecated in favour of rootUri")]]
	optional<variant<String, Null>> rootPath;

	/// The rootUri of the workspace. Is null if no
	/// folder is open. If both `rootPath` and `rootUri` are set
	/// `rootUri` wins.
	variant<DocumentUri, Null> rootUri;

	/// User provided initialization options.
	optional<Any> initializationOptions;

	/// The capabilities provided by the client (editor or tool)
	ClientCapabilities capabilities;

	/// The initial trace setting. If omitted trace is disabled ('off').
	optional<TraceKind> trace;

	/// The workspace folders configured in the client when the server starts.
	/// This property is only available if the client supports workspace
	/// folders.  It can be `null` if the client supports workspace folders
	/// but none are configured.
	///
	/// @since 3.6.0
	optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	InitializeParams(optional<ProgressToken> workDoneToken,
		variant<Number, Null> processId,
		optional<ClientInfo> clientInfo,
		optional<variant<String, Null>> rootPath,
		variant<DocumentUri, Null> rootUri,
		optional<Any> initializationOptions,
		ClientCapabilities capabilities,
		optional<TraceKind> trace,
		optional<variant<vector<WorkspaceFolder>, Null>> workspaceFolders);

	InitializeParams(optional<ProgressToken> workDoneToken,
		variant<Number, Null> processId,
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
private:
	const static String textDocumentSyncKey;
	const static String completionProviderKey;
	const static String hoverProviderKey;
	const static String signatureHelpProviderKey;
	const static String declarationProviderKey;
	const static String definitionProviderKey;
	const static String typeDefinitionProviderKey;
	const static String implementationProviderKey;
	const static String referencesProviderKey;
	const static String documentHighlightProviderKey;
	const static String documentSymbolProviderKey;
	const static String codeActionProviderKey;
	const static String codeLensProviderKey;
	const static String documentLinkProviderKey;
	const static String colorProviderKey;
	const static String documentFormattingProviderKey;
	const static String documentRangeFormattingProviderKey;
	const static String documentOnTypeFormattingProviderKey;
	const static String renameProviderKey;
	const static String foldingRangeProviderKey;
	const static String executeCommandProviderKey;
	const static String workspaceSymbolProviderKey;
	const static String workspaceKey;
	const static String experimentalKey;

public:
	/// Defines how text documents are synced. Is either a detailed structure
	/// defining each notification or for backwards compatibility the
	/// TextDocumentSyncKind number. If omitted it defaults to
	/// `TextDocumentSyncKind.None`.
	optional<variant<TextDocumentSyncOptions, Number>> textDocumentSync;

	/// The server provides completion support.
	optional<CompletionOptions> completionProvider;

	/// The server provides hover support.
	optional<variant<Boolean, HoverOptions>> hoverProvider;

	/// The server provides signature help support.
	optional<SignatureHelpOptions> signatureHelpProvider;

	/// The server provides go to declaration support.
	///
	/// @since 3.14.0
	optional<variant<Boolean,
		DeclarationOptions,
		DeclarationRegistrationOptions>> declarationProvider;

	/// The server provides goto definition support.
	optional<variant<Boolean, DefinitionOptions>> definitionProvider;

	/// The server provides goto type definition support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		TypeDefinitionOptions,
		TypeDefinitionRegistrationOptions>> typeDefinitionProvider;

	/// The server provides goto implementation support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		ImplementationOptions,
		ImplementationRegistrationOptions>> implementationProvider;

	/// The server provides find references support.
	optional<variant<Boolean, ReferenceOptions>> referencesProvider;

	/// The server provides document highlight support.
	optional<variant<Boolean,
		DocumentHighlightOptions>> documentHighlightProvider;

	/// The server provides document symbol support.
	optional<variant<Boolean, DocumentSymbolOptions>> documentSymbolProvider;

	/// The server provides code actions. The `CodeActionOptions` return type
	/// is only valid if the client signals code action literal support via the
	/// property `textDocument.codeAction.codeActionLiteralSupport`.
	optional<variant<Boolean, CodeActionOptions>> codeActionProvider;

	/// The server provides code lens.
	optional<CodeLensOptions> codeLensProvider;

	/// The server provides document link support.
	optional<DocumentLinkOptions> documentLinkProvider;

	/// The server provides color provider support.
	///
	/// @since 3.6.0
	optional<variant<Boolean,
		DocumentColorOptions,
		DocumentColorRegistrationOptions>> colorProvider;

	/// The server provides document formatting.
	optional<variant<Boolean,
		DocumentFormattingOptions>> documentFormattingProvider;

	/// The server provides document range formatting.
	optional<variant<Boolean,
		DocumentRangeFormattingOptions>> documentRangeFormattingProvider;

	/// The server provides document formatting on typing.
	optional<DocumentOnTypeFormattingOptions> documentOnTypeFormattingProvider;

	/// The server provides rename support. RenameOptions may only be
	/// specified if the client states that it supports
	/// `prepareSupport` in its initial `initialize` request.
	optional<variant<Boolean, RenameOptions>> renameProvider;

	/// The server provides folding provider support.
	///
	/// @since 3.10.0
	optional<variant<Boolean,
		FoldingRangeOptions,
		FoldingRangeRegistrationOptions>> foldingRangeProvider;

	/// The server provides execute command support.
	optional<ExecuteCommandOptions> executeCommandProvider;

	/// The server provides workspace symbol support.
	optional<Boolean> workspaceSymbolProvider;

	/// Workspace specific server capabilities
	struct Workspace
	{
	private:
		const static String workspaceFoldersKey;

	public:
		/// The server supports workspace folder.
		///
		/// @since 3.6.0
		optional<WorkspaceFoldersServerCapabilities> workspaceFolders;

		// No parsing

		Workspace(optional<WorkspaceFoldersServerCapabilities> workspaceFolders);

		Workspace();

		virtual ~Workspace();
	};

	/// Workspace specific server capabilities
	optional<Workspace> workspace;

	/// Experimental server capabilities.
	optional<Any> experimental;

	// No parsing

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

struct InitializedParams: public ObjectT
{


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer

	// Using default fillInitializer

	// Using default isValid()

	//=======================================================================//

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
private:
	const static String capabilitiesKey;
	const static String serverInfoKey;

public:
	/// The capabilities the language server provides.
	ServerCapabilities capabilities;

	/// Information about the server.
	///
	/// @since 3.15.0
	struct ServerInfo
	{
	private:
		const static String nameKey;
		const static String versionKey;

	public:
		/// The name of the server as defined by the server.
		String name;

		/// The server's version as defined by the server.
		optional<String> version;

		// No parsing

		ServerInfo(String name, optional<String> version);

		ServerInfo();

		virtual ~ServerInfo();
	};

	/// Information about the server.
	///
	/// @since 3.15.0
	optional<ServerInfo> serverInfo;

	// No parsing

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
private:
	const static String retryKey;

public:
	/// Indicates whether the client execute the following retry logic:
	/// (1) show the message provided by the ResponseError to the user
	/// (2) user selects retry or cancel
	/// (3) if user selected retry the initialize method is sent again.
	Boolean retry;

	// No parsing

	InitializeError(Boolean retry);

	InitializeError();

	virtual ~InitializeError();
};

}
