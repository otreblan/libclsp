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
/// dynamicRegistration?: Boolean
///
struct ReferenceClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	ReferenceClientCapabilities(optional<Boolean> dynamicRegistration);

	ReferenceClientCapabilities();

	virtual ~ReferenceClientCapabilities();
};

/// Find references server capability
using ReferenceOptions = WorkDoneProgressOptions; // No parsing

struct ReferenceRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public ReferenceOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	ReferenceRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	ReferenceRegistrationOptions();

	virtual ~ReferenceRegistrationOptions();
};

/// An option for the find references request.
///
/// includeDeclaration: Boolean
///
struct ReferenceContext: public ObjectT
{
private:
	const static String includeDeclarationKey;

public:
	Boolean includeDeclaration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

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
private:
	const static String contextKey;

public:
	ReferenceContext context;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	ReferenceParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		ReferenceContext context);

	ReferenceParams();

	virtual ~ReferenceParams();
};

}
