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

#include <libclsp/types/codeLens.hpp>

namespace libclsp
{

using namespace std;

const String CodeLensClientCapabilities::
	dynamicRegistrationKey      = "dynamicRegistration";


CodeLensClientCapabilities::
	CodeLensClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

CodeLensClientCapabilities:: CodeLensClientCapabilities():
	dynamicRegistration()
{};

CodeLensClientCapabilities::~CodeLensClientCapabilities(){};


const String CodeLensOptions::resolveProviderKey = "resolveProvider";

CodeLensOptions::CodeLensOptions(optional<ProgressToken> workDoneProgress,
	optional<Boolean> resolveProvider):
		WorkDoneProgressOptions(workDoneProgress),
		resolveProvider(resolveProvider)
{};


CodeLensOptions::CodeLensOptions():
	WorkDoneProgressOptions(),
	resolveProvider()
{};

CodeLensOptions::~CodeLensOptions(){};


CodeLensRegistrationOptions::CodeLensRegistrationOptions(
	variant<DocumentSelector, Null> documentSelector,
	optional<ProgressToken> workDoneProgress,
	optional<Boolean> resolveProvider):
		TextDocumentRegistrationOptions(documentSelector),
		CodeLensOptions(workDoneProgress, resolveProvider)
{};

CodeLensRegistrationOptions::CodeLensRegistrationOptions():
	TextDocumentRegistrationOptions(),
	CodeLensOptions()
{};

CodeLensRegistrationOptions::~CodeLensRegistrationOptions(){};


const String CodeLensParams::textDocumentKey = "textDocument";

CodeLensParams::CodeLensParams(optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	TextDocumentIdentifier textDocument):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		textDocument(textDocument)
{};

CodeLensParams::CodeLensParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	textDocument()
{};

CodeLensParams::~CodeLensParams(){};


const String CodeLens::rangeKey   = "range";
const String CodeLens::commandKey = "command";
const String CodeLens::dataKey    = "data";

CodeLens::CodeLens(Range range,
	optional<Command> command,
	optional<Any> data):
		range(range),
		command(command),
		data(data)
{};

CodeLens::CodeLens():
	range(),
	command(),
	data()
{};

CodeLens::~CodeLens(){};


}
