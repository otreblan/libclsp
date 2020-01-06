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

#include <libclsp/messages/textDocumentIdentifier.hpp>

namespace libclsp
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
struct WillSaveTextDocumentParams
{

	const static String textDocumentKey;

	/// The document that will be saved.
	TextDocumentIdentifier textDocument;


	const static String reasonKey;

	/// The 'TextDocumentSaveReason'.
	TextDocumentSaveReason reason;


	WillSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		TextDocumentSaveReason reason);

	WillSaveTextDocumentParams();

	virtual ~WillSaveTextDocumentParams();
};

}
