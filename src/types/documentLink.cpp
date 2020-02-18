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

#include <libclsp/types/documentLink.hpp>

namespace clsp
{

using namespace std;

const String DocumentLinkClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String DocumentLinkClientCapabilities::
	tooltipSupportKey      = "tooltipSupport";

DocumentLinkClientCapabilities::
	DocumentLinkClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> tooltipSupport):
			dynamicRegistration(dynamicRegistration),
			tooltipSupport(tooltipSupport)
{};


DocumentLinkClientCapabilities:: DocumentLinkClientCapabilities(){};
DocumentLinkClientCapabilities::~DocumentLinkClientCapabilities(){};

void DocumentLinkClientCapabilities::
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

	// tooltipSupport?:
	setterMap.emplace(
		tooltipSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				tooltipSupport = b;
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


const String DocumentLinkOptions::resolveProviderKey = "resolveProvider";

DocumentLinkOptions::DocumentLinkOptions(optional<Boolean> workDoneProgress,
	optional<Boolean> resolveProvider):
		WorkDoneProgressOptions(workDoneProgress),
		resolveProvider(resolveProvider)
{};


DocumentLinkOptions::DocumentLinkOptions(){};
DocumentLinkOptions::~DocumentLinkOptions(){};


DocumentLinkRegistrationOptions::DocumentLinkRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<Boolean> workDoneProgress,
	optional<Boolean> resolveProvider):
		TextDocumentRegistrationOptions(documentSelector),
		DocumentLinkOptions(workDoneProgress, resolveProvider)
{};

DocumentLinkRegistrationOptions::DocumentLinkRegistrationOptions(){};
DocumentLinkRegistrationOptions::~DocumentLinkRegistrationOptions(){};


const String DocumentLinkParams::textDocumentKey = "textDocument";

DocumentLinkParams::DocumentLinkParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

DocumentLinkParams::DocumentLinkParams(){};
DocumentLinkParams::~DocumentLinkParams(){};

void DocumentLinkParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);

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

	// Needed members
	neededMap.emplace(textDocumentKey, 0);

	// This
	initializer.object = this;
}

const String DocumentLink::rangeKey   = "range";
const String DocumentLink::targetKey  = "target";
const String DocumentLink::tooltipKey = "tooltip";
const String DocumentLink::dataKey    = "data";

DocumentLink::DocumentLink(Range range,
	optional<DocumentUri> target,
	optional<String> tooltip,
	optional<Any> data):
		range(range),
		target(target),
		tooltip(tooltip),
		data(data)
{};

DocumentLink::DocumentLink(){};
DocumentLink::~DocumentLink(){};

}
