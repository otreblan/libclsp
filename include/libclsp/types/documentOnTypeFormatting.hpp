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

namespace libclsp
{

using namespace std;

/// DocumentOnTypeFormatting request client capabilities
///
/// dynamicRegistration?: boolean;
///
struct DocumentOnTypeFormattingClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	DocumentOnTypeFormattingClientCapabilities(
		optional<Boolean> dynamicRegistration);

	DocumentOnTypeFormattingClientCapabilities();

	virtual ~DocumentOnTypeFormattingClientCapabilities();
};

/// DocumentOnTypeFormatting request parameters
///
/// firstTriggerCharacter: String
///
/// moreTriggerCharacter?: String[]
///
struct DocumentOnTypeFormattingOptions
{

	const static String firstTriggerCharacterKey;

	/// A character on which formatting should be triggered, like `}`.
	String firstTriggerCharacter;


	const static String moreTriggerCharacterKey;

	/// More trigger characters.
	optional<vector<String>> moreTriggerCharacter;


	DocumentOnTypeFormattingOptions(String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingOptions();

	virtual ~DocumentOnTypeFormattingOptions();
};

struct DocumentOnTypeFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentOnTypeFormattingOptions
{

	DocumentOnTypeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingRegistrationOptions();

	virtual ~DocumentOnTypeFormattingRegistrationOptions();
};

/// Document on type formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// position: Position
///
/// ch: String
///
/// options: FormattingOptions
///
struct DocumentOnTypeFormattingParams
{

	const static String textDocumentKey;

	/// The document to format.
	TextDocumentIdentifier textDocument;


	const static String positionKey;

	/// The position at which this request was sent.
	Position position;


	const static String chKey;

	/// The character that has been typed.
	String ch;


	const static String optionsKey;

	/// The format options.
	FormattingOptions options;


	DocumentOnTypeFormattingParams(TextDocumentIdentifier textDocument,
		Position position,
		String ch,
		FormattingOptions options);

	DocumentOnTypeFormattingParams();

	virtual ~DocumentOnTypeFormattingParams();
};

}
