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

namespace libclsp
{

using namespace std;

/// Goto type definition request client capabilities
///
/// dynamicRegistration?: boolean;
///
/// linkSupport?: boolean;
///
struct TypeDefinitionClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether implementation supports dynamic registration. If this is set to
	/// `true` the client supports the new `TypeDefinitionRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;


	const static String linkSupportKey;

	/// The client supports additional metadata in the form of declaration
	/// links.
	///
	/// @since 3.14.0
	optional<Boolean> linkSupport;


	TypeDefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport);

	TypeDefinitionClientCapabilities();

	virtual ~TypeDefinitionClientCapabilities();
};

using TypeDefinitionOptions = WorkDoneProgressOptions;

struct TypeDefinitionRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public TypeDefinitionOptions,
	public StaticRegistrationOptions
{

	TypeDefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<String> id);

	TypeDefinitionRegistrationOptions();

	virtual ~TypeDefinitionRegistrationOptions();
};

struct TypeDefinitionParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{

	TypeDefinitionParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken);

	TypeDefinitionParams();

	virtual ~TypeDefinitionParams();
};

}
