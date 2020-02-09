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


ResponseMessage::ResponseMessage(variant<Number, String, Null> id,
	any result,
	optional<function<void(JsonWriter& ,any&)>> resultWriter):
		id(id),
		result(result),
		resultWriter(resultWriter)
{};

ResponseMessage::ResponseMessage(variant<Number, String, Null> id,
	ResponseError error):
		id(id),
		error(error)
{};

ResponseMessage::ResponseMessage(){};
ResponseMessage::~ResponseMessage(){};


void ResponseMessage::partialWrite(JsonWriter &writer)
{
	// Parent
	Message::partialWrite(writer);

	// id
	writer.Key(idKey);
	visit(overload
	(
		[&writer](Number n)
		{
			writer.Number(n);
		},
		[&writer](String &str)
		{
			writer.String(str);
		},
		[&writer](Null)
		{
			writer.Null();
		}
	), id);

	// result? or error?
	writeResultOrError(writer);
}

void ResponseMessage::writeResultOrError(JsonWriter &writer)
{
	if(result.has_value())
	{
		// result
		writer.Key(resultKey);
		resultWriter.value()(writer, result.value());
	}
	else
	{
		// error
		writer.Key(errorKey);
		error->write(writer);
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

