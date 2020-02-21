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

#include <any>
#include <functional>
#include <optional>
#include <variant>

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/message.hpp>

namespace clsp
{

using namespace std;

enum class ErrorCodes
{
	// Json-rpc error codes
	ParseError           = -32700,
	InvalidRequest       = -32600,
	MethodNotFound       = -32601,
	InvalidParams        = -32602,
	InternalError        = -32603,
	serverErrorStart     = -32099,
	serverErrorEnd       = -32000,
	ServerNotInitialized = -32002,
	UnknownErrorCode     = -32001,

	// LSP error codes
	RequestCancelled = -32800,
	ContentModified  = -32801
};

/// An object with the data of the error that ocurred
///
/// code: ErrorCodes
///
/// message: String
///
/// data?: String | Number | Boolean | Array | Object | Null
///
struct ResponseError: public ObjectT
{
	const static String codeKey;

	/// A number indicating the error type that occurred.
	ErrorCodes code;


	const static String messageKey;

	/// A string providing a short description of the error.
	String message;


	const static String dataKey;

	/// A Primitive or Structured value that contains additional
	/// information about the error. Can be omitted.
	optional<variant<String, Number, Boolean, Array, Object, Null>> data;

	// Initialize variables outside the constructor.
	// The variant constructor is not very clever.
	ResponseError(ErrorCodes code, String message,
		optional<variant<String, Number, Boolean, Array, Object, Null>> data);

	ResponseError();

	virtual ~ResponseError();

private:

	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

	/// Writer for the data pair
	void writeData(JsonWriter &writer);
};

/// A Response Message sent as a result of a request.
///
/// id: Number | String | Null
///
/// result?: any
///
/// error?: ResponseError
///
struct ResponseMessage: public Message
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String idKey;
	const static String resultKey;
	const static String errorKey;

public:
	/// The request id.
	variant<Number, String, Null> id;

	/// The result of a request. This member is REQUIRED on success.
	/// This member MUST NOT exist if there was an error invoking the method.
	optional<any> result;

	/// The error object in case a request fails.
	optional<ResponseError> error;

	ResponseMessage(Server& server,
		variant<Number, String, Null> id,
		any result);

	ResponseMessage(Server& server,
		variant<Number, String, Null> id,
		ResponseError error);

	ResponseMessage(Server& server);

	virtual ~ResponseMessage();

};

}
