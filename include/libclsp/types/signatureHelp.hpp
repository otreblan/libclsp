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

#include <libclsp/types/markupContent.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace libclsp
{

using namespace std;

/// Signature Help request client capabilities.
///
/// dynamicRegistration?: Boolean;
///
/// signatureInformation?: {
///
/// 	documentationFormat?: MarkupKind[]
///
/// 	parameterInformation?: {
///
/// 		labelOffsetSupport?: Boolean
/// 	}
/// }
///
/// contextSupport?: Boolean
///
struct SignatureHelpClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether signature help supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	const static String signatureInformationKey;

	/// The client supports the following `SignatureInformation`
	/// specific properties.
	struct SignatureInformation
	{

		const static String documentationFormatKey;

		/// Client supports the follow content formats for the documentation
		/// property. The order describes the preferred format of the client.
		optional<vector<MarkupKind>> documentationFormat;


		const static String parameterInformationKey;

		/// Client capabilities specific to parameter information.
		struct ParameterInformation
		{

			const static String labelOffsetSupportKey;

			/// The client supports processing label offsets instead of a
			/// simple label string.
			///
			/// @since 3.14.0
			optional<Boolean> labelOffsetSupport;


			ParameterInformation(optional<Boolean> labelOffsetSupport);

			ParameterInformation();

			virtual ~ParameterInformation();
		};

		/// Client capabilities specific to parameter information.
		optional<ParameterInformation> parameterInformation;


		SignatureInformation(optional<vector<MarkupKind>> documentationFormat,
			optional<ParameterInformation> parameterInformation);

		SignatureInformation();

		virtual ~SignatureInformation();
	};

	/// The client supports the following `SignatureInformation`
	/// specific properties.
	optional<SignatureInformation> signatureInformation;


	const static String contextSupportKey;

	/// The client supports to send additional context information for a
	/// `textDocument/signatureHelp` request. A client that opts into
	/// contextSupport will also support the `retriggerCharacters` on
	/// `SignatureHelpOptions`.
	///
	/// @since 3.15.0
	optional<Boolean> contextSupport;


	SignatureHelpClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SignatureInformation> signatureInformation,
		optional<Boolean> contextSupport);

	SignatureHelpClientCapabilities();

	virtual ~SignatureHelpClientCapabilities();
};

/// signatureHelpProvider server capability.
///
/// triggerCharacters?: String[];
///
/// retriggerCharacters?: String[];
///
struct SignatureHelpOptions: public WorkDoneProgressOptions
{

	const static String triggerCharactersKey;

	/// The characters that trigger signature help
	/// automatically.
	optional<vector<String>> triggerCharacters;


	const static String retriggerCharactersKey;

	/// List of characters that re-trigger signature help.
	///
	/// These trigger characters are only active when signature help is already
	/// showing.
	/// All trigger characters are also counted as re-trigger characters.
	///
	/// @since 3.15.0
	optional<vector<String>> retriggerCharacters;


	SignatureHelpOptions(optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> retriggerCharacters);

	SignatureHelpOptions();

	virtual ~SignatureHelpOptions();
};

struct SignatureHelpRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public SignatureHelpOptions
{

	SignatureHelpRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> retriggerCharacters);

	SignatureHelpRegistrationOptions();

	virtual ~SignatureHelpRegistrationOptions();
};

/// Represents a parameter of a callable-signature. A parameter can
/// have a label and a doc-comment.
///
/// label: String | [Number, Number]
///
/// documentation?: String | MarkupContent
///
struct ParameterInformation
{

	const static String labelKey;

	/// The label of this parameter information.
	///
	/// Either a string or an inclusive start and exclusive end offsets within
	/// its containing signature label.
	/// (see SignatureInformation.label).
	/// The offsets are based on a UTF-16 string representation as `Position`
	/// and `Range` does.
	///
	/// *Note*: a label of type string should be a substring of its containing
	/// signature label.  Its intended use case is to highlight the parameter
	/// label part in the `SignatureInformation.label`.
	variant<String, array<Number, 2>> label;


	const static String documentationKey;

	/// The human-readable doc-comment of this parameter. Will be shown
	/// in the UI but can be omitted.
	optional<variant<String, MarkupContent>> documentation;


	ParameterInformation(variant<String, array<Number, 2>> label,
		optional<variant<String, MarkupContent>> documentation);

	ParameterInformation();

	virtual ~ParameterInformation();
};

/// Represents the signature of something callable. A signature
/// can have a label, like a function-name, a doc-comment, and
/// a set of parameters.
///
/// label: String
///
/// documentation?: String | MarkupContent
///
/// parameters?: ParameterInformation[]
///
struct SignatureInformation
{

	const static String labelKey;

	/// The label of this signature. Will be shown in
	/// the UI.
	String label;


	const static String documentationKey;

	/// The human-readable doc-comment of this signature. Will be shown
	/// in the UI but can be omitted.
	optional<variant<String, MarkupContent>> documentation;


	const static String parametersKey;

	/// The parameters of this signature.
	optional<vector<ParameterInformation>> parameters;


	SignatureInformation(String label,
		optional<variant<String, MarkupContent>> documentation,
		optional<vector<ParameterInformation>> parameters);

	SignatureInformation();

	virtual ~SignatureInformation();
};

/// Signature help represents the signature of something
/// callable. There can be multiple signature but only one
/// active and only one active parameter.
///
/// signatures: SignatureInformation[];
///
/// activeSignature?: Number;
///
/// activeParameter?: Number;
///
struct SignatureHelp
{

	const static String signaturesKey;

	/// One or more signatures.
	vector<SignatureInformation> signatures;


	const static String activeSignatureKey;

	/// The active signature. If omitted or the value lies outside the
	/// range of `signatures` the value defaults to zero or is ignored if
	/// `signatures.size() == 0`. Whenever possible implementors should
	/// make an active decision about the active signature and shouldn't
	/// rely on a default value.
	/// In future version of the protocol this property might become
	/// mandatory to better express this.
	optional<Number> activeSignature;


	const static String activeParameterKey;

	/// The active parameter of the active signature. If omitted or the value
	/// lies outside the range of `signatures[activeSignature].parameters`
	/// defaults to 0 if the active signature has parameters. If
	/// the active signature has no parameters it is ignored.
	/// In future version of the protocol this property might become
	/// mandatory to better express the active parameter if the
	/// active signature does have any.
	optional<Number> activeParameter;


	SignatureHelp(vector<SignatureInformation> signatures,
		optional<Number> activeSignature,
		optional<Number> activeParameter);

	SignatureHelp();

	virtual ~SignatureHelp();
};

/// How a signature help was triggered.
///
/// @since 3.15.0
enum class SignatureHelpTriggerKind
{
	/// Signature help was invoked manually by the user or by a command.
	Invoked = 1,

	/// Signature help was triggered by a trigger character.
	TriggerCharacter = 2,

	/// Signature help was triggered by the cursor moving or by the document
	/// content changing.
	ContentChange = 3
};

/// Additional information about the context in which a signature help request
/// was triggered.
///
/// @since 3.15.0
struct SignatureHelpContext
{

	const static String triggerKindKey;

	/// Action that caused signature help to be triggered.
	SignatureHelpTriggerKind triggerKind;


	const static String triggerCharacterKey;

	/// Character that caused signature help to be triggered.
	///
	/// This is undefined when
	/// `triggerKind != SignatureHelpTriggerKind.TriggerCharacter`
	optional<String> triggerCharacter;


	const static String isRetriggerKey;

	/// `true` if signature help was already showing when it was triggered.
	///
	/// Retriggers occur when the signature help is already active and can be
	/// caused by actions such as typing a trigger character, a cursor move, or
	/// document content changes.
	Boolean isRetrigger;


	const static String activeSignatureHelpKey;

	/// The currently active `SignatureHelp`.
	///
	/// The `activeSignatureHelp` has its `SignatureHelp.activeSignature` field
	/// updated based on the user navigating through available signatures.
	optional<SignatureHelp> activeSignatureHelp;


	SignatureHelpContext(SignatureHelpTriggerKind triggerKind,
		optional<String> triggerCharacter,
		Boolean isRetrigger,
		optional<SignatureHelp> activeSignatureHelp);

	SignatureHelpContext();

	virtual ~SignatureHelpContext();
};

/// Signature help request parameters
///
/// context?: SignatureHelpContext;
///
struct SignatureHelpParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams
{

	// FIXME:
	// Even if the struct is not parseable this functions must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String contextKey;

	/// The signature help context. This is only available if the client
	/// specifies to send this using the client capability
	/// `textDocument.signatureHelp.contextSupport == true`
	///
	/// @since 3.15.0
	optional<SignatureHelpContext> context;


	SignatureHelpParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<SignatureHelpContext> context);

	SignatureHelpParams();

	virtual ~SignatureHelpParams();
};
}
