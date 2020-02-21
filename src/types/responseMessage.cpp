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

#include <libclsp/types/responseMessage.hpp>

namespace clsp
{

using namespace std;

const String ResponseMessage::idKey     = "id";
const String ResponseMessage::resultKey = "result";
const String ResponseMessage::errorKey  = "error";


ResponseMessage::ResponseMessage(Server& server,
	variant<Number, String, Null> id,
	any result):
		Message(server),
		id(id),
		result(result)
{};

ResponseMessage::ResponseMessage(Server& server,
	variant<Number, String, Null> id,
	ResponseError error):
		Message(server),
		id(id),
		error(error)
{};

ResponseMessage::ResponseMessage(Server& server):
	Message(server)
{};

ResponseMessage::~ResponseMessage(){};


void ResponseMessage::partialWrite(JsonWriter &writer)
{
	// Parent
	Message::partialWrite(writer);

	// For some reason the id value has a Null option that needs to be removed
	// to use the id on the maps.
	variant<Number, String> methodId;

	// id
	writer.Key(idKey);
	visit(overload
	(
		[&writer, &methodId](Number n)
		{
			writer.Number(n);
			methodId = n;
		},
		[&writer, &methodId](String &str)
		{
			writer.String(str);
			methodId = str;
		},
		[&writer](Null)
		{
			writer.Null();
		}
	), id);

	// result?
	if(result.has_value() && !holds_alternative<Null>(id))
	{
		// Completes the request send from the client.
		String method = server.completeRequest(methodId, RequestKind::fromClient);

		optional<Capability> capability = server.getCapability(method);
		if(capability.has_value())
		{
			writer.Key(resultKey);
			capability->result->writer.value()(writer, *result);
		}
	}

	// error?
	if(error.has_value())
	{
		writer.Key(errorKey);
		writer.Object(*error);
	}
}

const String ResponseError::codeKey    = "code";
const String ResponseError::messageKey = "message";
const String ResponseError::dataKey    = "data";

ResponseError::ResponseError(ErrorCodes code, String message,
	optional<variant<String, Number, Boolean, Array, Object, Null>> data):
		code(code),
		message(message),
		data(data)
{};

ResponseError::ResponseError(){};
ResponseError::~ResponseError(){};

void ResponseError::partialWrite(JsonWriter &writer)
{
	// code
	writer.Key(codeKey);
	writer.Int((int)code);

	// message
	writer.Key(messageKey);
	writer.String(message);

	// data?
	writeData(writer);
}

void ResponseError::writeData(JsonWriter &writer)
{
	if(data.has_value())
	{
		writer.Key(dataKey);
		visit(overload
		(
			[&writer](String &str)
			{
				writer.String(str);
			},
			[&writer](Number n)
			{
				writer.Number(n);
			},
			[&writer](Boolean b)
			{
				writer.Bool(b);
			},
			[&writer](Array &a)
			{
				writer.Array(a);
			},
			[&writer](Object obj)
			{
				writer.Object(*obj);
			},
			[&writer](Null)
			{
				writer.Null();
			}
		), data.value());
	}
}

}

