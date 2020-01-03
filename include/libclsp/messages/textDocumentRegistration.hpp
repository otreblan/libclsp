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

#include <libclsp/messages/documentFilter.hpp>

namespace libclsp
{

using namespace std;

/// Options to dynamically register for requests for a set of text documents.
///
/// documentSelector: DocumentSelector | Null
///
struct TextDocumentRegistrationOptions
{

	const static String documentSelectorKey;

	/// A document selector to identify the scope of the registration.
	/// If set to null the document selector provided on the client side
	/// will be used.
	variant<DocumentSelector, Null> documentSelector;

	TextDocumentRegistrationOptions(variant<DocumentSelector, Null> documentSelector);

	virtual ~TextDocumentRegistrationOptions();
};

}
