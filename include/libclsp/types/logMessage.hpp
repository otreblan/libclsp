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

#include <libclsp/types/showMessage.hpp>

namespace clsp
{

using namespace std;

/// The log message notification is sent from the server to the client to
/// ask the client to log a particular message.
///
/// type: MessageType
///
/// message: String
///
struct LogMessageParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String typeKey;
	const static String messageKey;

public:
	/// The message type. See {@link MessageType}
	MessageType type;

	/// The actual message
	String message;

	// No parsing

	LogMessageParams(MessageType type, String message);

	LogMessageParams();

	virtual ~LogMessageParams();
};

}
