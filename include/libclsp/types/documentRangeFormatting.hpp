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

/// DocumentRangeFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentRangeFormattingClientCapabilities: public ObjectT
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

	// No writing

	DocumentRangeFormattingClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentRangeFormattingClientCapabilities();

	virtual ~DocumentRangeFormattingClientCapabilities();
};

using DocumentRangeFormattingOptions = WorkDoneProgressOptions; // No parsing

struct DocumentRangeFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentRangeFormattingOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:

	// No parsing

	DocumentRangeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentRangeFormattingRegistrationOptions();

	virtual ~DocumentRangeFormattingRegistrationOptions();
};

/// Document range formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// range: Range
///
/// options: FormattingOptions
///
struct DocumentRangeFormattingParams: public WorkDoneProgressParams
{
private:
	const static String textDocumentKey;
	const static String rangeKey;
	const static String optionsKey;

public:
	/// The document to format.
	TextDocumentIdentifier textDocument;

	/// The range to format
	Range range;

	/// The format options.
	FormattingOptions options;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	DocumentRangeFormattingParams(optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		Range range,
		FormattingOptions options);

	DocumentRangeFormattingParams();

	virtual ~DocumentRangeFormattingParams();
};

}
