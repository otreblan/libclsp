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

#include <libclsp/types/completion.hpp>

namespace clsp
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

CompletionOptions::CompletionOptions(){};
CompletionOptions::~CompletionOptions(){};

void CompletionOptions::partialWrite(JsonWriter &writer)
{
	// Parent
	WorkDoneProgressOptions::partialWrite(writer);

	// triggerCharacters?
	if(triggerCharacters.has_value())
	{
		writer.Key(triggerCharactersKey);
		writer.StartArray();
		for(auto& i: *triggerCharacters)
		{
			writer.String(i);
		}
		writer.EndArray();
	}

	// allCommitCharacters?
	if(allCommitCharacters.has_value())
	{
		writer.Key(allCommitCharactersKey);
		writer.StartArray();
		for(auto& i: *allCommitCharacters)
		{
			writer.String(i);
		}
		writer.EndArray();
	}

	// resolveProvider?
	if(resolveProvider.has_value())
	{
		writer.Key(resolveProviderKey);
		writer.Bool(*resolveProvider);
	}
}


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

CompletionRegistrationOptions::CompletionRegistrationOptions(){};
CompletionRegistrationOptions::~CompletionRegistrationOptions(){};

void CompletionRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parents
	TextDocumentRegistrationOptions::partialWrite(writer);
	CompletionOptions::partialWrite(writer);
}


const String CompletionContext::triggerKindKey      = "triggerKind";
const String CompletionContext::triggerCharacterKey = "triggerCharacter";

CompletionContext::CompletionContext(CompletionTriggerKind triggerKind,
	optional<String> triggerCharacter):
		triggerKind(triggerKind),
		triggerCharacter(triggerCharacter)
{};

CompletionContext::CompletionContext(){};
CompletionContext::~CompletionContext(){};

void CompletionContext::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// triggerKind:
	setterMap.emplace(
		triggerKindKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				if(holds_alternative<int>(n))
				{
					int i = get<int>(n);

					triggerKind = (CompletionTriggerKind)i;

					neededMap[triggerKindKey] = true;
				}
				else
				{
					// TODO
					// Exception or something
				}
			},

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

	// triggerCharacter?:
	setterMap.emplace(
		triggerCharacterKey,
		ValueSetter{
			// String
			[this](String str)
			{
				triggerCharacter = str;
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
	neededMap.emplace(triggerKindKey, 0);

	// This
	initializer.object = this;
}

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

CompletionParams::CompletionParams(){};
CompletionParams::~CompletionParams(){};


void CompletionParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);

	// Value setters

	// context?:
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
			[this, handler]()
			{
				context.emplace();

				handler->pushInitializer();
				context->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// This
	initializer.object = this;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

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

CompletionItem::CompletionItem(){};
CompletionItem::~CompletionItem(){};

void CompletionItem::partialWrite(JsonWriter &writer)
{
	// label
	writer.Key(labelKey);
	writer.String(label);

	// kind?
	if(kind.has_value())
	{
		writer.Key(kindKey);
		writer.Int((int)(*kind));
	}

	// tags?
	if(tags.has_value())
	{
		writer.Key(tagsKey);
		writer.StartArray();
		for(auto i: *tags)
		{
			writer.Int((int)i);
		}
		writer.EndArray();
	}

	// detail?
	if(detail.has_value())
	{
		writer.Key(detailKey);
		writer.String(*detail);
	}

	// documentation?
	if(documentation.has_value())
	{
		writer.Key(documentationKey);
		visit(overload(
			[&writer](String& str)
			{
				writer.String(str);
			},
			[&writer](MarkupContent& obj)
			{
				writer.Object(obj);
			}
		), *documentation);
	}

	// deprecated?
	if(deprecated.has_value())
	{
		writer.Key(deprecatedKey);
		writer.Bool(*deprecated);
	}

	// preselect?
	if(preselect.has_value())
	{
		writer.Key(preselectKey);
		writer.Bool(*preselect);
	}

	// sortText?
	if(sortText.has_value())
	{
		writer.Key(sortTextKey);
		writer.String(*sortText);
	}

	// filterText?
	if(filterText.has_value())
	{
		writer.Key(filterTextKey);
		writer.String(*filterText);
	}

	// insertText?
	if(insertText.has_value())
	{
		writer.Key(insertTextKey);
		writer.String(*insertText);
	}

	// insertTextFormat?
	if(insertTextFormat.has_value())
	{
		writer.Key(insertTextFormatKey);
		writer.Int((int)(*insertTextFormat));
	}

	// textEdit?
	if(textEdit.has_value())
	{
		writer.Key(textEditKey);
		writer.Object(*textEdit);
	}

	// additionalTextEdits?
	if(additionalTextEdits.has_value())
	{
		writer.Key(additionalTextEditsKey);
		writer.StartArray();
		for(auto i: *additionalTextEdits)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}

	// commitCharacters?
	if(commitCharacters.has_value())
	{
		writer.Key(commitCharactersKey);
		writer.StartArray();
		for(auto i: *commitCharacters)
		{
			writer.String(i);
		}
		writer.EndArray();
	}

	// command?
	if(command.has_value())
	{
		writer.Key(commandKey);
		writer.Object(*command);
	}

	// data?
	if(data.has_value())
	{
		writer.Key(dataKey);
		writer.Any(*data);
	}
}

#pragma GCC diagnostic pop


const String CompletionList::isIncompleteKey = "isIncomplete";
const String CompletionList::itemsKey        = "items";

CompletionList::CompletionList(Boolean isIncomplete,
	vector<CompletionItem> items):
		isIncomplete(isIncomplete),
		items(items)
{};

CompletionList::CompletionList(){};
CompletionList::~CompletionList(){};

void CompletionList::partialWrite(JsonWriter &writer)
{
	// isIncomplete
	writer.Key(isIncompleteKey);
	writer.Bool(isIncomplete);

	// items
	writer.Key(itemsKey);
	writer.StartArray();
	for(auto& i: items)
	{
		writer.Object(i);
	}
	writer.EndArray();
}

const String CompletionClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String CompletionClientCapabilities::
	completionItemKey      = "completionItem";

const String CompletionClientCapabilities::
	completionItemKindKey  = "completionItemKind";

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

CompletionClientCapabilities::CompletionClientCapabilities(){};
CompletionClientCapabilities::~CompletionClientCapabilities(){};

void CompletionClientCapabilities::fillInitializer(ObjectInitializer& initializer)
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

	// completionItem?:
	setterMap.emplace(
		completionItemKey,
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
				completionItem.emplace();

				handler->pushInitializer();
				completionItem->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// completionItemKind?:
	setterMap.emplace(
		completionItemKindKey,
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
				completionItemKind.emplace();

				handler->pushInitializer();
				completionItemKind->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// contextSupport?:
	setterMap.emplace(
		contextSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				contextSupport = b;
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

CompletionClientCapabilities::CompletionItem::CompletionItem(){};
CompletionClientCapabilities::CompletionItem::~CompletionItem(){};


void CompletionClientCapabilities::CompletionItem::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// snippetSupport?:
	setterMap.emplace(
		snippetSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				snippetSupport = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// commitCharactersSupport?:
	setterMap.emplace(
		commitCharactersSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				commitCharactersSupport = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// documentationFormat?:
	setterMap.emplace(
		documentationFormatKey,
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
				documentationFormat.emplace();

				handler->pushInitializer();

				auto* maker = new DocumentationFormatMaker(documentationFormat.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);

	// deprecatedSupport?:
	setterMap.emplace(
		deprecatedSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				deprecatedSupport = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// preselectSupport?:
	setterMap.emplace(
		preselectSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				preselectSupport = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// tagSupport?:
	setterMap.emplace(
		tagSupportKey,
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
				tagSupport.emplace();

				handler->pushInitializer();
				tagSupport->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// This
	initializer.object = this;
}


CompletionClientCapabilities::CompletionItem::DocumentationFormatMaker::
	DocumentationFormatMaker(vector<MarkupKind> &parentArray):
		parentArray(parentArray)
{};

CompletionClientCapabilities::CompletionItem::DocumentationFormatMaker::
	~DocumentationFormatMaker()
{};

void CompletionClientCapabilities::CompletionItem::DocumentationFormatMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// MarkupKind[]
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


const string CompletionClientCapabilities::CompletionItem::TagSupport::
	valueSetKey = "valueSet";

CompletionClientCapabilities::CompletionItem::TagSupport::
	TagSupport(vector<CompletionItemTag> valueSet):
		valueSet(valueSet)
{};

CompletionClientCapabilities::CompletionItem::TagSupport::TagSupport(){};
CompletionClientCapabilities::CompletionItem::TagSupport::~TagSupport(){};

void CompletionClientCapabilities::CompletionItem::TagSupport::
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


	// This
	initializer.object = this;
}


CompletionClientCapabilities::CompletionItem::TagSupport::ValueSetMaker::
	ValueSetMaker(vector<CompletionItemTag> &parentArray):
		parentArray(parentArray)
{};

CompletionClientCapabilities::CompletionItem::TagSupport::ValueSetMaker::
	~ValueSetMaker()
{};

void CompletionClientCapabilities::CompletionItem::TagSupport::ValueSetMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// CompletionItemTag[]
	extraSetter =
	{
		// String
		nullopt,

		// Number
		[this](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				parentArray.emplace_back((CompletionItemTag)i);
			}
			else
			{
				// TODO
				// An exception or something
			}
		},

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

const String CompletionClientCapabilities::CompletionItemKind::
	valueSetKey = "valueSet";

CompletionClientCapabilities::CompletionItemKind::
	CompletionItemKind(optional<vector<clsp::CompletionItemKind>> valueSet):
		valueSet(valueSet)
{};

CompletionClientCapabilities::CompletionItemKind::CompletionItemKind(){};
CompletionClientCapabilities::CompletionItemKind::~CompletionItemKind(){};

void CompletionClientCapabilities::CompletionItemKind::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

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
			[this, handler]()
			{
				valueSet.emplace();

				handler->pushInitializer();

				auto* maker = new ValueSetMaker(valueSet.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			nullopt
		}
	);


	// This
	initializer.object = this;
}

CompletionClientCapabilities::CompletionItemKind::ValueSetMaker::
	ValueSetMaker(vector<clsp::CompletionItemKind> &parentArray):
		parentArray(parentArray)
{};

CompletionClientCapabilities::CompletionItemKind::ValueSetMaker::
	~ValueSetMaker()
{};

void CompletionClientCapabilities::CompletionItemKind::ValueSetMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// CompletionItemKind[]
	extraSetter =
	{
		// String
		nullopt,

		// Number
		[this](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				parentArray.emplace_back((clsp::CompletionItemKind)i);
			}
			else
			{
				// TODO
				// An exception or something
			}
		},

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

}
