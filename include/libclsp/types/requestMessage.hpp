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

namespace libclsp
{

using namespace std;


/// A request message to describe a request between the client and the server.
///
/// id: Number | String
///
/// method: String
///
/// params?: any
///
struct RequestMessage: public Message
{

	const static String idKey;

	/// The request id.
	variant<Number, String> id;


	const static String methodKey;

	/// The method to be invoked.
	String method;


	const static String paramsKey;

	/// The method's params.
	optional<any> params;

	optional<function<void(any&, Writer<StringBuffer>&)>> paramsWriter;


	RequestMessage(variant<Number, String> id,
		String method,
		optional<any> params,
		optional<function<void(any&, Writer<StringBuffer>&)>> paramsWriter);

	RequestMessage();

	virtual ~RequestMessage();
};

}
