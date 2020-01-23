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

#include <libclsp/types/workspaceSymbol.hpp>

namespace libclsp
{

using namespace std;

const String WorkspaceSymbolClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String WorkspaceSymbolClientCapabilities::
	symbolKindKey          = "symbolKind";

WorkspaceSymbolClientCapabilities::
	WorkspaceSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind):
			dynamicRegistration(dynamicRegistration),
			symbolKind(symbolKind)
{};

WorkspaceSymbolClientCapabilities::WorkspaceSymbolClientCapabilities(){};
WorkspaceSymbolClientCapabilities::~WorkspaceSymbolClientCapabilities(){};

void WorkspaceSymbolClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// symbolKind?:
	setterMap.emplace(
		symbolKindKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				symbolKind.emplace();

				handler->preFillInitializer();
				symbolKind->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// This
	initializer.object = this;
}

const String WorkspaceSymbolClientCapabilities::SymbolKind::
	valueSetKey = "valueSet";

WorkspaceSymbolClientCapabilities::SymbolKind::
	SymbolKind(optional<vector<libclsp::SymbolKind>> valueSet):
		valueSet(valueSet)
{};

WorkspaceSymbolClientCapabilities::SymbolKind::SymbolKind(){};
WorkspaceSymbolClientCapabilities::SymbolKind::~SymbolKind(){};

void WorkspaceSymbolClientCapabilities::SymbolKind::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// valueSet?:
	setterMap.emplace(
		valueSetKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{
				valueSet.emplace();

				auto* maker = new ValueSetMaker(*this);

				handler->preFillInitializer();
				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{}
		}
	);

	// This
	initializer.object = this;
}

WorkspaceSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	ValueSetMaker(SymbolKind& parent):
		parent(parent)
{};

WorkspaceSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	~ValueSetMaker()
{};

void WorkspaceSymbolClientCapabilities::SymbolKind::ValueSetMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;
	auto& Vector = parent.valueSet.value();

	// Value setters

	// SymbolKind[]
	extraSetter =
	{
		// String
		{},

		// Number
		[&Vector](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				Vector.emplace_back((libclsp::SymbolKind)i);
			}

			// Nothing is added by default

		},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		{}
	};

	// This
	initializer.object = this;
}

const String WorkspaceSymbolParams::queryKey = "query";

WorkspaceSymbolParams::WorkspaceSymbolParams(
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	String query):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		query(query)
{};

WorkspaceSymbolParams::WorkspaceSymbolParams(){};
WorkspaceSymbolParams::~WorkspaceSymbolParams(){};

void WorkspaceSymbolParams::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Parents
	WorkDoneProgressParams::fillInitializer(initializer);
	PartialResultParams::fillInitializer(initializer);

	// Value setters

	// query:
	setterMap.emplace(
		queryKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				query = str;
				neededMap[queryKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(queryKey, 0);

	// This
	initializer.object = this;
}

}
