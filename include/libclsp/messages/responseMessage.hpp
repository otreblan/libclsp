// A C++17 library for language servers.
// Copyright © 2019 otreblan
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

#ifndef LIBCLSP_MESSAGES_RESPONSEMESSAGE_H
#define LIBCLSP_MESSAGES_RESPONSEMESSAGE_H

#include <variant>
#include <optional>

#include <libclsp/messages/jsonTypes.hpp>
#include <libclsp/messages/message.hpp>
#include <libclsp/messages/responseError.hpp>
#include <libclsp/messages/object.hpp>

namespace libclsp
{

using namespace std;

class ResponseMessage: public Message
{

private:
	// Key, value, pair types.
	// In json-rpc all keys are strings.

	const static String idKey;
	using idValue = variant<Number, String, Null>;
	using idPair  = pair<const String, idValue>;

	/// The request id.
	idPair id;


	const static String resultKey;
	using resultValue = variant<String, Number, Boolean, Object, Null>;
	using resultPair  = optional<pair<const String, resultValue>>;

	/// The result of a request. This member is REQUIRED on success.
	/// This member MUST NOT exist if there was an error invoking the method.
	resultPair result;


	const static String errorKey;
	using errorValue = ResponseError;
	using errorPair = optional<pair<const String, errorValue>>;

	/// The error object in case a request fails.
	errorPair error;

public:
	ResponseMessage(idValue _id, resultValue _result);
	virtual ~ResponseMessage();
};

}

#endif /* LIBCLSP_MESSAGES_RESPONSEMESSAGE_H */
