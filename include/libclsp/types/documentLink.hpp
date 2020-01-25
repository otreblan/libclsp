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

#include <libclsp/types/command.hpp>
#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;


/// DocumentLink request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// tooltipSupport?: Boolean
///
struct DocumentLinkClientCapabilities
{

	const static String dynamicRegistrationKey;

	/// Whether code action supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	const static String tooltipSupportKey;

	/// Whether the client supports the `tooltip` property on `DocumentLink`.
	///
	/// @since 3.15.0
	optional<Boolean> tooltipSupport;


	DocumentLinkClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> tooltipSupport);

	DocumentLinkClientCapabilities();

	virtual ~DocumentLinkClientCapabilities();
};

/// DocumentLink server capability
///
/// codeLensKinds?: DocumentLinkKind[]
///
struct DocumentLinkOptions: public WorkDoneProgressOptions
{

	const static String resolveProviderKey;

	/// Code lens has a resolve provider as well.
	optional<Boolean> resolveProvider;


	DocumentLinkOptions(optional<ProgressToken> workDoneProgress,
		optional<Boolean> resolveProvider);

	DocumentLinkOptions();

	virtual ~DocumentLinkOptions();
};

struct DocumentLinkRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentLinkOptions
{

	DocumentLinkRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress,
		optional<Boolean> resolveProvider);

	DocumentLinkRegistrationOptions();

	virtual ~DocumentLinkRegistrationOptions();
};

/// Params for the DocumentLink Request
///
/// textDocument: TextDocumentIdentifier;
///
struct DocumentLinkParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{

	// FIXME:
	// Even if the struct is not parseable this function must be declared
	// because virtual inheritance
	virtual void fillInitializer(ObjectInitializer&){};

	const static String textDocumentKey;

	/// The document to provide document links for.
	TextDocumentIdentifier textDocument;


	DocumentLinkParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument);

	DocumentLinkParams();

	virtual ~DocumentLinkParams();
};

/// A document link is a range in a text document that links to an internal or
/// external resource, like another text document or a web site.
///
/// range: Range
///
/// target?: DocumentUri
///
/// tooltip?: String
///
/// data?: Any
///
struct DocumentLink
{

	const static String rangeKey;;

	/// The range this link applies to.
	Range range;


	const static String targetKey;

	/// The uri this link points to. If missing a resolve request is sent
	/// later.
	optional<DocumentUri> target;


	const static String tooltipKey;;

	/// The tooltip text when you hover over this link.
	///
	/// If a tooltip is provided, is will be displayed in a string that
	/// includes instructions on how to trigger the link, such as
	/// `{0} (ctrl + click)`. The specific instructions vary depending on OS,
	/// user settings, and localization.
	///
	/// @since 3.15.0
	optional<String> tooltip;


	const static String dataKey;

	/// A data entry field that is preserved on a document link between a
	/// DocumentLinkRequest and a DocumentLinkResolveRequest.
	optional<Any> data;


	DocumentLink(Range range,
		optional<DocumentUri> target,
		optional<String> tooltip,
		optional<Any> data);

	DocumentLink();

	virtual ~DocumentLink();
};

}
