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

#include <rapidjson/writer.h>

#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/server/jsonHandler.hpp>

namespace libclsp
{

using namespace std;
using namespace rapidjson;

struct JsonHandler;

class ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(Writer<StringBuffer> &writer);

public:

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	/// This is for writing the json
	virtual void write(Writer<StringBuffer> &writer);

	/// This checks if the JsonHandler called all necesary keys
	virtual bool isValid(JsonHandler& handler);

	ObjectT();
	virtual ~ObjectT();
};

/// Copied from https://arne-mertz.de/2018/05/overload-build-a-variant-visitor-on-the-fly/
template<class ...Fs>
struct overload : Fs...
{
	overload(Fs const&... fs): Fs{fs}...{};

	using Fs::operator()...;
};

/// Number json writer
void writeNumber(Writer<StringBuffer> &writer, Number n);

/// Array json writer
void writeArray(Writer<StringBuffer> &writer, Array &a);

/// Any json writer
void writeAny(Writer<StringBuffer> &writer, Any &a);

/// Write key with std::string
void writeKey(Writer<StringBuffer> &writer, const String &str);

}
