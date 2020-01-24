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

#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/textDocumentIdentifier.hpp>

namespace clsp
{

using namespace std;

/// DidSaveTextDocument Server capability
///
/// includeText?: Boolean
///
struct SaveOptions
{
private:
	const static String includeTextKey;

public:
	/// The client is supposed to include the content on save.
	optional<Boolean> includeText;

	// No parsing

	SaveOptions(optional<Boolean> includeText);

	SaveOptions();

	virtual ~SaveOptions();
};

/// DidSaveTextDocument registration options
///
/// includeText?: Boolean
///
struct TextDocumentSaveRegistrationOptions: public TextDocumentRegistrationOptions
{
private:
	const static String includeTextKey;

public:
	/// The client is supposed to include the content on save.
	optional<Boolean> includeText;

	// No parsing

	TextDocumentSaveRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> includeText);

	TextDocumentSaveRegistrationOptions();

	virtual ~TextDocumentSaveRegistrationOptions();
};

/// DidSaveTextDocument parameters
///
/// textDocument: TextDocumentIdentifier
///
/// text?: String
///
struct DidSaveTextDocumentParams: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String textKey;

public:
	/// The document that was saved.
	TextDocumentIdentifier textDocument;

	/// Optional the content when saved. Depends on the includeText value
	/// when the save notification was requested.
	optional<String> text;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DidSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		optional<String> text);

	DidSaveTextDocumentParams();

	virtual ~DidSaveTextDocumentParams();
};

}
