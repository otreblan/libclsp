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

#include <libclsp/types/symbol.hpp>

namespace libclsp
{

using namespace std;

/// WorkspaceSymbol request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// symbolKind?: {
///
/// 	valueSet?: SymbolKind[]
/// }
///
struct WorkspaceSymbolClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether declaration supports dynamic registration. If this is set to
	/// `true` the client supports the new `WorkspaceSymbolRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;


	const static String symbolKindKey;

	/// Specific capabilities for the `SymbolKind` in the `workspace/symbol`
	/// request.
	struct SymbolKind
	{

		const static String valueSetKey;

		/// The symbol kind values the client supports. When this
		/// property exists the client also guarantees that it will
		/// handle values outside its set gracefully and falls back
		/// to a default value when unknown.
		///
		/// If this property is not present the client only supports
		/// the symbol kinds from `File` to `Array` as defined in
		/// the initial version of the protocol.
		optional<vector<libclsp::SymbolKind>> valueSet;


		SymbolKind(optional<vector<libclsp::SymbolKind>> valueSet);

		SymbolKind();

		virtual ~SymbolKind();
	};

	/// Specific capabilities for the `SymbolKind` in the `workspace/symbol`
	/// request.
	optional<SymbolKind> symbolKind;


	WorkspaceSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind);


	WorkspaceSymbolClientCapabilities();

	virtual ~WorkspaceSymbolClientCapabilities();
};

using WorkspaceSymbolOptions = WorkDoneProgressOptions;

using WorkspaceSymbolRegistrationOptions = WorkspaceSymbolOptions;


/// The parameters of a Workspace Symbol Request.
///
/// query: String
///
struct WorkspaceSymbolParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{

	const static String queryKey;

	/// A query string to filter symbols by. Clients may send an empty
	/// string here to request all symbols.
	String query;


	WorkspaceSymbolParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		String query);

	WorkspaceSymbolParams();

	virtual ~WorkspaceSymbolParams();
};

}
