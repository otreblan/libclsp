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

#include <libclsp/messages/responseMessage.hpp>

namespace libclsp
{

using namespace std;

const String ResponseMessage::idKey     = "id";
const String ResponseMessage::resultKey = "result";
const String ResponseMessage::errorKey  = "error";


ResponseMessage::ResponseMessage(variant<Number, String, Null> id,
	variant<String, Number, Boolean, Object, Null> result):
		id(id),
		result(result)
{};

ResponseMessage::ResponseMessage(variant<Number, String, Null> id,
	ResponseError error):
		id(id),
		error(error)
{};

ResponseMessage::ResponseMessage():
	id(),
	error()
{};

ResponseMessage::~ResponseMessage(){};


void ResponseMessage::write(Writer<StringBuffer> &writer)
{
	writer.StartObject();

	Message::partialWrite(writer);
	partialWrite(writer);

	writer.EndObject();
}

void ResponseMessage::partialWrite(Writer<StringBuffer> &writer)
{
	// id
	writer.Key(idKey.c_str());
	visit(overload
	(
		[&writer](Number ii)
		{
			writeNumber(writer, ii);
		},
		[&writer](String ii)
		{
			writer.String(ii.c_str());
		},
		[&writer](Null)
		{
			writer.Null();
		}
	), id);

	// result? or error?
	writeResultOrError(writer);
}

void ResponseMessage::writeResultOrError(Writer<StringBuffer> &writer)
{
	if(result.has_value())
	{
		// result
		writer.Key(resultKey.c_str());
		visit(overload
		(
			[&writer](String ii)
			{
				writer.String(ii.c_str());
			},
			[&writer](Number ii)
			{
				writeNumber(writer, ii);
			},
			[&writer](Boolean ii)
			{
				writer.Bool(ii);
			},
			[&writer](Object ii)
			{
				ii->write(writer);
			},
			[&writer](Null)
			{
				writer.Null();
			}
		), result.value());
	}
	else
	{
		// error
		writer.Key(errorKey.c_str());
		error.value().write(writer);
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

ResponseError::ResponseError():
	code(),
	message(),
	data()
{};

ResponseError::~ResponseError(){};

void ResponseError::write(Writer<StringBuffer> &writer)
{
	writer.StartObject();

	partialWrite(writer);

	writer.EndObject();
}

void ResponseError::partialWrite(Writer<StringBuffer> &writer)
{
	// code
	writer.Key(codeKey.c_str());
	writer.Int((int)code);

	// message
	writer.Key(messageKey.c_str());
	writer.String(message.c_str());

	// data?
	writeData(writer);
}

void ResponseError::writeData(Writer<StringBuffer> &writer)
{
	if(data.has_value())
	{
		writer.Key(dataKey.c_str());
		visit(overload
		(
			[&writer](String ii)
			{
				writer.String(ii.c_str());
			},
			[&writer](Number ii)
			{
				writeNumber(writer, ii);
			},
			[&writer](Boolean ii)
			{
				writer.Bool(ii);
			},
			[&writer](Array &ii)
			{
				writeArray(writer, ii);
			},
			[&writer](Object ii)
			{
				ii->write(writer);
			},
			[&writer](Null)
			{
				writer.Null();
			}
		), data.value());
	}
}

}

