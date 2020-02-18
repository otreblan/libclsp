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
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// Rename request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// prepareSupport?: Boolean
///
struct RenameClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String prepareSupportKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	/// Client supports testing for validity of rename operations
	/// before execution.
	///
	/// @since version 3.12.0
	optional<Boolean> prepareSupport;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


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
private:
	const static String prepareProviderKey;

public:
	/// Renames should be checked and tested before being executed.
	optional<Boolean> prepareProvider;

	// No parsing

	RenameOptions(optional<Boolean> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameOptions();

	virtual ~RenameOptions();
};

struct RenameRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public RenameOptions
{
protected:
	// TODO
	// without this the compilation fails
	virtual void partialWrite(JsonWriter&){};

public:

	// No parsing

	RenameRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameRegistrationOptions();

	virtual ~RenameRegistrationOptions();
};

/// Document range formatting request parameters
///
/// newName: String
///
struct RenameParams: public TextDocumentPositionParams,
	public WorkDoneProgressParams
{
private:
	const static String newNameKey;

public:
	/// The new name of the symbol. If the given name is not valid the
	/// request must return a ResponseError with an
	/// appropriate message set.
	String newName;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	RenameParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		String newName);

	RenameParams();

	virtual ~RenameParams();
};

}
