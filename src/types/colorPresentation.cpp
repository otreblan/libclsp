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

#include <libclsp/types/colorPresentation.hpp>

namespace libclsp
{

using namespace std;

const String ColorPresentationParams::textDocumentKey = "textDocument";
const String ColorPresentationParams::colorKey        = "color";
const String ColorPresentationParams::rangeKey        = "range";

ColorPresentationParams::ColorPresentationParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument,
	Color color,
	Range range):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument),
		color(color),
		range(range)
{};

ColorPresentationParams::ColorPresentationParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument(),
	color(),
	range()
{};

ColorPresentationParams::~ColorPresentationParams(){};


const String ColorPresentation::labelKey               = "label";
const String ColorPresentation::textEditKey            = "textEdit";
const String ColorPresentation::additionalTextEditsKey = "additionalTextEdits";

ColorPresentation::ColorPresentation(String label,
	optional<TextEdit> textEdit,
	optional<vector<TextEdit>> additionalTextEdits):
		label(label),
		textEdit(textEdit),
		additionalTextEdits(additionalTextEdits)
{};

ColorPresentation::ColorPresentation():
	label(),
	textEdit(),
	additionalTextEdits()
{};

ColorPresentation::~ColorPresentation(){};

}
