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

#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/staticRegistration.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// DocumentColor request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentColorClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether document color supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	DocumentColorClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentColorClientCapabilities();

	virtual ~DocumentColorClientCapabilities();
};

using DocumentColorOptions = WorkDoneProgressOptions; // No parsing

struct DocumentColorRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public StaticRegistrationOptions,
	public DocumentColorOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	DocumentColorRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id,
		optional<Boolean> workDoneProgress);

	DocumentColorRegistrationOptions();

	virtual ~DocumentColorRegistrationOptions();
};

/// DocumentColor request parameters
///
/// textDocument: TextDocumentIdentifier
///
struct DocumentColorParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{
private:
	const static String textDocumentKey;

public:
	/// The text document.
	TextDocumentIdentifier textDocument;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//

	// No writing

	DocumentColorParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument);

	DocumentColorParams();

	virtual ~DocumentColorParams();
};

/// Represents a color in RGBA space.
///
/// red: Number
///
/// green: Number
///
/// blue: Number
///
/// alpha: Number
///
struct Color: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String redKey;
	const static String greenKey;
	const static String blueKey;
	const static String alphaKey;

public:
	/// The red component of this color in the range [0-1].
	Number red;

	/// The green component of this color in the range [0-1].
	Number green;

	/// The blue component of this color in the range [0-1].
	Number blue;

	/// The alpha component of this color in the range [0-1].
	Number alpha;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	Color(Number red, Number green, Number blue, Number alpha);

	Color();

	virtual ~Color();
};

/// Part of the Document color response
///
/// range: Range
///
/// color: Color
///
struct ColorInformation: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String rangeKey;
	const static String colorKey;

public:
	/// The range in the document where this color appears.
	Range range;

	/// The actual color value for this color range.
	Color color;

	// No parsing

	ColorInformation(Range range, Color color);

	ColorInformation();

	virtual ~ColorInformation();
};

}
