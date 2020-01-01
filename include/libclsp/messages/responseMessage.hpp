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

#include <libclsp/messages/jsonTypes.hpp>
#include <libclsp/messages/message.hpp>
#include <libclsp/messages/objectT.hpp>

namespace libclsp
{

using namespace std;

enum ErrorCodes
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
struct ResponseError
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

	ResponseError(ErrorCodes code, String message,
		optional<variant<String, Number, Boolean, Array, Object, Null>> data);

	virtual ~ResponseError();
};

/// A Response Message sent as a result of a request.
///
/// id: Number | String | Null
///
/// result?: String | Number | Boolean | Object | Null
///
/// error?: ResponseError
///
struct ResponseMessage: public Message
{

	// Key, value, pair types.
	// In json-rpc all keys are strings.

	const static String idKey;

	/// The request id.
	variant<Number, String, Null> id;


	const static String resultKey;

	/// The result of a request. This member is REQUIRED on success.
	/// This member MUST NOT exist if there was an error invoking the method.
	optional<variant<String, Number, Boolean, Object, Null>> result;


	const static String errorKey;

	/// The error object in case a request fails.
	optional<ResponseError> error;

	ResponseMessage(variant<Number, String, Null> id,
		optional<variant<String, Number, Boolean, Object, Null>> result);

	ResponseMessage(variant<Number, String, Null> id,
		optional<ResponseError> error);

	virtual ~ResponseMessage();
};

}
