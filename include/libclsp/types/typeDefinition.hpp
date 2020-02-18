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

#include <libclsp/types/staticRegistration.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>
#include <libclsp/types/partialResult.hpp>

namespace clsp
{

using namespace std;

/// Goto type definition request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// linkSupport?: Boolean
///
struct TypeDefinitionClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String linkSupportKey;

public:
	/// Whether implementation supports dynamic registration. If this is set to
	/// `true` the client supports the new `TypeDefinitionRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;

	/// The client supports additional metadata in the form of declaration
	/// links.
	///
	/// @since 3.14.0
	optional<Boolean> linkSupport;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	TypeDefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport);

	TypeDefinitionClientCapabilities();

	virtual ~TypeDefinitionClientCapabilities();
};

using TypeDefinitionOptions = WorkDoneProgressOptions; // No parsing

struct TypeDefinitionRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public TypeDefinitionOptions,
	public StaticRegistrationOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	TypeDefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<String> id);

	TypeDefinitionRegistrationOptions();

	virtual ~TypeDefinitionRegistrationOptions();
};

struct TypeDefinitionParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{

	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	TypeDefinitionParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken);

	TypeDefinitionParams();

	virtual ~TypeDefinitionParams();
};

}
