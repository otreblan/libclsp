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

#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// DocumentHighlight request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentHighlightClientCapabilities: public ObjectT
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


	DocumentHighlightClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentHighlightClientCapabilities();

	virtual ~DocumentHighlightClientCapabilities();
};

/// Find references server capability
using DocumentHighlightOptions = WorkDoneProgressOptions; // No parsing

struct DocumentHighlightRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentHighlightOptions
{
protected:
	// TODO
	// without this the compilation fails
	virtual void partialWrite(JsonWriter&){};

public:

	// No parsing

	DocumentHighlightRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentHighlightRegistrationOptions();

	virtual ~DocumentHighlightRegistrationOptions();
};

/// Document highlight request parameters
struct DocumentHighlightParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{

	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DocumentHighlightParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken);

	DocumentHighlightParams();

	virtual ~DocumentHighlightParams();
};

/// A document highlight kind.
enum class DocumentHighlightKind
{
	/// A textual occurrence.
	Text = 1,

	/// Read-access of a symbol, like reading a variable.
	Read = 2,

	/// Write-access of a symbol, like writing to a variable.
	Write = 3
};

/// A document highlight is a range inside a text document which deserves
/// special attention. Usually a document highlight is visualized by changing
/// the background color of its range.
struct DocumentHighlight
{
private:
	const static String rangeKey;
	const static String kindKey;

public:
	/// The range this highlight applies to.
	Range range;

	/// The highlight kind, default is DocumentHighlightKind.Text.
	optional<DocumentHighlightKind> kind;

	// No parsing

	DocumentHighlight(Range range, optional<DocumentHighlightKind> kind);

	DocumentHighlight();

	virtual ~DocumentHighlight();
};

}
