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

#include <libclsp/messages/registration.hpp>

namespace libclsp
{

using namespace std;

const String Registration::idKey              = "id";
const String Registration::methodKey          = "method";
const String Registration::registerOptionsKey = "registerOptions";

Registration::Registration(String id, String method, optional<Any> registerOptions):
	id(id),
	method(method),
	registerOptions(registerOptions)
{};

Registration::Registration():
	id(),
	method(),
	registerOptions()
{};

Registration::~Registration(){};


const String RegistrationParams::registrationsKey = "registrations";

RegistrationParams::RegistrationParams(vector<Registration> registrations):
	registrations(registrations)
{};

RegistrationParams::RegistrationParams():
	registrations()
{};

RegistrationParams::~RegistrationParams(){};


const String UnRegistration::idKey              = "id";
const String UnRegistration::methodKey          = "method";

UnRegistration::UnRegistration(String id, String method):
	id(id),
	method(method)
{};

UnRegistration::UnRegistration():
	id(),
	method()
{};

UnRegistration::~UnRegistration(){};


const String UnRegistrationParams::unregisterationsKey = "unregisterations";

UnRegistrationParams::UnRegistrationParams(vector<UnRegistration> unregisterations):
	unregisterations(unregisterations)
{};

UnRegistrationParams::UnRegistrationParams():
	unregisterations()
{};

UnRegistrationParams::~UnRegistrationParams(){};

}
