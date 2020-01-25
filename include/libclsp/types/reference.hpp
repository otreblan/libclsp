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

#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>
#include <libclsp/types/partialResult.hpp>

namespace clsp
{

using namespace std;

/// Goto Reference request client capabilities
///
/// dynamicRegistration?: boolean;
///
struct ReferenceClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;




	ReferenceClientCapabilities(optional<Boolean> dynamicRegistration);

	ReferenceClientCapabilities();

	virtual ~ReferenceClientCapabilities();
};

/// Find references server capability
using ReferenceOptions = WorkDoneProgressOptions;

struct ReferenceRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public ReferenceOptions
{

	ReferenceRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress);

	ReferenceRegistrationOptions();

	virtual ~ReferenceRegistrationOptions();
};

/// An option for the find references request.
///
/// includeDeclaration: Boolean
///
struct ReferenceContext
{

	const static String includeDeclarationKey;

	Boolean includeDeclaration;


	ReferenceContext(Boolean includeDeclaration);

	ReferenceContext();

	virtual ~ReferenceContext();
};

/// Find references request parameters
///
/// context: ReferenceContext
///
struct ReferenceParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{

	// FIXME:
	// Even if the struct is not parseable this function must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String contextKey;

	ReferenceContext context;


	ReferenceParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		ReferenceContext context);

	ReferenceParams();

	virtual ~ReferenceParams();
};

}
