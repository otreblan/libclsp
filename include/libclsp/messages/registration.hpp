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

/// General parameters to register for a capability
///
/// id: String
///
/// method: String
///
/// registerOptions?: Any
///
struct Registration
{

	const static String idKey;

	/// The id used to register the request. The id can be used to deregister
	/// the request again.
	String id;


	const static String methodKey;

	/// The method / capability to register for.
	String method;


	const static String registerOptionsKey;

	/// Options necessary for the registration.
	optional<Any> registerOptions;


	Registration(String id, String method, optional<Any> registerOptions);

	virtual ~Registration();
};

/// The client/registerCapability request is sent from the server
/// to the client to register for a new capability on the client side.
///
/// registrations: Registration[]
///
struct RegistrationParams
{

	const static String registrationsKey;

	vector<Registration> registrations;

	RegistrationParams(vector<Registration> registrations);
	virtual ~RegistrationParams();
};

}
