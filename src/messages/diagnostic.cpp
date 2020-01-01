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

#include <libclsp/messages/diagnostic.hpp>

namespace libclsp
{

using namespace std;

const String Diagnostic::rangeKey              = "range";
const String Diagnostic::severityKey           = "severity";
const String Diagnostic::codeKey               = "code";
const String Diagnostic::sourceKey             = "source";
const String Diagnostic::messageKey            = "message";
const String Diagnostic::tagsKey               = "tags";
const String Diagnostic::relatedInformationKey = "relatedInformation";

Diagnostic::Diagnostic(Range range,
	optional<DiagnosticSeverity> severity,
	optional<variant<Number, String>> code,
	optional<String> source,
	String message,
	optional<vector<DiagnosticTag>> tags,
	optional<vector<DiagnosticRelatedInformation>> relatedInformation):
		range(range),
		severity(severity),
		code(code),
		source(source),
		message(message),
		tags(tags),
		relatedInformation(relatedInformation){};

Diagnostic::~Diagnostic(){};


const String DiagnosticRelatedInformation::locationKey = "location";
const String DiagnosticRelatedInformation::messageKey  = "message";

DiagnosticRelatedInformation::DiagnosticRelatedInformation(Location location,
	String message):
		location(location),
		message(message){};

DiagnosticRelatedInformation::~DiagnosticRelatedInformation(){};

}
