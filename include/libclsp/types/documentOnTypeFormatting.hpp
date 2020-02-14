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

#pragma once

#include <libclsp/types/documentFormatting.hpp>

namespace clsp
{

using namespace std;

/// DocumentOnTypeFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentOnTypeFormattingClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DocumentOnTypeFormattingClientCapabilities(
		optional<Boolean> dynamicRegistration);

	DocumentOnTypeFormattingClientCapabilities();

	virtual ~DocumentOnTypeFormattingClientCapabilities();
};

/// DocumentOnTypeFormatting server capability
///
/// firstTriggerCharacter: String
///
/// moreTriggerCharacter?: String[]
///
struct DocumentOnTypeFormattingOptions
{
private:
	const static String firstTriggerCharacterKey;
	const static String moreTriggerCharacterKey;

public:
	/// A character on which formatting should be triggered, like `}`.
	String firstTriggerCharacter;

	/// More trigger characters.
	optional<vector<String>> moreTriggerCharacter;

	// No parsing

	DocumentOnTypeFormattingOptions(String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingOptions();

	virtual ~DocumentOnTypeFormattingOptions();
};

struct DocumentOnTypeFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentOnTypeFormattingOptions
{
protected:
	// TODO
	// without this the compilation fails
	virtual void partialWrite(JsonWriter&){};

public:

	// No parsing

	DocumentOnTypeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingRegistrationOptions();

	virtual ~DocumentOnTypeFormattingRegistrationOptions();
};

/// Document on type formatting request parameters
///
/// ch: String
///
/// options: FormattingOptions
///
struct DocumentOnTypeFormattingParams: public TextDocumentPositionParams
{
private:
	const static String chKey;
	const static String optionsKey;

public:
	/// The character that has been typed.
	String ch;

	/// The format options.
	FormattingOptions options;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DocumentOnTypeFormattingParams(TextDocumentIdentifier textDocument,
		Position position,
		String ch,
		FormattingOptions options);

	DocumentOnTypeFormattingParams();

	virtual ~DocumentOnTypeFormattingParams();
};

}
