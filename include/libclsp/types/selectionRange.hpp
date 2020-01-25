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
/// dynamicRegistration?: boolean;
///
struct SelectionRangeClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether declaration supports dynamic registration. If this is set to
	/// `true` the client supports the new `SelectionRangeRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;



	SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration);

	SelectionRangeClientCapabilities();

	virtual ~SelectionRangeClientCapabilities();
};

using SelectionRangeOptions = WorkDoneProgressOptions;

struct SelectionRangeRegistrationOptions:
	public SelectionRangeOptions,
	public TextDocumentRegistrationOptions,
	public StaticRegistrationOptions
{

	SelectionRangeRegistrationOptions(optional<ProgressToken> workDoneProgress,
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

	// FIXME:
	// Even if the struct is not parseable this function must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String textDocumentKey;

	/// The text document.
	TextDocumentIdentifier textDocument;


	const static String positionsKey;

	/// The positions inside the text document.
	vector<Position> positions;


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
struct SelectionRange
{

	const static String rangeKey;

	/// The range of this selection range.
	Range range;


	const static String parentKey;

	/// The parent selection range containing this range.
	/// Therefore `parent.range` must contain `this.range`.
	optional<reference_wrapper<SelectionRange>> parent;


	SelectionRange(Range range,
		optional<reference_wrapper<SelectionRange>> parent);

	SelectionRange();

	virtual ~SelectionRange();
};

}
