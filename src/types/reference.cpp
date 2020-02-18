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

#include <libclsp/types/reference.hpp>

namespace clsp
{

using namespace std;

const String ReferenceClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

ReferenceClientCapabilities::
	ReferenceClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

ReferenceClientCapabilities::ReferenceClientCapabilities(){};
ReferenceClientCapabilities::~ReferenceClientCapabilities(){};

void ReferenceClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?::
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

ReferenceRegistrationOptions::ReferenceRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			ReferenceOptions(workDoneProgress)
{};

ReferenceRegistrationOptions::ReferenceRegistrationOptions(){};
ReferenceRegistrationOptions::~ReferenceRegistrationOptions(){};


const String ReferenceContext::includeDeclarationKey = "includeDeclaration";

ReferenceContext::ReferenceContext(Boolean includeDeclaration):
	includeDeclaration(includeDeclaration)
{};

ReferenceContext::ReferenceContext(){};
ReferenceContext::~ReferenceContext(){};

void ReferenceContext::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// includeDeclaration:
	setterMap.emplace(
		includeDeclarationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this, &neededMap](Boolean b)
			{
				includeDeclaration = b;
				neededMap[includeDeclarationKey] = true;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(includeDeclarationKey, 0);

	// This
	initializer.object = this;
}

const String ReferenceParams::contextKey = "context";

ReferenceParams::ReferenceParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	ReferenceContext context):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		context(context)
{};

ReferenceParams::ReferenceParams(){};
ReferenceParams::~ReferenceParams(){};

void ReferenceParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);

	// Value setters

	// context:
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
			[this, handler, &neededMap]()
			{
				handler->pushInitializer();
				context.fillInitializer(handler->objectStack.top());
				neededMap[contextKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(contextKey, 0);

	// This
	initializer.object = this;
}

}
