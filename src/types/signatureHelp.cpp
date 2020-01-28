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

SignatureHelpClientCapabilities::SignatureHelpClientCapabilities(){};
SignatureHelpClientCapabilities::~SignatureHelpClientCapabilities(){};


void SignatureHelpClientCapabilities::
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
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// signatureInformation?:
	setterMap.emplace(
		signatureInformationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				signatureInformation.emplace();

				handler->pushInitializer();
				signatureInformation->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// contextSupport?:
	setterMap.emplace(
		contextSupportKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				contextSupport = b;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// This
	initializer.object = this;
}

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

SignatureHelpClientCapabilities::SignatureInformation::SignatureInformation(){};
SignatureHelpClientCapabilities::SignatureInformation::
	~SignatureInformation()
{};

void SignatureHelpClientCapabilities::SignatureInformation::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// documentationFormat?:
	setterMap.emplace(
		documentationFormatKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{
				documentationFormat.emplace();

				handler->pushInitializer();

				auto* maker = new DocumentationFormatMaker(*documentationFormat);

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{}
		}
	);

	// parameterInformation?:
	setterMap.emplace(
		parameterInformationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				parameterInformation.emplace();

				handler->pushInitializer();
				parameterInformation->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// This
	initializer.object = this;
}


SignatureHelpClientCapabilities::
	SignatureInformation::
	DocumentationFormatMaker::
		DocumentationFormatMaker(vector<MarkupKind> &parentArray):
			parentArray(parentArray)
{};

SignatureHelpClientCapabilities::
	SignatureInformation::
	DocumentationFormatMaker::
		~DocumentationFormatMaker()
{};

void SignatureHelpClientCapabilities::
	SignatureInformation::
	DocumentationFormatMaker::
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
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		{}
	};

	// This
	initializer.object = this;
}

const String SignatureHelpClientCapabilities::
	SignatureInformation::
	ParameterInformation::
		labelOffsetSupportKey = "labelOffsetSupport";

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	ParameterInformation(optional<Boolean> labelOffsetSupport):
		labelOffsetSupport(labelOffsetSupport)
{};

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	ParameterInformation()
{};

SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
	~ParameterInformation()
{};

void SignatureHelpClientCapabilities::
	SignatureInformation::
	ParameterInformation::
		fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// labelOffsetSupport?:
	setterMap.emplace(
		labelOffsetSupportKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				labelOffsetSupport = b;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// This
	initializer.object = this;
}


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

SignatureHelpOptions::SignatureHelpOptions(){};
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

SignatureHelpRegistrationOptions::SignatureHelpRegistrationOptions(){};
SignatureHelpRegistrationOptions::~SignatureHelpRegistrationOptions(){};


const String ParameterInformation::labelKey         = "label";
const String ParameterInformation::documentationKey = "documentation";

ParameterInformation::
	ParameterInformation(variant<String, array<Number, 2>> label,
		optional<variant<String, MarkupContent>> documentation):
			label(label),
			documentation(documentation)
{};

ParameterInformation::ParameterInformation(){};
ParameterInformation::~ParameterInformation(){};

void ParameterInformation::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// label:
	setterMap.emplace(
		labelKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				label = str;
				neededMap[labelKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler, &neededMap]()
			{
				auto& arr = label.emplace<array<Number, 2>>();

				handler->pushInitializer();

				auto* maker = new LabelMaker(arr);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[labelKey] = true;
			},

			// Object
			{}
		}
	);

	// documentation?:
	setterMap.emplace(
		documentationKey,
		ValueSetter{
			// String
			[this](String str)
			{
				documentation = str;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				auto& obj = documentation.emplace().emplace<MarkupContent>();

				handler->pushInitializer();
				obj.fillInitializer(handler->objectStack.top());
			}
		}
	);

	// Needed members
	neededMap.emplace(labelKey, 0);

	// This
	initializer.object = this;
}

ParameterInformation::LabelMaker::LabelMaker(array<Number, 2> &parentArray):
	parentArray(parentArray)
{};

ParameterInformation::LabelMaker::
	~LabelMaker()
{};

void ParameterInformation::LabelMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// [Number, Number]
	extraSetter =
	{
		// String
		{},

		// Number
		[this](Number n)
		{
			parentArray.at(index++) = n;
		},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		{}
	};

	// This
	initializer.object = this;
}


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

SignatureInformation::SignatureInformation(){};
SignatureInformation::~SignatureInformation(){};

void SignatureInformation::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// label:
	setterMap.emplace(
		labelKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				label = str;
				neededMap[labelKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// documentation?:
	setterMap.emplace(
		documentationKey,
		ValueSetter{
			// String
			[this](String str)
			{
				documentation = str;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				documentation = MarkupContent();

				handler->pushInitializer();

				get<MarkupContent>(documentation.value()).
					fillInitializer(handler->objectStack.top());
			}
		}
	);

	// parameters?:
	setterMap.emplace(
		parametersKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{
				parameters.emplace();

				handler->pushInitializer();

				auto* maker = new ParametersMaker(parameters.value());

				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{},
		}
	);

	// Needed members
	neededMap.emplace(labelKey, 0);

	// This
	initializer.object = this;
}

SignatureInformation::ParametersMaker::
	ParametersMaker(vector<ParameterInformation> &parentArray):
		parentArray(parentArray)
{};

SignatureInformation::ParametersMaker::
	~ParametersMaker()
{};


void SignatureInformation::ParametersMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// ParameterInformation[]
	extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

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

SignatureHelp::SignatureHelp(){};
SignatureHelp::~SignatureHelp(){};

void SignatureHelp::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// signatures:
	setterMap.emplace(
		signaturesKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();

				auto* maker = new SignaturesMaker(signatures);

				maker->fillInitializer(handler->objectStack.top());

				neededMap[signaturesKey] = true;
			},

			// Object
			{}
		}
	);

	// activeSignature?:
	setterMap.emplace(
		activeSignatureKey,
		ValueSetter{
			// String
			{},

			// Number
			[this](Number n)
			{
				activeSignature = n;
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// activeParameter?:
	setterMap.emplace(
		activeParameterKey,
		ValueSetter{
			// String
			{},

			// Number
			[this](Number n)
			{
				activeParameter = n;
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(signaturesKey, 0);

	// This
	initializer.object = this;
}


SignatureHelp::SignaturesMaker::
	SignaturesMaker(vector<SignatureInformation> &parentArray):
		parentArray(parentArray)
{};

SignatureHelp::SignaturesMaker::
	~SignaturesMaker()
{};


void SignatureHelp::SignaturesMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// SignatureInfomation[]
	extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

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

SignatureHelpContext::SignatureHelpContext(){};
SignatureHelpContext::~SignatureHelpContext(){};

void SignatureHelpContext::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// SignatureHelpTriggerKind:
	setterMap.emplace(
		triggerKindKey,
		ValueSetter{
			// String
			{},

			// Number
			[this, &neededMap](Number n)
			{
				if(holds_alternative<int>(n))
				{
					int i = get<int>(n);

					triggerKind = (SignatureHelpTriggerKind)i;

					neededMap[triggerKindKey] = true;
				}
				else
				{
					// Exception or something
				}
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
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
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// isRetrigger:
	setterMap.emplace(
		isRetriggerKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this, &neededMap](Boolean b)
			{
				isRetrigger = b;
				neededMap[isRetriggerKey] = true;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// activeSignatureHelp?:
	setterMap.emplace(
		activeSignatureHelpKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				activeSignatureHelp.emplace();

				handler->pushInitializer();
				activeSignatureHelp->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// Needed members
	neededMap.emplace(triggerKindKey, 0);
	neededMap.emplace(isRetriggerKey, 0);

	// This
	initializer.object = this;
}

const String SignatureHelpParams::contextKey = "context";

SignatureHelpParams::SignatureHelpParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<SignatureHelpContext> context):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		context(context)
{};

SignatureHelpParams::SignatureHelpParams(){};
SignatureHelpParams::~SignatureHelpParams(){};

void SignatureHelpParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);

	// Value setters

	// context?:
	setterMap.emplace(
		contextKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

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

}
