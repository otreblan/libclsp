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

#include <map>

#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// DocumentFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentFormattingClientCapabilities: public ObjectT
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


	DocumentFormattingClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentFormattingClientCapabilities();

	virtual ~DocumentFormattingClientCapabilities();
};

using DocumentFormattingOptions = WorkDoneProgressOptions; // No parsing

struct DocumentFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentFormattingOptions
{
protected:
	// TODO
	// without this the compilation fails
	virtual void partialWrite(JsonWriter&){};

public:
	// No parsing

	DocumentFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentFormattingRegistrationOptions();

	virtual ~DocumentFormattingRegistrationOptions();
};

/// Value-object describing what options formatting should use.
///
/// tabSize: Number
///
/// insertSpaces: Boolean
///
/// trimTrailingWhitespace?: Boolean
///
/// insertFinalNewline?: Boolean
///
/// trimFinalNewlines?: Boolean
///
/// [key: String]: Boolean | Number | String
///
struct FormattingOptions: public ObjectT
{
private:
	const static String tabSizeKey;
	const static String insertSpacesKey;
	const static String trimTrailingWhitespaceKey;
	const static String insertFinalNewlineKey;
	const static String trimFinalNewlinesKey;

public:
	/// Size of a tab in spaces.
	Number tabSize;

	/// Prefer spaces over tabs.
	Boolean insertSpaces;

	/// Trim trailing whitespace on a line.
	///
	/// @since 3.15.0
	optional<Boolean> trimTrailingWhitespace;

	/// Insert a newline character at the end of the file if one does not
	/// exist.
	///
	/// @since 3.15.0
	optional<Boolean> insertFinalNewline;

	/// Trim all newlines after the final newline at the end of the file.
	///
	/// @since 3.15.0
	optional<Boolean> trimFinalNewlines;

	/// Signature for further properties.
	map<String, variant<Boolean, Number, String>> extras;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	FormattingOptions(Number tabSize,
		Boolean insertSpaces,
		optional<Boolean> trimTrailingWhitespace,
		optional<Boolean> insertFinalNewline,
		optional<Boolean> trimFinalNewlines,
		map<String, variant<Boolean, Number, String>> extras);

	FormattingOptions();

	virtual ~FormattingOptions();
};

/// Document formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// options: FormattingOptions
///
struct DocumentFormattingParams: public WorkDoneProgressParams
{
private:
	const static String textDocumentKey;
	const static String optionsKey;

public:
	/// The document to format.
	TextDocumentIdentifier textDocument;

	/// The format options.
	FormattingOptions options;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DocumentFormattingParams(optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		FormattingOptions options);

	DocumentFormattingParams();

	virtual ~DocumentFormattingParams();
};

}
