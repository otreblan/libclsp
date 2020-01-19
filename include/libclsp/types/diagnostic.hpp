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

#include <variant>
#include <optional>

#include <libclsp/types/location.hpp>

namespace libclsp
{

using namespace std;

/// Represents a related message and source code location for a diagnostic.
///
/// location: Location
///
/// message: String
///
struct DiagnosticRelatedInformation: public ObjectT
{
private:
	const static String locationKey;
	const static String messageKey;

public:

	/// The location of this related diagnostic information.
	Location location;

	/// The message of this related diagnostic information.
	String message;


	//====================   Parsing   ======================================//

	/// This fills the ObjectInitializer at the top of the handler stack
	virtual void fillInitializer(JsonHandler& handler);

	// Using default isValid()

	//=======================================================================//


	DiagnosticRelatedInformation(Location location, String message);

	DiagnosticRelatedInformation();

	virtual ~DiagnosticRelatedInformation();
};

enum class DiagnosticSeverity
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

enum class DiagnosticTag
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
struct Diagnostic: public ObjectT
{
private:
	const static String rangeKey;
	const static String severityKey;
	const static String codeKey;
	const static String sourceKey;
	const static String messageKey;
	const static String tagsKey;
	const static String relatedInformationKey;

	struct TagsMaker: public ObjectT
	{

		// The object where the array is build
		Diagnostic* parent;

		//====================   Parsing   ==================================//

		/// This fills the ObjectInitializer at the top of the handler stack
		virtual void fillInitializer(JsonHandler& handler);


		// Using default isValid()

		//===================================================================//
	};

	struct RelatedInformationMaker: public ObjectT
	{

		// The object where the array is build
		Diagnostic* parent;

		//====================   Parsing   ==================================//

		/// This fills the ObjectInitializer at the top of the handler stack
		virtual void fillInitializer(JsonHandler& handler);


		// Using default isValid()

		//===================================================================//
	};

public:

	/// The range at which the message applies.
	Range range;

	/// The diagnostic's severity. Can be omitted. If omitted it is up to the
	/// client to interpret diagnostics as error, warning, info or hint.
	optional<DiagnosticSeverity> severity;

	/// The diagnostic's code, which might appear in the user interface.
	optional<variant<Number, String>> code;

	/// A human-readable string describing the source of this
	/// diagnostic, e.g. 'typescript' or 'super lint'.
	optional<String> source;

	/// The diagnostic's message.
	String message;

	/// Additional metadata about the diagnostic.
	///
	/// @since 3.15.0
	optional<vector<DiagnosticTag>> tags;

	/// An array of related diagnostic information, e.g. when symbol-names within
	/// a scope collide all definitions can be marked via this property.
	optional<vector<DiagnosticRelatedInformation>> relatedInformation;


	//====================   Parsing   ======================================//

	/// This fills the ObjectInitializer at the top of the handler stack
	virtual void fillInitializer(JsonHandler& handler);

	// Using default isValid()

	//=======================================================================//


	Diagnostic(Range range,
		optional<DiagnosticSeverity> severity,
		optional<variant<Number, String>> code,
		optional<String> source,
		String message,
		optional<vector<DiagnosticTag>> tags,
		optional<vector<DiagnosticRelatedInformation>> relatedInformation);

	Diagnostic();

	virtual ~Diagnostic();
};

}
