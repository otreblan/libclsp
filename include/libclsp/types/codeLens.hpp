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

#include <libclsp/types/command.hpp>
#include <libclsp/types/diagnostic.hpp>
#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;


/// CodeLens request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct CodeLensClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether code action supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	CodeLensClientCapabilities(optional<Boolean> dynamicRegistration);

	CodeLensClientCapabilities();

	virtual ~CodeLensClientCapabilities();
};

/// Code lens server capability
///
/// resolveProvider?: Boolean
///
struct CodeLensOptions: public WorkDoneProgressOptions
{
private:
	const static String resolveProviderKey;

public:
	/// Code lens has a resolve provider as well.
	optional<Boolean> resolveProvider;

	// No parsing

	CodeLensOptions(optional<ProgressToken> workDoneProgress,
		optional<Boolean> resolveProvider);

	CodeLensOptions();

	virtual ~CodeLensOptions();
};

struct CodeLensRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public CodeLensOptions
{

	// No parsing

	CodeLensRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<Boolean> resolveProvider);

	CodeLensRegistrationOptions();

	virtual ~CodeLensRegistrationOptions();
};

/// Params for the CodeLensRequest
///
/// textDocument: TextDocumentIdentifier
///
struct CodeLensParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{
private:
	const static String textDocumentKey;

public:
	/// The document in which the command was invoked.
	TextDocumentIdentifier textDocument;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	CodeLensParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument);

	CodeLensParams();

	virtual ~CodeLensParams();
};

/// A code lens represents a command that should be shown along with
/// source text, like the number of references, a way to run tests, etc.
///
/// A code lens is _unresolved_ when no command is associated to it. For
/// performance reasons the creation of a code lens and resolving should be
/// done in two stages.
///
/// range: Range
///
/// command?: Command
///
/// data?: Any
///
struct CodeLens
{
private:
	const static String rangeKey;;
	const static String commandKey;
	const static String dataKey;

public:
	/// The range in which this code lens is valid. Should only span a single
	/// line.
	Range range;

	/// The command this code lens represents.
	optional<Command> command;

	/// A data entry field that is preserved on a code lens item between
	/// a code lens and a code lens resolve request.
	optional<Any> data;

	// No parsing

	CodeLens(Range range,
		optional<Command> command,
		optional<Any> data);

	CodeLens();

	virtual ~CodeLens();
};

}
