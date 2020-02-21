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

#include <map>
#include <shared_mutex>

#include <libclsp/server/jsonHandler.hpp>
#include <libclsp/server/capability.hpp>

namespace clsp
{

using namespace std;

class Server
{
private:
	map<String, Capability> capabiliyMap;

	mutable shared_mutex capabilityLock;

public:
	/// This starts the server and seeks for the Initialize request.
	void startIO();

	/// This function adds a new capability to the server, but doesn't
	/// send the client/registerCapability request.
	void addCapability(Capability capability);

	/// Returns the capability of the method given. If no capability is found
	/// the optional<> is set to nullopt.
	optional<Capability> getCapability(String method);

	Server();
	virtual ~Server();
};

}
