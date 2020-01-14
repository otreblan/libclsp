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

#include <libclsp/types/publishDiagnostic.hpp>

namespace libclsp
{

using namespace std;

const String PublishDiagnosticsClientCapabilities::
	relatedInformationKey = "relatedInformation";

const String PublishDiagnosticsClientCapabilities::
	tagSupportKey         = "tagSupport";

const String PublishDiagnosticsClientCapabilities::
	versionSupportKey     = "versionSupport";

PublishDiagnosticsClientCapabilities::
	PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
		optional<TagSupport> tagSupport,
		optional<Boolean> versionSupport):
			relatedInformation(relatedInformation),
			tagSupport(tagSupport),
			versionSupport(versionSupport)
{};

PublishDiagnosticsClientCapabilities::PublishDiagnosticsClientCapabilities():
	relatedInformation(),
	tagSupport(),
	versionSupport()
{};

PublishDiagnosticsClientCapabilities::
	~PublishDiagnosticsClientCapabilities()
{};


const String PublishDiagnosticsClientCapabilities::TagSupport::
	valueSetKey = "valueSet";

PublishDiagnosticsClientCapabilities::TagSupport::
	TagSupport(vector<DiagnosticTag> valueSet):
		valueSet(valueSet)
{}

PublishDiagnosticsClientCapabilities::TagSupport::TagSupport():
	valueSet()
{}

PublishDiagnosticsClientCapabilities::TagSupport::~TagSupport(){};


const String PublishDiagnosticsParams::uriKey         = "uri";
const String PublishDiagnosticsParams::versionKey     = "version";
const String PublishDiagnosticsParams::diagnosticsKey = "diagnostics";

PublishDiagnosticsParams::PublishDiagnosticsParams(DocumentUri uri,
	optional<Number> version,
	vector<Diagnostic> diagnostics):
		uri(uri),
		version(version),
		diagnostics(diagnostics)
{};

PublishDiagnosticsParams::PublishDiagnosticsParams():
	uri(),
	version(),
	diagnostics()
{};

PublishDiagnosticsParams::~PublishDiagnosticsParams(){};

}
