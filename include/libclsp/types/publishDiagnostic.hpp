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

#include <libclsp/types/diagnostic.hpp>

namespace libclsp
{

using namespace std;

/// Publish diagnostic client capability
///
/// relatedInformation?: Boolean
///
/// tagSupport?: {
///
/// 	valueSet: DiagnosticTag[]
/// }
///
struct PublishDiagnosticsClientCapabilities
{

	const static String relatedInformationKey;

	/// Whether the clients accepts diagnostics with related information.
	optional<Boolean> relatedInformation;


	const static String tagSupportKey;

	/// Client supports the tag property to provide meta data about a
	/// diagnostic.
	/// Clients supporting tags have to handle unknown tags gracefully.
	///
	/// @since 3.15.0
	struct TagSupport
	{

		const static String valueSetKey;

		/// The tags supported by the client.
		vector<DiagnosticTag> valueSet;


		TagSupport(vector<DiagnosticTag> valueSet);

		TagSupport();

		virtual ~TagSupport();
	};

	/// Client supports the tag property to provide meta data about a
	/// diagnostic.
	/// Clients supporting tags have to handle unknown tags gracefully.
	///
	/// @since 3.15.0
	optional<TagSupport> tagSupport;


	PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
		optional<TagSupport> tagSupport);

	PublishDiagnosticsClientCapabilities();

	virtual ~PublishDiagnosticsClientCapabilities();
};

/// Publish diagnostic notification parameters.
///
/// uri: DocumentUri
///
/// version?: Number
///
/// diagnostics: Diagnostic[]
///
struct PublishDiagnosticsParams
{

	const static String uriKey;

	/// The URI for which diagnostic information is reported.
	DocumentUri uri;


	const static String versionKey;

	/// Optional the version number of the document the diagnostics are published
	/// for.
	/// 
	/// @since 3.15.0
	optional<Number> version;


	const static String diagnosticsKey;

	/// An array of diagnostic information items.
	vector<Diagnostic> diagnostics;


	PublishDiagnosticsParams(DocumentUri uri,
		optional<Number> version,
		vector<Diagnostic> diagnostics);

	PublishDiagnosticsParams();

	virtual ~PublishDiagnosticsParams();
};

}
