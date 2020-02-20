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

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/objectT.hpp>
#include <libclsp/server/server.hpp>

namespace clsp
{

using namespace std;

struct Message: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

	/// A reference to the lsp server
	Server& server;

public:
	const static pair<String, String> jsonrpc;

	Message(Server& server);

	virtual ~Message();
};

}
