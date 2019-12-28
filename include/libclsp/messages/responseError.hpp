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

}
