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

#include <optional>

#include <libclsp/types/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// Static registration options can be used to register a feature in the
/// initialize result with a given server control ID to be able to un-register
/// the feature later on.
///
/// id?: String
///
struct StaticRegistrationOptions
{

	const static String idKey;

	/// The id used to register the request. The id can be used to deregister
	/// the request again. See also Registration#id.
	optional<String> id;


	StaticRegistrationOptions(optional<String> id);

	StaticRegistrationOptions();

	virtual ~StaticRegistrationOptions();
};

}
