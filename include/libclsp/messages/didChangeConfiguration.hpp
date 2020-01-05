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

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// Server capability for DidChangeConfiguration
///
/// dynamicRegistration?: Boolean
///
struct DidChangeConfigurationClientCapabilities
{
	const static String dynamicRegistrationKey;

	/// Did change configuration notification supports dynamic registration.
	optional<Boolean> dynamicRegistration;


	DidChangeConfigurationClientCapabilities(optional<Boolean> dynamicRegistration);
	virtual ~DidChangeConfigurationClientCapabilities();

};

/// DidChangeConfiguration params
///
/// settings: Any
///
struct DidChangeConfigurationParams
{
	const static String settingsKey;

	/// The actual changed settings
	Any settings;


	DidChangeConfigurationParams(Any settings);
	virtual ~DidChangeConfigurationParams();
};

}
