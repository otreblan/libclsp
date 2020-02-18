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

#include <libclsp/types/location.hpp>
#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/workDoneProgress.hpp>

namespace clsp
{

using namespace std;

/// A symbol kind.
enum class SymbolKind
{
	File          = 1,
	Module        = 2,
	Namespace     = 3,
	Package       = 4,
	Class         = 5,
	Method        = 6,
	Property      = 7,
	Field         = 8,
	Constructor   = 9,
	Enum          = 10,
	Interface     = 11,
	Function      = 12,
	Variable      = 13,
	Constant      = 14,
	String        = 15,
	Number        = 16,
	Boolean       = 17,
	Array         = 18,
	Object        = 19,
	Key           = 20,
	Null          = 21,
	EnumMember    = 22,
	Struct        = 23,
	Event         = 24,
	Operator      = 25,
	TypeParameter = 26
};

/// DocumentSymbol request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// symbolKind?: {
///
/// 	valueSet?: SymbolKind[]
/// }
///
/// hierarchicalDocumentSymbolSupport?: Boolean
///
struct DocumentSymbolClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String symbolKindKey;
	const static String hierarchicalDocumentSymbolSupportKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	/// Specific capabilities for the `SymbolKind` in the
	/// `textDocument/documentSymbol` request.
	struct SymbolKind: public ObjectT
	{
	private:
		const static String valueSetKey;

		struct ValueSetMaker: public ObjectT
		{
			vector<clsp::SymbolKind> &parentArray;

			//====================   Parsing   ==============================//

			/// This fills an ObjectInitializer
			virtual void fillInitializer(ObjectInitializer& initializer);

			// Using default isValid()

			//===============================================================//

			ValueSetMaker(vector<clsp::SymbolKind> &parentArray);

			virtual ~ValueSetMaker();
		};
	public:
		/// The symbol kind values the client supports. When this
		/// property exists the client also guarantees that it will
		/// handle values outside its set gracefully and falls back
		/// to a default value when unknown.
		///
		/// If this property is not present the client only supports
		/// the symbol kinds from `File` to `Array` as defined in
		/// the initial version of the protocol.
		optional<vector<clsp::SymbolKind>> valueSet;


		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//


		SymbolKind(optional<vector<clsp::SymbolKind>> valueSet);

		SymbolKind();

		virtual ~SymbolKind();
	};

	/// Specific capabilities for the `SymbolKind` in the
	/// `textDocument/documentSymbol` request.
	optional<SymbolKind> symbolKind;

	/// The client supports hierarchical document symbols.
	optional<Boolean> hierarchicalDocumentSymbolSupport;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DocumentSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind,
		optional<Boolean> hierarchicalDocumentSymbolSupport);

	DocumentSymbolClientCapabilities();

	virtual ~DocumentSymbolClientCapabilities();
};

/// Find references server capability
using DocumentSymbolOptions = WorkDoneProgressOptions; // No parsing

struct DocumentSymbolRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentSymbolOptions
{
protected:
	// TODO
	// without this the compilation fails
	virtual void partialWrite(JsonWriter&){};

public:

	// No parsing

	DocumentSymbolRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentSymbolRegistrationOptions();

	virtual ~DocumentSymbolRegistrationOptions();
};

/// Document highlight request parameters
///
/// textDocument: TextDocumentIdentifier
///
struct DocumentSymbolParams:
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


	DocumentSymbolParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument);

	DocumentSymbolParams();

	virtual ~DocumentSymbolParams();
};


/// Represents programming constructs like variables, classes, interfaces etc.
/// that appear in a document. Document symbols can be hierarchical and they
/// have two ranges: one that encloses its definition and one that points to
/// its most interesting range, e.g. the range of an identifier.
///
/// name: String
///
/// detail?: String
///
/// kind: SymbolKind
///
/// deprecated?: Boolean
///
/// range: Range
///
/// selectionRange: Range
///
/// children?: DocumentSymbol[]
///
struct DocumentSymbol
{
private:
	const static String nameKey;
	const static String detailKey;
	const static String kindKey;
	const static String deprecatedKey;
	const static String rangeKey;
	const static String selectionRangeKey;
	const static String childrenKey;

public:
	/// The name of this symbol. Will be displayed in the user interface and
	/// therefore must not be an empty string or a string only consisting of
	/// white spaces.
	String name;

	/// More detail for this symbol, e.g the signature of a function.
	optional<String> detail;

	/// The kind of this symbol.
	SymbolKind kind;

	/// Indicates if this symbol is deprecated.
	optional<Boolean> deprecated;

	/// The range enclosing this symbol not including leading/trailing
	/// whitespace but everything else like comments. This information is
	/// typically used to determine if the clients cursor is inside the symbol
	/// to reveal in the symbol in the UI.
	Range range;

	/// The range that should be selected and revealed when this symbol is
	/// being picked, e.g the name of a function.  Must be contained by the `range`.
	Range selectionRange;

	/// Children of this symbol, e.g. properties of a class.
	optional<vector<DocumentSymbol>> children;

	// No parsing

	DocumentSymbol(String name,
		optional<String> detail,
		SymbolKind kind,
		optional<Boolean> deprecated,
		Range range,
		Range selectionRange,
		optional<vector<DocumentSymbol>> children);

	DocumentSymbol();

	virtual ~DocumentSymbol();
};

/// Represents information about programming constructs like variables,
/// classes, interfaces etc.
///
/// name: String
///
/// kind: SymbolKind
///
/// deprecated?: Boolean
///
/// location: Location
///
/// containerName?: String
///
struct SymbolInformation
{
private:
	const static String nameKey;
	const static String kindKey;
	const static String deprecatedKey;
	const static String locationKey;
	const static String containerNameKey;

public:
	/// The name of this symbol.
	String name;

	/// The kind of this symbol.
	SymbolKind kind;

	/// Indicates if this symbol is deprecated.
	optional<Boolean> deprecated;

	/// The location of this symbol. The location's range is used by a tool
	/// to reveal the location in the editor. If the symbol is selected in the
	/// tool the range's start information is used to position the cursor. So
	/// the range usually spans more then the actual symbol's name and does
	/// normally include things like visibility modifiers.
	///
	/// The range doesn't have to denote a node range in the sense of a abstract
	/// syntax tree. It can therefore not be used to re-construct a hierarchy of
	/// the symbols.
	Location location;

	/// The name of the symbol containing this symbol. This information is for
	/// user interface purposes (e.g. to render a qualifier in the user
	/// interface if necessary). It can't be used to re-infer a hierarchy for
	/// the document symbols.
	optional<String> containerName;

	// No parsing

	SymbolInformation(String name,
		SymbolKind kind,
		optional<Boolean> deprecated,
		Location location,
		optional<String> containerName);

	SymbolInformation();

	virtual ~SymbolInformation();
};

}
