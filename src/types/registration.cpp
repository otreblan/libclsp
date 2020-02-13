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

#include <libclsp/types/registration.hpp>

namespace clsp
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

Registration::Registration(){};
Registration::~Registration(){};

void Registration::partialWrite(JsonWriter &writer)
{
	// id
	writer.Key(idKey);
	writer.String(id);

	// method
	writer.Key(methodKey);
	writer.String(method);

	// registerOptions?
	if(registerOptions.has_value())
	{
		writer.Key(registerOptionsKey);
		writer.Any(*registerOptions);
	}
}


const String RegistrationParams::registrationsKey = "registrations";

RegistrationParams::RegistrationParams(vector<Registration> registrations):
	registrations(registrations)
{};

RegistrationParams::RegistrationParams(){};
RegistrationParams::~RegistrationParams(){};

void RegistrationParams::partialWrite(JsonWriter &writer)
{
	// registrations
	writer.Key(registrationsKey);
	writer.StartArray();
	for(auto& i: registrations)
	{
		writer.Object(i);
	}
	writer.EndArray();
}


const String UnRegistration::idKey              = "id";
const String UnRegistration::methodKey          = "method";

UnRegistration::UnRegistration(String id, String method):
	id(id),
	method(method)
{};

UnRegistration::UnRegistration(){};
UnRegistration::~UnRegistration(){};

void UnRegistration::partialWrite(JsonWriter &writer)
{
	// id
	writer.Key(idKey);
	writer.String(id);

	// method
	writer.Key(methodKey);
	writer.String(method);
}


const String UnRegistrationParams::unregisterationsKey = "unregisterations";

UnRegistrationParams::UnRegistrationParams(vector<UnRegistration> unregisterations):
	unregisterations(unregisterations)
{};

UnRegistrationParams::UnRegistrationParams(){};
UnRegistrationParams::~UnRegistrationParams(){};

void UnRegistrationParams::partialWrite(JsonWriter &writer)
{
	// registrations
	writer.Key(unregisterationsKey);
	writer.StartArray();
	for(auto& i: unregisterations)
	{
		writer.Object(i);
	}
	writer.EndArray();
}

}
