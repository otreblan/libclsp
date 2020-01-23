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

#include <libclsp/types/command.hpp>
#include <libclsp/types/markupContent.hpp>
#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/textEdit.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// Completion server capabilities.
///
/// triggerCharacters?: String[];
///
/// allCommitCharacters?: String[];
///
/// resolveProvider?: Boolean;
///
struct CompletionOptions: public WorkDoneProgressOptions
{

	const static String triggerCharactersKey;

	/// Most tools trigger completion request automatically without explicitly
	/// requesting it using a keyboard shortcut (e.g. Ctrl+Space).
	/// Typically they do so when the user starts to type an identifier.
	/// For example if the user types `c` in a JavaScript file code complete
	/// will automatically pop up present `console` besides others as a
	/// completion item. Characters that make up identifiers don't need
	/// to be listed here.
	///
	/// If code complete should automatically be trigger on characters not
	/// being valid inside an identifier (for example `.` in JavaScript)
	/// list them in `triggerCharacters`.
	optional<vector<String>> triggerCharacters;


	const static String allCommitCharactersKey;

	/// The list of all possible characters that commit a completion.
	/// This field can be used if clients don't support individual commit
	/// characters per completion item.
	///
	/// If a server provides both `allCommitCharacters` and commit characters
	/// on an individual completion item the ones on the completion item win.
	///
	/// @since 3.2.0
	optional<vector<String>> allCommitCharacters;


	const static String resolveProviderKey;

	/// The server provides support to resolve additional information for a
	/// completion item.
	optional<Boolean> resolveProvider;


	CompletionOptions(optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> allCommitCharacters,
		optional<Boolean> resolveProvider);

	CompletionOptions();

	virtual ~CompletionOptions();
};

struct CompletionRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public CompletionOptions
{

	CompletionRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> allCommitCharacters,
		optional<Boolean> resolveProvider);

	CompletionRegistrationOptions();

	virtual ~CompletionRegistrationOptions();
};

/// How a completion was triggered
enum class CompletionTriggerKind
{
	/// Completion was triggered by typing an identifier (24x7 code
	/// complete), manual invocation (e.g Ctrl+Space) or via API.
	Invoked = 1,

	/// Completion was triggered by a trigger character specified by
	/// the `triggerCharacters` properties of the
	/// `CompletionRegistrationOptions`.
	TriggerCharacter = 2,

	/// Completion was re-triggered as the current completion list is
	/// incomplete.
	TriggerForIncompleteCompletions = 3
};

/// Contains additional information about the context in which a completion
/// request is triggered.
///
/// triggerKind: CompletionTriggerKind
///
/// triggerCharacter?: String
///
struct CompletionContext
{

	const static String triggerKindKey;

	/// How the completion was triggered.
	CompletionTriggerKind triggerKind;


	const static String triggerCharacterKey;

	/// The trigger character (a single character) that has trigger code
	/// complete. Is undefined if
	/// `triggerKind != CompletionTriggerKind.TriggerCharacter`
	optional<String> triggerCharacter;


	CompletionContext(CompletionTriggerKind triggerKind,
		optional<String> triggerCharacter);

	CompletionContext();

	virtual ~CompletionContext();
};

/// Completion request parameters
///
/// context?: CompletionContext
///
struct CompletionParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{

	// FIXME:
	// Even if the struct is not parseable this functions must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String contextKey;

	/// The completion context. This is only available if the client specifies
	/// to send this using
	/// `ClientCapabilities.textDocument.completion.contextSupport == true`
	optional<CompletionContext> context;


	CompletionParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		optional<CompletionContext> context);

	CompletionParams();


	virtual ~CompletionParams();
};

/// Defines whether the insert text in a completion item should be interpreted
/// as plain text or a snippet.
enum class InsertTextFormat
{
	/// The primary text to be inserted is treated as a plain string.
	PlainText = 1,

	/// The primary text to be inserted is treated as a snippet.
	///
	/// A snippet can define tab stops and placeholders with `$1`, `$2`
	/// and `${3:foo}`. `$0` defines the final tab stop, it defaults to
	/// the end of the snippet. Placeholders with equal identifiers are linked,
	/// that is typing in one will update others too.
	Snippet = 2
};

/// Completion item tags are extra annotations that tweak the rendering of
/// a completion item.
///
/// @since 3.15.0
enum class CompletionItemTag
{
	/// Render a completion as obsolete, usually using a strike-out.
	Deprecated = 1
};

/// The kind of a completion entry.
enum class CompletionItemKind
{
	Text          = 1,
	Method        = 2,
	Function      = 3,
	Constructor   = 4,
	Field         = 5,
	Variable      = 6,
	Class         = 7,
	Interface     = 8,
	Module        = 9,
	Property      = 10,
	Unit          = 11,
	Value         = 12,
	Enum          = 13,
	Keyword       = 14,
	Snippet       = 15,
	Color         = 16,
	File          = 17,
	Reference     = 18,
	Folder        = 19,
	EnumMember    = 20,
	Constant      = 21,
	Struct        = 22,
	Event         = 23,
	Operator      = 24,
	TypeParameter = 25
};

/// Part of the completion response
///
/// label: string;
///
/// kind?: Number;
///
/// tags?: CompletionItemTag[];
///
/// detail?: String;
///
/// documentation?: String | MarkupContent;
///
/// deprecated?: Boolean;
///
/// preselect?: Boolean;
///
/// sortText?: String;
///
/// filterText?: String;
///
/// insertText?: String;
///
/// insertTextFormat?: InsertTextFormat;
///
/// textEdit?: TextEdit;
///
/// additionalTextEdits?: TextEdit[];
///
/// commitCharacters?: String[];
///
/// command?: Command;
///
/// data?: Any
///
struct CompletionItem
{

	const static String labelKey;

	/// The label of this completion item. By default
	/// also the text that is inserted when selecting
	/// this completion.
	String label;


	const static String kindKey;

	/// The kind of this completion item. Based of the kind
	/// an icon is chosen by the editor. The standardized set
	/// of available values is defined in `CompletionItemKind`.
	optional<CompletionItemKind> kind;


	const static String tagsKey;

	/// Tags for this completion item.
	///
	/// @since 3.15.0
	optional<vector<CompletionItemTag>> tags;


	const static String detailKey;

	/// A human-readable string with additional information
	/// about this item, like type or symbol information.
	optional<String> detail;


	const static String documentationKey;

	/// A human-readable string that represents a doc-comment.
	optional<variant<String, MarkupContent>> documentation;


	const static String deprecatedKey;

	/// Indicates if this item is deprecated.
	optional<Boolean> deprecated;


	const static String preselectKey;

	/// Select this item when showing.
	///
	/// *Note* that only one completion item can be selected and that the
	/// tool / client decides which item that is. The rule is that the *first*
	/// item of those that match best is selected.
	optional<Boolean> preselect;


	const static String sortTextKey;

	/// A string that should be used when comparing this item
	/// with other items. When `falsy` the label is used.
	optional<String> sortText;


	const static String filterTextKey;

	/// A string that should be used when filtering a set of
	/// completion items. When `falsy` the label is used.
	optional<String> filterText;


	const static String insertTextKey;

	/// A string that should be inserted into a document when selecting
	/// this completion. When `falsy` the label is used.
	///
	/// The `insertText` is subject to interpretation by the client side.
	/// Some tools might not take the string literally. For example
	/// VS Code when code complete is requested in this example
	/// `con<cursor position>` and a completion item with an `insertText` of
	/// console` is provided it will only insert `sole`.
	/// Therefore it is recommended to use `textEdit` instead since it avoids
	/// additional client side interpretation.
	optional<String> insertText;


	const static String insertTextFormatKey;

	/// The format of the insert text. The format applies to both the
	/// `insertText` property and the `newText` property of a provided
	/// `textEdit`. If omitted defaults to `InsertTextFormat.PlainText`.
	optional<InsertTextFormat> insertTextFormat;


	const static String textEditKey;

	/// An edit which is applied to a document when selecting this completion.
	/// When an edit is provided the value of `insertText` is ignored.
	///
	/// *Note:* The range of the edit must be a single line range and it must
	/// contain the position at which completion has been requested.
	optional<TextEdit> textEdit;


	const static String additionalTextEditsKey;

	/// An optional array of additional text edits that are applied when
	/// selecting this completion. Edits must not overlap (including the same
	/// insert position) with the main edit nor with themselves.
	///
	/// Additional text edits should be used to change text unrelated to the
	/// current cursor position (for example adding an import statement at the
	/// top of the file if the completion item will insert an unqualified type).
	optional<vector<TextEdit>> additionalTextEdits;


	const static String commitCharactersKey;

	/// An optional set of characters that when pressed while this completion
	/// is active will accept it first and then type that character.
	/// *Note* that all commit characters should have `length=1` and that
	/// superfluous characters will be ignored.
	optional<vector<String>> commitCharacters;


	const static String commandKey;

	/// An optional command that is executed *after* inserting this completion.
	/// *Note* that additional modifications to the current document should
	/// be described with the additionalTextEdits-property.
	optional<Command> command;


	const static String dataKey;

	/// A data entry field that is preserved on a completion item between
	/// a completion and a completion resolve request.
	optional<Any> data;


	CompletionItem(String label,
		optional<CompletionItemKind> kind,
		optional<vector<CompletionItemTag>> tags,
		optional<String> detail,
		optional<variant<String, MarkupContent>> documentation,
		optional<Boolean> deprecated,
		optional<Boolean> preselect,
		optional<String> sortText,
		optional<String> filterText,
		optional<String> insertText,
		optional<InsertTextFormat> insertTextFormat,
		optional<TextEdit> textEdit,
		optional<vector<TextEdit>> additionalTextEdits,
		optional<vector<String>> commitCharacters,
		optional<Command> command,
		optional<Any> data);

	CompletionItem();

	virtual ~CompletionItem();
};

/// Represents a collection of [completion items](#CompletionItem) to be presented
/// in the editor.
///
/// isIncomplete: boolean;
///
/// items: CompletionItem[];
///
struct CompletionList
{

	const static String isIncompleteKey;

	/// This list it not complete. Further typing should result in recomputing
	/// this list.
	Boolean isIncomplete;


	const static String itemsKey;

	/// The completion items.
	vector<CompletionItem> items;


	CompletionList(Boolean isIncomplete, vector<CompletionItem> items);

	CompletionList();

	virtual ~CompletionList();
};

/// Completion client capabilities
///
/// dynamicRegistration?: Boolean
///
/// completionItem?: {
///
/// 	snippetSupport?: Boolean
///
/// 	commitCharactersSupport?: Boolean
///
/// 	documentationFormat?: MarkupKind[]
///
/// 	deprecatedSupport?: Boolean
///
/// 	preselectSupport?: Boolean
///
/// 	tagSupport?: {
///
/// 		valueSet: CompletionItemTag[]
/// 	}
/// }
///
/// completionItemKind?: {
///
/// 	valueSet?: CompletionItemKind[]
/// }
///
/// contextSupport?: Boolean
///
struct CompletionClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether completion supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	const static String completionItemKey;

	/// The client supports the following `CompletionItem` specific
	/// capabilities.
	struct CompletionItem
	{

		const static String snippetSupportKey;

		/// Client supports snippets as insert text.
		///
		/// A snippet can define tab stops and placeholders with `$1`, `$2`
		/// and `${3:foo}`. `$0` defines the final tab stop, it defaults to
		/// the end of the snippet. Placeholders with equal identifiers are
		/// linked, that is typing in one will update others too.
		optional<Boolean> snippetSupport;


		const static String commitCharactersSupportKey;

		/// Client supports commit characters on a completion item.
		optional<Boolean> commitCharactersSupport;


		const static String documentationFormatKey;

		/// Client supports the follow content formats for the documentation
		/// property. The order describes the preferred format of the client.
		optional<vector<MarkupKind>> documentationFormat;


		const static String deprecatedSupportKey;

		/// Client supports the deprecated property on a completion item.
		optional<Boolean> deprecatedSupport;


		const static String preselectSupportKey;

		/// Client supports the preselect property on a completion item.
		optional<Boolean> preselectSupport;


		const static String tagSupportKey;

		/// Client supports the tag property on a completion item. Clients
		/// supporting tags have to handle unknown tags gracefully. Clients
		/// especially need to preserve unknown tags when sending a completion
		/// item back to the server in a resolve call.
		///
		/// #since 3.15.0
		struct TagSupport
		{

			const static String valueSetKey;

			/// The tags supported by the client.
			vector<CompletionItemTag> valueSet;


			TagSupport(vector<CompletionItemTag> valueSet);

			TagSupport();

			virtual ~TagSupport();
		};

		/// Client supports the tag property on a completion item. Clients
		/// supporting tags have to handle unknown tags gracefully. Clients
		/// especially need to preserve unknown tags when sending a completion
		/// item back to the server in a resolve call.
		///
		/// #since 3.15.0
		optional<TagSupport> tagSupport;

		CompletionItem(optional<Boolean> snippetSupport,
			optional<Boolean> commitCharactersSupport,
			optional<vector<MarkupKind>> documentationFormat,
			optional<Boolean> deprecatedSupport,
			optional<Boolean> preselectSupport,
			optional<TagSupport> tagSupport);

		CompletionItem();

		virtual ~CompletionItem();
	};

	/// The client supports the following `CompletionItem` specific
	/// capabilities.
	optional<CompletionItem> completionItem;


	const static String completionItemKindKey;

	struct CompletionItemKind
	{

		const static String valueSetKey;

		/// The completion item kind values the client supports. When this
		/// property exists the client also guarantees that it will
		/// handle values outside its set gracefully and falls back
		/// to a default value when unknown.
		///
		/// If this property is not present the client only supports
		/// the completion items kinds from `Text` to `Reference` as defined
		/// in the initial version of the protocol.
		optional<vector<clsp::CompletionItemKind>> valueSet;


		CompletionItemKind(optional<vector<clsp::CompletionItemKind>> valueSet);

		CompletionItemKind();

		virtual ~CompletionItemKind();
	};

	optional<CompletionItemKind> completionItemKind;


	const static String contextSupportKey;

	/// The client supports to send additional context information for a
	/// `textDocument/completion` request.
	optional<Boolean> contextSupport;


	CompletionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<CompletionItem> completionItem,
		optional<CompletionItemKind> completionItemKind,
		optional<Boolean> contextSupport);

	CompletionClientCapabilities();

	virtual ~CompletionClientCapabilities();
};

}
