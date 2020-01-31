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

#include <libclsp/types/documentRangeFormatting.hpp>

namespace clsp
{

using namespace std;

const String DocumentRangeFormattingClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentRangeFormattingClientCapabilities::
	DocumentRangeFormattingClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DocumentRangeFormattingClientCapabilities::
	DocumentRangeFormattingClientCapabilities()
{};

DocumentRangeFormattingClientCapabilities::
	~DocumentRangeFormattingClientCapabilities()
{};

void DocumentRangeFormattingClientCapabilities::
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


DocumentRangeFormattingRegistrationOptions::DocumentRangeFormattingRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress):
		TextDocumentRegistrationOptions(documentSelector),
		DocumentRangeFormattingOptions(workDoneProgress)
{};

DocumentRangeFormattingRegistrationOptions::
	DocumentRangeFormattingRegistrationOptions()
{};

DocumentRangeFormattingRegistrationOptions::
	~DocumentRangeFormattingRegistrationOptions()
{};


const String DocumentRangeFormattingParams::textDocumentKey = "textDocument";
const String DocumentRangeFormattingParams::rangeKey        = "range";
const String DocumentRangeFormattingParams::optionsKey      = "options";

DocumentRangeFormattingParams::DocumentRangeFormattingParams(
	optional<ProgressToken> workDoneToken,
	TextDocumentIdentifier textDocument,
	Range range,
	FormattingOptions options):
		WorkDoneProgressParams(workDoneToken),
		textDocument(textDocument),
		range(range),
		options(options)
{};

DocumentRangeFormattingParams::DocumentRangeFormattingParams(){};
DocumentRangeFormattingParams::~DocumentRangeFormattingParams(){};

void DocumentRangeFormattingParams::
	fillInitializer(ObjectInitializer& initializer)
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
	neededMap.emplace(rangeKey, 0);
	neededMap.emplace(optionsKey, 0);

	// This
	initializer.object = this;
}

}
