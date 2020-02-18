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

namespace clsp
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
/// versionSupport?: Boolean
///
struct PublishDiagnosticsClientCapabilities: public ObjectT
{
private:
	const static String relatedInformationKey;
	const static String tagSupportKey;
	const static String versionSupportKey;
public:

	/// Whether the clients accepts diagnostics with related information.
	optional<Boolean> relatedInformation;

	/// Client supports the tag property to provide meta data about a
	/// diagnostic.
	/// Clients supporting tags have to handle unknown tags gracefully.
	///
	/// @since 3.15.0
	struct TagSupport: public ObjectT
	{
	private:
		const static String valueSetKey;

		struct ValueSetMaker: public ObjectT
		{
			/// The array to make
			vector<DiagnosticTag>& parentArray;

			//====================   Parsing   ==============================//

			/// This fills an ObjectInitializer
			virtual void fillInitializer(ObjectInitializer& initializer);

			// Using default isValid()

			//===============================================================//

			ValueSetMaker(vector<DiagnosticTag>& parentArray);
			virtual ~ValueSetMaker();
		};
	public:
		/// The tags supported by the client.
		vector<DiagnosticTag> valueSet;


		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//


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

	/// Whether the client interprets the version property of the
	/// `textDocument/publishDiagnostics` notification's parameter.
	///
	/// @since 3.15.0
	optional<Boolean> versionSupport;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
		optional<TagSupport> tagSupport,
		optional<Boolean> versionSupport);

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
struct PublishDiagnosticsParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String uriKey;
	const static String versionKey;
	const static String diagnosticsKey;

public:
	/// The URI for which diagnostic information is reported.
	DocumentUri uri;

	/// Optional the version number of the document the diagnostics are published
	/// for.
	///
	/// @since 3.15.0
	optional<Number> version;

	/// An array of diagnostic information items.
	vector<Diagnostic> diagnostics;

	// No parsing

	PublishDiagnosticsParams(DocumentUri uri,
		optional<Number> version,
		vector<Diagnostic> diagnostics);

	PublishDiagnosticsParams();

	virtual ~PublishDiagnosticsParams();
};

}
