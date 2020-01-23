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

#include <libclsp/types/position.hpp>
#include <libclsp/types/textDocumentIdentifier.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// Rename request client capabilities
///
/// dynamicRegistration?: boolean;
///
/// prepareSupport?: boolean
///
struct RenameClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	const static String prepareSupportKey;

	/// Client supports testing for validity of rename operations
	/// before execution.
	///
	/// @since version 3.12.0
	optional<Boolean> prepareSupport;


	RenameClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> prepareSupport);

	RenameClientCapabilities();

	virtual ~RenameClientCapabilities();
};

/// RenameOptions may only be specified if the client states that it supports
/// prepareSupport in its initial initialize request.
///
/// prepareProvider?: Boolean
///
struct RenameOptions: public WorkDoneProgressOptions
{

	const static String prepareProviderKey;

	/// Renames should be checked and tested before being executed.
	optional<Boolean> prepareProvider;


	RenameOptions(optional<ProgressToken> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameOptions();

	virtual ~RenameOptions();
};

struct RenameRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public RenameOptions
{

	RenameRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameRegistrationOptions();

	virtual ~RenameRegistrationOptions();
};

/// Document range formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// position: Position
///
/// newName: String
///
struct RenameParams: public WorkDoneProgressParams
{

	const static String textDocumentKey;

	/// The document to format.
	TextDocumentIdentifier textDocument;


	const static String positionKey;

	/// The position at which this request was sent.
	Position position;


	const static String newNameKey;

	/// The new name of the symbol. If the given name is not valid the
	/// request must return a ResponseError with an
	/// appropriate message set.
	String newName;


	RenameParams(optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		Position position,
		String newName);

	RenameParams();

	virtual ~RenameParams();
};

}
