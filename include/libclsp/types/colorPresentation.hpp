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

#include <libclsp/types/documentColor.hpp>
#include <libclsp/types/textEdit.hpp>


namespace clsp
{

using namespace std;


/// ColorPresentation request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// color: Color
///
/// range: Range
///
struct ColorPresentationParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{

	// FIXME:
	// Even if the struct is not parseable this functions must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String textDocumentKey;

	/// The text document.
	TextDocumentIdentifier textDocument;


	const static String colorKey;

	/// The color information to request presentations for.
	Color color;


	const static String rangeKey;

	/// The range where the color would be inserted. Serves as a context.
	Range range;


	ColorPresentationParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument,
		Color color,
		Range range);

	ColorPresentationParams();

	virtual ~ColorPresentationParams();
};

/// Color presentation response result.
///
/// label: String
///
/// textEdit?: TextEdit
///
/// additionalTextEdits?: TextEdit[]
///
struct ColorPresentation
{

	const static String labelKey;

	/// The label of this color presentation. It will be shown on the color
	/// picker header. By default this is also the text that is inserted when
	/// selecting this color presentation.
	String label;


	const static String textEditKey;

	/// An edit which is applied to a document when selecting
	/// this presentation for the color.  When `falsy` the label
	/// is used.
	optional<TextEdit> textEdit;


	const static String additionalTextEditsKey;

	/// An optional array of additional text edits that are applied when
	/// selecting this color presentation. Edits must not overlap with the
	/// main edit nor with themselves.
	optional<vector<TextEdit>> additionalTextEdits;


	ColorPresentation(String label,
		optional<TextEdit> textEdit,
		optional<vector<TextEdit>> additionalTextEdits);

	ColorPresentation();

	virtual ~ColorPresentation();
};

}
