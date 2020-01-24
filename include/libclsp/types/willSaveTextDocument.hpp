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

#include <optional>

#include <libclsp/types/textDocumentIdentifier.hpp>

namespace clsp
{

using namespace std;

/// Represents reasons why a text document is saved.
enum class TextDocumentSaveReason
{
	/// Manually triggered, e.g. by the user pressing save, by starting
	/// debugging, or by an API call.
	Manual = 1,

	/// Automatic after a delay.
	AfterDelay = 2,

	/// When the editor lost focus.
	FocusOut = 3
};

/// The parameters send in a will save text document notification.
///
/// textDocument: TextDocumentIdentifie
///
/// reason: TextDocumentSaveReason
///
struct WillSaveTextDocumentParams: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String reasonKey;

public:
	/// The document that will be saved.
	TextDocumentIdentifier textDocument;

	/// The 'TextDocumentSaveReason'.
	TextDocumentSaveReason reason;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	WillSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		TextDocumentSaveReason reason);

	WillSaveTextDocumentParams();

	virtual ~WillSaveTextDocumentParams();
};

}
