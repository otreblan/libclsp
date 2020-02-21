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

#include <variant>
#include <optional>

#include <libclsp/types/message.hpp>

namespace clsp
{

using namespace std;

/// A notification message.
/// A processed notification message must not send a response back.
///
/// method: String
///
/// params?: any
///
struct NotificationMessage: public Message
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String methodKey;
	const static String paramsKey;

public:
	/// The method to be invoked.
	String method;

	/// The notification's params.
	optional<any> params;

	NotificationMessage(Server& server,
		String method,
		optional<any> params);

	NotificationMessage(Server& server);

	virtual ~NotificationMessage();
};

}
