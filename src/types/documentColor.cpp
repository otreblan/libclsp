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

#include <libclsp/types/documentColor.hpp>

namespace clsp
{

using namespace std;

const String DocumentColorClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DocumentColorClientCapabilities::
	DocumentColorClientCapabilities(optional<Boolean> dynamicRegistration):
			dynamicRegistration(dynamicRegistration)
{};

DocumentColorClientCapabilities::DocumentColorClientCapabilities():
	dynamicRegistration()
{};

DocumentColorClientCapabilities::~DocumentColorClientCapabilities(){};


DocumentColorRegistrationOptions::DocumentColorRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<String> id,
	optional<ProgressToken> workDoneProgress):
		TextDocumentRegistrationOptions(documentSelector),
		StaticRegistrationOptions(id),
		DocumentColorOptions(workDoneProgress)
{};


DocumentColorRegistrationOptions::DocumentColorRegistrationOptions():
	TextDocumentRegistrationOptions(),
	StaticRegistrationOptions(),
	DocumentColorOptions()
{};

DocumentColorRegistrationOptions::~DocumentColorRegistrationOptions(){};


DocumentColorParams::DocumentColorParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

DocumentColorParams::DocumentColorParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument()
{};

DocumentColorParams::~DocumentColorParams(){};


const String Color::redKey   = "red";
const String Color::greenKey = "green";
const String Color::blueKey  = "blue";
const String Color::alphaKey = "alpha ";

Color::Color(const Number red,
	const Number green,
	const Number blue,
	const Number alpha):
		red(red),
		green(green),
		blue(blue),
		alpha(alpha)
{};

Color::Color():
	red(),
	green(),
	blue(),
	alpha()
{};

Color::~Color(){};


const String ColorInformation::rangeKey = "range";
const String ColorInformation::colorKey = "color";

ColorInformation::ColorInformation(Range range, Color color):
	range(range),
	color(color)
{};

ColorInformation::ColorInformation():
	range(),
	color()
{};

ColorInformation::~ColorInformation(){};

}
