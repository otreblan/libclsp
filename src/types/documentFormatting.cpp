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

#include <libclsp/types/documentFormatting.hpp>

namespace clsp
{

using namespace std;

const String DocumentFormattingClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentFormattingClientCapabilities::
	DocumentFormattingClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DocumentFormattingClientCapabilities::DocumentFormattingClientCapabilities(){};
DocumentFormattingClientCapabilities::~DocumentFormattingClientCapabilities(){};

void DocumentFormattingClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
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

	// This
	initializer.object = this;
}


DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<Boolean> workDoneProgress):
		TextDocumentRegistrationOptions(documentSelector),
		DocumentFormattingOptions(workDoneProgress)
{};

DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions(){};
DocumentFormattingRegistrationOptions::~DocumentFormattingRegistrationOptions(){};


const String FormattingOptions::
	tabSizeKey                = "tabSize";

const String FormattingOptions::
	insertSpacesKey           = "insertSpaces";

const String FormattingOptions::
	trimTrailingWhitespaceKey = "trimTrailingWhitespace";

const String FormattingOptions::
	insertFinalNewlineKey     = "insertFinalNewline";

const String FormattingOptions::
	trimFinalNewlinesKey      = "trimFinalNewlines";

FormattingOptions::FormattingOptions(Number tabSize,
	Boolean insertSpaces,
	optional<Boolean> trimTrailingWhitespace,
	optional<Boolean> insertFinalNewline,
	optional<Boolean> trimFinalNewlines,
	map<String, variant<Boolean, Number, String>> extras):
		tabSize(tabSize),
		insertSpaces(insertSpaces),
		trimTrailingWhitespace(trimTrailingWhitespace),
		insertFinalNewline(insertFinalNewline),
		trimFinalNewlines(trimFinalNewlines),
		extras(extras)
{};

FormattingOptions::FormattingOptions(){};
FormattingOptions::~FormattingOptions(){};

void FormattingOptions::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;
	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// tabSize:
	setterMap.emplace(
		tabSizeKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this, &neededMap](Number n)
			{
				tabSize = n;
				neededMap[tabSizeKey] = true;
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

	// insertSpaces:
	setterMap.emplace(
		insertSpacesKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this, &neededMap](Boolean b)
			{
				insertSpaces = b;
				neededMap[insertSpacesKey] = true;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// trimTrailingWhitespace?:
	setterMap.emplace(
		trimTrailingWhitespaceKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				trimTrailingWhitespace = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// insertFinalNewline?:
	setterMap.emplace(
		insertFinalNewlineKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				insertFinalNewline = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// trimFinalNewlines?:
	setterMap.emplace(
		trimFinalNewlinesKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				trimFinalNewlines = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// Extra members
	extraSetter =
	{
		// String
		[this, handler](String str)
		{
			extras.emplace(handler->lastKey, str);
		},

		// Number
		[this, handler](Number n)
		{
			extras.emplace(handler->lastKey, n);
		},

		// Boolean
		[this, handler](Boolean b)
		{
			extras.emplace(handler->lastKey, b);
		},

		// Null
		nullopt,

		// Array
		nullopt,

		// Object
		nullopt
	};

	// Needed members
	neededMap.emplace(tabSizeKey, 0);
	neededMap.emplace(insertSpacesKey, 0);

	// This
	initializer.object = this;
}


const String DocumentFormattingParams::textDocumentKey = "textDocument";
const String DocumentFormattingParams::optionsKey      = "options";

DocumentFormattingParams::DocumentFormattingParams(
	optional<ProgressToken> workDoneToken,
	TextDocumentIdentifier textDocument,
	FormattingOptions options):
		WorkDoneProgressParams(workDoneToken),
		textDocument(textDocument),
		options(options)
{};

DocumentFormattingParams::DocumentFormattingParams(){};
DocumentFormattingParams::~DocumentFormattingParams(){};

void DocumentFormattingParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parent
	WorkDoneProgressParams::fillInitializer(initializer);

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

	// options:
	setterMap.emplace(
		optionsKey,
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

				options.fillInitializer(handler->objectStack.top());

				neededMap[optionsKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(textDocumentKey, 0);
	neededMap.emplace(optionsKey, 0);

	// This
	initializer.object = this;
}

}
