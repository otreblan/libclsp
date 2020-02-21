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

#include <libclsp/types/notificationMessage.hpp>

namespace clsp
{

using namespace std;

const String NotificationMessage::methodKey = "method";
const String NotificationMessage::paramsKey = "params";

NotificationMessage::NotificationMessage(Server& server,
	String method,
	optional<any> params):
		Message(server),
		method(method),
		params(params)
{};

NotificationMessage::NotificationMessage(Server& server):
	Message(server)
{};

NotificationMessage::~NotificationMessage(){};

void NotificationMessage::partialWrite(JsonWriter &writer)
{
	// Parent
	Message::partialWrite(writer);

	// method
	writer.Key(methodKey);
	writer.String(method);

	// params?
	if(params.has_value())
	{
		optional<Capability> capability = server.getCapability(method);
		if(capability.has_value())
		{
			writer.Key(paramsKey);
			capability->params.writer.value()(writer, *params);
		}
	}
}

}
