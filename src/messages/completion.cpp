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

#include <libclsp/messages/completion.hpp>

namespace libclsp
{

using namespace std;

const String CompletionOptions::triggerCharactersKey   = "triggerCharacters";
const String CompletionOptions::allCommitCharactersKey = "allCommitCharacters";
const String CompletionOptions::resolveProviderKey     = "resolveProvider";

CompletionOptions::CompletionOptions(optional<ProgressToken> workDoneProgress,
	optional<vector<String>> triggerCharacters,
	optional<vector<String>> allCommitCharacters,
	optional<Boolean> resolveProvider):
		WorkDoneProgressOptions(workDoneProgress),
		triggerCharacters(triggerCharacters),
		allCommitCharacters(allCommitCharacters),
		resolveProvider(resolveProvider)
{};

CompletionOptions::CompletionOptions():
	WorkDoneProgressOptions(),
	triggerCharacters(),
	allCommitCharacters(),
	resolveProvider()
{};

CompletionOptions::~CompletionOptions(){};


CompletionRegistrationOptions::
	CompletionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> allCommitCharacters,
		optional<Boolean> resolveProvider):
			TextDocumentRegistrationOptions(documentSelector),
			CompletionOptions(workDoneProgress,
				triggerCharacters,
				allCommitCharacters,
				resolveProvider)
{};

CompletionRegistrationOptions::CompletionRegistrationOptions():
	TextDocumentRegistrationOptions(),
	CompletionOptions()
{};

CompletionRegistrationOptions::~CompletionRegistrationOptions(){};


const String CompletionContext::triggerKindKey      = "triggerKind";
const String CompletionContext::triggerCharacterKey = "triggerCharacter";

CompletionContext::CompletionContext(CompletionTriggerKind triggerKind,
	optional<String> triggerCharacter):
		triggerKind(triggerKind),
		triggerCharacter(triggerCharacter)
{};

CompletionContext::CompletionContext():
	triggerKind(),
	triggerCharacter()
{};

CompletionContext::~CompletionContext(){};


const String CompletionParams::contextKey = "context";

CompletionParams::CompletionParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	optional<CompletionContext> context):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		context(context)
{};

CompletionParams::CompletionParams():
	TextDocumentPositionParams(),
	WorkDoneProgressParams(),
	PartialResultParams(),
	context()
{};

CompletionParams::~CompletionParams(){};


const String CompletionItem::labelKey               = "label";
const String CompletionItem::kindKey                = "kind";
const String CompletionItem::tagsKey                = "tags";
const String CompletionItem::detailKey              = "detail";
const String CompletionItem::documentationKey       = "documentation";
const String CompletionItem::deprecatedKey          = "deprecated";
const String CompletionItem::preselectKey           = "preselect";
const String CompletionItem::sortTextKey            = "sortText";
const String CompletionItem::filterTextKey          = "filterText";
const String CompletionItem::insertTextKey          = "insertText";
const String CompletionItem::insertTextFormatKey    = "insertTextFormat";
const String CompletionItem::textEditKey            = "textEdit";
const String CompletionItem::additionalTextEditsKey = "additionalTextEdits";
const String CompletionItem::commitCharactersKey    = "commitCharacters";
const String CompletionItem::commandKey             = "command";
const String CompletionItem::dataKey                = "data";

CompletionItem::CompletionItem(String label,
	optional<CompletionItemKind> kind,
	optional<vector<CompletionItemTag>> tags,
	optional<String> detail,
	optional<variant<String,MarkupContent>> documentation,
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
	optional<Any> data):
		label(label),
		kind(kind),
		tags(tags),
		detail(detail),
		documentation(documentation),
		deprecated(deprecated),
		preselect(preselect),
		sortText(sortText),
		filterText(filterText),
		insertText(insertText),
		insertTextFormat(insertTextFormat),
		textEdit(textEdit),
		additionalTextEdits(additionalTextEdits),
		commitCharacters(commitCharacters),
		command(command),
		data(data)
{};

CompletionItem::CompletionItem():
	label(),
	kind(),
	tags(),
	detail(),
	documentation(),
	deprecated(),
	preselect(),
	sortText(),
	filterText(),
	insertText(),
	insertTextFormat(),
	textEdit(),
	additionalTextEdits(),
	commitCharacters(),
	command(),
	data()
{};

CompletionItem::~CompletionItem(){};


const String CompletionList::isIncompleteKey = "isIncomplete";
const String CompletionList::itemsKey        = "items";

CompletionList::CompletionList(Boolean isIncomplete,
	vector<CompletionItem> items):
		isIncomplete(isIncomplete),
		items(items)
{};

CompletionList::CompletionList():
	isIncomplete(),
	items()
{};

CompletionList::~CompletionList(){};


const String CompletionClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String CompletionClientCapabilities::
	completionItemKey      = "completionItem";

const String CompletionClientCapabilities::
	completionItemKindKey  = "completionItemKey";

const String CompletionClientCapabilities::
	contextSupportKey      = "contextSupport";

CompletionClientCapabilities::
	CompletionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<CompletionItem> completionItem,
		optional<CompletionItemKind> completionItemKind,
		optional<Boolean> contextSupport):
			dynamicRegistration(dynamicRegistration),
			completionItem(completionItem),
			completionItemKind(completionItemKind),
			contextSupport(contextSupport)
{};

CompletionClientCapabilities::CompletionClientCapabilities():
	dynamicRegistration(),
	completionItem(),
	completionItemKind(),
	contextSupport()
{};

CompletionClientCapabilities::~CompletionClientCapabilities(){};


const String CompletionClientCapabilities::CompletionItem::
	snippetSupportKey          = "snippetSupport";

const String CompletionClientCapabilities::CompletionItem::
	commitCharactersSupportKey = "commitCharactersSupport";

const String CompletionClientCapabilities::CompletionItem::
	documentationFormatKey     = "documentationFormat";

const String CompletionClientCapabilities::CompletionItem::
	deprecatedSupportKey       = "deprecatedSupport";

const String CompletionClientCapabilities::CompletionItem::
	preselectSupportKey        = "preselectSupport";

const String CompletionClientCapabilities::CompletionItem::
	tagSupportKey              = "tagSupport";

CompletionClientCapabilities::CompletionItem::
	CompletionItem(optional<Boolean> snippetSupport,
		optional<Boolean> commitCharactersSupport,
		optional<vector<MarkupKind>> documentationFormat,
		optional<Boolean> deprecatedSupport,
		optional<Boolean> preselectSupport,
		optional<TagSupport> tagSupport):
			snippetSupport(snippetSupport),
			commitCharactersSupport(commitCharactersSupport),
			documentationFormat(documentationFormat),
			deprecatedSupport(deprecatedSupport),
			preselectSupport(preselectSupport),
			tagSupport(tagSupport)
{};

CompletionClientCapabilities::CompletionItem::CompletionItem():
	snippetSupport(),
	commitCharactersSupport(),
	documentationFormat(),
	deprecatedSupport(),
	preselectSupport(),
	tagSupport()
{};

CompletionClientCapabilities::CompletionItem::~CompletionItem(){};



const string CompletionClientCapabilities::CompletionItem::TagSupport::
	valueSetKey = "valueSet";

CompletionClientCapabilities::CompletionItem::TagSupport::
	TagSupport(vector<CompletionItemTag> valueSet):
		valueSet(valueSet)
{};

CompletionClientCapabilities::CompletionItem::TagSupport::TagSupport():
	valueSet()
{};

CompletionClientCapabilities::CompletionItem::TagSupport::~TagSupport(){};


const String CompletionClientCapabilities::CompletionItemKind::
	valueSetKey = "valueSet";

CompletionClientCapabilities::CompletionItemKind::
	CompletionItemKind(optional<vector<libclsp::CompletionItemKind>> valueSet):
		valueSet(valueSet)
{};

CompletionClientCapabilities::CompletionItemKind::CompletionItemKind():
	valueSet()
{};

CompletionClientCapabilities::CompletionItemKind::~CompletionItemKind(){};

}
