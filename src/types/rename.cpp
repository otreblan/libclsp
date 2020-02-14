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

#include <libclsp/types/rename.hpp>

namespace clsp
{

using namespace std;

const String RenameClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String RenameClientCapabilities::
	prepareSupportKey      = "prepareSupport";

RenameClientCapabilities::
	RenameClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> prepareSupport):
			dynamicRegistration(dynamicRegistration),
			prepareSupport(prepareSupport)
{};

RenameClientCapabilities::RenameClientCapabilities(){};
RenameClientCapabilities::~RenameClientCapabilities(){};

void RenameClientCapabilities::
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

	// prepareSupport?:
	setterMap.emplace(
		prepareSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				prepareSupport = b;
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


const String RenameOptions::prepareProviderKey = "prepareProvider";

RenameOptions::RenameOptions(optional<ProgressToken> workDoneProgress,
	optional<Boolean> prepareProvider):
		WorkDoneProgressOptions(workDoneProgress),
		prepareProvider(prepareProvider)
{};

RenameOptions::RenameOptions(){};
RenameOptions::~RenameOptions(){};


RenameRegistrationOptions::RenameRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<Boolean> prepareProvider):
		TextDocumentRegistrationOptions(documentSelector),
		RenameOptions(workDoneProgress, prepareProvider)
{};

RenameRegistrationOptions::RenameRegistrationOptions(){};
RenameRegistrationOptions::~RenameRegistrationOptions(){};


const String RenameParams::newNameKey      = "newName";


RenameParams::RenameParams( TextDocumentIdentifier textDocument,
	Position position,
	optional<ProgressToken> workDoneToken,
	String newName):
		TextDocumentPositionParams(textDocument, position),
		WorkDoneProgressParams(workDoneToken),
		newName(newName)
{};

RenameParams::RenameParams(){};
RenameParams::~RenameParams(){};

void RenameParams::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	TextDocumentPositionParams::fillInitializer(initializer);
	WorkDoneProgressParams::fillInitializer(initializer);

	// Value setters

	// newName:
	setterMap.emplace(
		newNameKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				newName = str;
				neededMap[newNameKey] = true;
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
	neededMap.emplace(newNameKey, 0);

	// This
	initializer.object = this;
}

}
