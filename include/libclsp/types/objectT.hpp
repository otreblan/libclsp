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

#include <functional>

#include <libclsp/server/jsonHandler.hpp>
#include <libclsp/server/jsonWriter.hpp>

namespace clsp
{

using namespace std;
using namespace rapidjson;

struct JsonHandler;

class ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	/// This is for writing the json
	void write(JsonWriter &writer);

	/// This checks if the JsonHandler called all necesary keys
	virtual bool isValid(JsonHandler& handler);

	ObjectT();
	virtual ~ObjectT();
};

}
