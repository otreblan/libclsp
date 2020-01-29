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

#include <libclsp/types/didChangeConfiguration.hpp>
#include <libclsp/types/genericObject.hpp>

namespace clsp
{

using namespace std;

const String DidChangeConfigurationClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

DidChangeConfigurationClientCapabilities::
	DidChangeConfigurationClientCapabilities(optional<Boolean> dynamicRegistration):
		dynamicRegistration(dynamicRegistration)
{};

DidChangeConfigurationClientCapabilities::
	DidChangeConfigurationClientCapabilities()
{};

DidChangeConfigurationClientCapabilities::
	~DidChangeConfigurationClientCapabilities()
{};

void DidChangeConfigurationClientCapabilities::
	fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// dynamicRegistration?:
	setterMap.emplace(
		dynamicRegistrationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				dynamicRegistration = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// This
	initializer.object = this;
}


const String DidChangeConfigurationParams::settingsKey = "settings";

DidChangeConfigurationParams::DidChangeConfigurationParams(Any settings):
	settings(settings)
{};

DidChangeConfigurationParams::DidChangeConfigurationParams(){};
DidChangeConfigurationParams::~DidChangeConfigurationParams(){};

void DidChangeConfigurationParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// settings
	setterMap.emplace(
		settingsKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				settings = str;
				neededMap[settingsKey] = true;
			},

			// Number
			[this, &neededMap](Number n)
			{
				settings = n;
				neededMap[settingsKey] = true;
			},

			// Boolean
			[this, &neededMap](Boolean b)
			{
				settings = b;
				neededMap[settingsKey] = true;
			},

			// Null
			[this, &neededMap]()
			{
				settings = Null();
				neededMap[settingsKey] = true;
			},

			// Array
			[this, handler, &neededMap]()
			{
				settings = Array();

				auto* maker = new ArrayMaker(get<Array>(settings));

				handler->pushInitializer();
				maker->fillInitializer(handler->objectStack.top());

				neededMap[settingsKey] = true;
			},

			// Object
			[this, handler, &neededMap]()
			{
				settings = Object(new GenericObject());

				handler->pushInitializer();
				get<Object>(settings)->fillInitializer(handler->objectStack.top());

				neededMap[settingsKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(settingsKey, 0);

	// This
	initializer.object = this;
}

}
