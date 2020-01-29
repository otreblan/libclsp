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

#include <libclsp/types/typeDefinition.hpp>

namespace clsp
{

using namespace std;

const String TypeDefinitionClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String TypeDefinitionClientCapabilities::
	linkSupportKey         = "linkSupport";

TypeDefinitionClientCapabilities::
	TypeDefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport):
			dynamicRegistration(dynamicRegistration),
			linkSupport(linkSupport)
{};

TypeDefinitionClientCapabilities::TypeDefinitionClientCapabilities(){};
TypeDefinitionClientCapabilities::~TypeDefinitionClientCapabilities(){};

void TypeDefinitionClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
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

	// linkSupport?:
	setterMap.emplace(
		linkSupportKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				linkSupport = b;
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

TypeDefinitionRegistrationOptions::
	TypeDefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<String> id):
			TextDocumentRegistrationOptions(documentSelector),
			TypeDefinitionOptions(workDoneProgress),
			StaticRegistrationOptions(id)
{};

TypeDefinitionRegistrationOptions::TypeDefinitionRegistrationOptions(){};
TypeDefinitionRegistrationOptions::~TypeDefinitionRegistrationOptions(){};


TypeDefinitionParams::TypeDefinitionParams(TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken)
{};

TypeDefinitionParams::TypeDefinitionParams(){};
TypeDefinitionParams::~TypeDefinitionParams(){};

void TypeDefinitionParams::fillInitializer(ObjectInitializer& initializer)
{
	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);
}

}
