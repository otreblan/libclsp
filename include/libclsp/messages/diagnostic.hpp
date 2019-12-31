// A C++17 library for language servers.
// Copyright © 2019 otreblan
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

#include <variant>
#include <optional>

#include <libclsp/messages/location.hpp>

namespace libclsp
{

using namespace std;

/// Represents a related message and source code location for a diagnostic.
///
/// location: Location
///
/// message: String
///
struct DiagnosticRelatedInformation
{
	const static String locationKey;

	/// The location of this related diagnostic information.
	Location location;


	const static String messageKey;

	/// The message of this related diagnostic information.
	String message;

	DiagnosticRelatedInformation(Location location, String message);

	virtual ~DiagnosticRelatedInformation();
};

enum DiagnosticSeverity
{
	/// Reports an error.
	Error = 1,

	/// Reports a warning.
	Warning = 2,

	/// Reports an information.
	Information = 3,

	/// Reports a hint.
	Hint = 4
};

enum DiagnosticTag
{
	/// Unused or unnecessary code.
	///
	/// Clients are allowed to render diagnostics with this tag faded out
	/// instead of having an error squiggle.
	Unnecessary = 1,

	/// Deprecated or obsolete code.
	///
	/// Clients are allowed to rendered diagnostics with this tag strike through.
	Deprecated = 2
};

/// Represents a diagnostic, such as a compiler error or warning.
///
/// range: Range
///
/// severity?: DiagnosticSeverity
///
/// code?: Number | String
///
/// source?: String
///
/// message: String
///
/// tags?: DiagnosticTag[]
///
/// relatedInformation?: DiagnosticRelatedInformation[]
///
struct Diagnostic
{
	const static String rangeKey;

	/// The range at which the message applies.
	Range range;


	const static String severityKey;

	/// The diagnostic's severity. Can be omitted. If omitted it is up to the
	/// client to interpret diagnostics as error, warning, info or hint.
	optional<DiagnosticSeverity> severity;


	const static String codeKey;

	/// The diagnostic's code, which might appear in the user interface.
	optional<variant<Number, String>> code;


	const static String sourceKey;

	/// A human-readable string describing the source of this
	/// diagnostic, e.g. 'typescript' or 'super lint'.
	optional<String> source;


	const static String messageKey;

	/// The diagnostic's message.
	String message;


	const static String tagsKey;

	/// Additional metadata about the diagnostic.
	///
	/// @since 3.15.0
	optional<vector<DiagnosticTag>> tags;


	const static String relatedInformationKey;

	/// An array of related diagnostic information, e.g. when symbol-names within
	/// a scope collide all definitions can be marked via this property.
	optional<vector<DiagnosticRelatedInformation>> relatedInformation;

	Diagnostic(Range range,
		optional<DiagnosticSeverity> severity,
		optional<variant<Number, String>> code,
		optional<String> source,
		String message,
		optional<vector<DiagnosticTag>> tags,
		optional<vector<DiagnosticRelatedInformation>> relatedInformation);

	virtual ~Diagnostic();
};

}
