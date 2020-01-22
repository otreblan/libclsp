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

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;

/// Server capability for DidChangeConfiguration
///
/// dynamicRegistration?: Boolean
///
struct DidChangeConfigurationClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Did change configuration notification supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DidChangeConfigurationClientCapabilities(optional<Boolean> dynamicRegistration);

	DidChangeConfigurationClientCapabilities();

	virtual ~DidChangeConfigurationClientCapabilities();

};

/// DidChangeConfiguration params
///
/// settings: Any
///
struct DidChangeConfigurationParams: public ObjectT
{
private:
	const static String settingsKey;

public:
	/// The actual changed settings
	Any settings;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	DidChangeConfigurationParams(Any settings);

	DidChangeConfigurationParams();

	virtual ~DidChangeConfigurationParams();
};

}
