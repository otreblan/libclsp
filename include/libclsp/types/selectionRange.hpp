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
#include <libclsp/types/staticRegistration.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// SelectionRange request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct SelectionRangeClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration. If this is set to
	/// `true` the client supports the new `SelectionRangeRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration);

	SelectionRangeClientCapabilities();

	virtual ~SelectionRangeClientCapabilities();
};

using SelectionRangeOptions = WorkDoneProgressOptions; // No parsing

struct SelectionRangeRegistrationOptions:
	public SelectionRangeOptions,
	public TextDocumentRegistrationOptions,
	public StaticRegistrationOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	SelectionRangeRegistrationOptions(optional<Boolean> workDoneProgress,
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id);

	SelectionRangeRegistrationOptions();

	virtual ~SelectionRangeRegistrationOptions();
};

/// SelectionRange request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// positions: Position[]
///
struct SelectionRangeParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{
private:
	const static String textDocumentKey;
	const static String positionsKey;

	struct PositionsMaker: public ObjectT
	{
		vector<Position> &parentArray;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		PositionsMaker(vector<Position> &parentArray);

		virtual ~PositionsMaker();
	};
public:
	/// The text document.
	TextDocumentIdentifier textDocument;

	/// The positions inside the text document.
	vector<Position> positions;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	SelectionRangeParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument,
		vector<Position> positions);

	SelectionRangeParams();

	virtual ~SelectionRangeParams();
};

/// Part of the selection range response result
///
/// range: Range
///
/// parent?: SelectionRange
///
struct SelectionRange: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String rangeKey;
	const static String parentKey;

public:
	/// The range of this selection range.
	Range range;

	/// The parent selection range containing this range.
	/// Therefore `parent.range` must contain `this.range`.
	optional<shared_ptr<SelectionRange>> parent;

	// No parsing

	SelectionRange(Range range,
		optional<shared_ptr<SelectionRange>> parent);

	SelectionRange(Range range, SelectionRange parent);

	SelectionRange();

	virtual ~SelectionRange();
};

}
