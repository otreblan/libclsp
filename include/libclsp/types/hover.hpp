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

#include <optional>

#include <libclsp/types/markupContent.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// Hover request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// contentFormat?: MarkupKind[]
///
struct HoverClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String contentFormatKey;

	struct ContentFormatMaker: public ObjectT
	{
		vector<MarkupKind> &parentArray;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		ContentFormatMaker(vector<MarkupKind> &parentArray);

		virtual ~ContentFormatMaker();
	};
public:
	/// Whether hover supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	/// Client supports the follow content formats for the content
	/// property. The order describes the preferred format of the client.
	optional<vector<MarkupKind>> contentFormat;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	HoverClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<vector<MarkupKind>> contentFormat);

	HoverClientCapabilities();

	virtual ~HoverClientCapabilities();
};

/// Hover request server capabilities
using HoverOptions = WorkDoneProgressOptions; // No parsing

/// Hover request registration options
struct HoverRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public HoverOptions
{

	// No parsing

	HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
		optional<ProgressToken> workDoneProgress);

	HoverRegistrationOptions();

	virtual ~HoverRegistrationOptions();
};

/// textDocument/hover parameters
struct HoverParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams
{

	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	HoverParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken);

	HoverParams();

	virtual ~HoverParams();
};

struct [[deprecated("Use MarkupContent instead.")]] _MarkedString
{
private:
	const static String languageKey;
	const static String valueKey;

public:
	String language;

	String value;

	// No parsing

	_MarkedString(String language, String value);

	_MarkedString();

	virtual ~_MarkedString();
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/// MarkedString can be used to render human readable text. It is either a
/// markdown string or a code-block that provides a language and a code snippet.
/// The language identifier is semantically equal to the optional language
/// identifier in fenced code blocks in GitHub issues. See
/// https://help.github.com/articles/creating-and-highlighting-code-blocks/#syntax-highlighting
///
/// Note that markdown strings will be sanitized - that means html will be
/// escaped.
using MarkedString [[deprecated("Use MarkupContent instead.")]] = variant<String, _MarkedString>;

#pragma GCC diagnostic pop


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/// The result of a hover request.
///
/// contents: MarkedString | MarkedString[] | MarkupContent
///
/// range?: Range
///
struct Hover
{
private:
	const static String contentsKey;
	const static String rangeKey;

public:
	/// The hover's content
	variant<MarkedString, vector<MarkedString>, MarkupContent> contents;

	/// An optional range is a range inside a text document
	/// that is used to visualize a hover, e.g. by changing the background color.
	optional<Range> range;

	// No parsing

	[[deprecated("Use MarkupContent instead.")]]
	Hover(variant<MarkedString, vector<MarkedString>, MarkupContent> contents,
		optional<Range> range);

	Hover(MarkupContent contents, optional<Range> range);

	Hover();

	virtual ~Hover();
};

#pragma GCC diagnostic pop

}
