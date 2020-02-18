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

#include <libclsp/types/definition.hpp>

namespace clsp
{

using namespace std;

const String DefinitionClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String DefinitionClientCapabilities::
	linkSupportKey         = "linkSupport";

DefinitionClientCapabilities::
	DefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport):
			dynamicRegistration(dynamicRegistration),
			linkSupport(linkSupport)
{};

DefinitionClientCapabilities::DefinitionClientCapabilities(){};
DefinitionClientCapabilities::~DefinitionClientCapabilities(){};

void DefinitionClientCapabilities::
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

	// linkSupport?:
	setterMap.emplace(
		linkSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				linkSupport = b;
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

DefinitionRegistrationOptions::DefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress):
			TextDocumentRegistrationOptions(documentSelector),
			DefinitionOptions(workDoneProgress)
{};

DefinitionRegistrationOptions::DefinitionRegistrationOptions(){};
DefinitionRegistrationOptions::~DefinitionRegistrationOptions(){};

void DefinitionRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// Parents
	TextDocumentRegistrationOptions::partialWrite(writer);
	DefinitionOptions::partialWrite(writer);
}


DefinitionParams::DefinitionParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

DefinitionParams::DefinitionParams(){};
DefinitionParams::~DefinitionParams(){};

void DefinitionParams::fillInitializer(ObjectInitializer& initializer)
{
	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);
}

}
