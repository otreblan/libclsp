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

#include <libclsp/server/server.hpp>

namespace clsp
{

using namespace std;

void Server::startIO()
{
	// TODO
}

void Server::addCapability(Capability capability)
{
	capabilityMutex.lock();

	capabiliyMap.emplace(capability.method, capability);

	capabilityMutex.unlock();
}

optional<Capability> Server::getCapability(String method)
{
	optional<Capability> resu;

	capabilityMutex.lock_shared();

	auto capability = capabiliyMap.find(method);

	if(capability != capabiliyMap.end())
	{
		resu = capability->second;
	}
	else
	{
		resu = nullopt;
	}

	capabilityMutex.unlock_shared();

	return resu;

}

void Server::addRequest(variant<Number, String> id,
	String method,
	RequestKind kind)
{
	switch(kind)
	{
		case RequestKind::toClient:
			requestSentMutex.lock();

			requestSentMap.emplace(id, method);

			requestSentMutex.unlock();
			break;

		case RequestKind::fromClient:
			requestRecievedMutex.lock();

			requestRecievedMap.emplace(id, method);

			requestRecievedMutex.unlock();
			break;
	}
}

String Server::completeRequest(variant<Number, String> id, RequestKind kind)
{
	String resu;

	map<variant<Number, String>, String>::iterator mapIterator;

	switch(kind)
	{
		case RequestKind::toClient:
			requestSentMutex.lock();

			mapIterator = requestSentMap.find(id);
			if(mapIterator != requestSentMap.end())
			{
				resu = mapIterator->second;
				requestSentMap.erase(mapIterator);
			}

			requestSentMutex.unlock();
			break;

		case RequestKind::fromClient:
			requestRecievedMutex.lock();

			mapIterator = requestRecievedMap.find(id);
			if(mapIterator != requestRecievedMap.end())
			{
				resu = mapIterator->second;
				requestRecievedMap.erase(mapIterator);
			}

			requestRecievedMutex.unlock();
			break;
	}

	return resu;
}

Server::Server(){};
Server::~Server(){};

}
