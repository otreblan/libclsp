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

enum class RequestKind
{
	/// The request waits a response from the client.
	toClient,

	/// The request waits a response from the server.
	fromClient
};

class Server
{
private:
	/// A map with the capabilities that the server supports.
	map<String, Capability> capabiliyMap;

	/// A mutex for the capability map.
	mutable shared_mutex capabilityMutex;


	/// A map with the requests send to the client.
	/// The key is the id and the value is the method.
	map<variant<Number, String>, String> requestSentMap;

	/// A mutex for the requestSent map.
	mutable shared_mutex requestSentMutex;


	/// A map with the requests recieved from the client.
	/// The key is the id and the value is the method.
	map<variant<Number, String>, String> requestRecievedMap;

	/// A mutex for the requestSent map.
	mutable shared_mutex requestRecievedMutex;

public:
	/// This starts the server and seeks for the Initialize request.
	void startIO();

	/// This function adds a new capability to the server, but doesn't
	/// send the client/registerCapability request.
	void addCapability(Capability capability);

	/// Returns the capability of the method given. If no capability is found
	/// the optional<> is set to nullopt.
	optional<Capability> getCapability(String method);


	/// Adds a request to one of the two request maps.
	void addRequest(variant<Number, String> id, String method, RequestKind kind);

	/// Completes a request and returns the method name.
	String completeRequest(variant<Number, String> id, RequestKind kind);

	Server();
	virtual ~Server();
};

}
