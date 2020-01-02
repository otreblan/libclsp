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

#include <string>

#include <libclsp/messages/jsonTypes.hpp>
#include <libclsp/messages/objectT.hpp>

namespace libclsp
{

using namespace std;

struct Message: public ObjectT
{
	/// This is for writing the json
	virtual void write(Writer<StringBuffer> &ww);

	const static pair<String, String> jsonrpc;

	Message();
	virtual ~Message();

protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(Writer<StringBuffer> &ww);

};

}
