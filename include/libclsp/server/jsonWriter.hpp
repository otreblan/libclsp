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

#include <rapidjson/writer.h>

#include <libclsp/types/jsonTypes.hpp>

namespace clsp
{

using namespace std;
using namespace rapidjson;


/// Copied from https://arne-mertz.de/2018/05/overload-build-a-variant-visitor-on-the-fly/
template<class ...Fs>
struct overload : Fs...
{
	overload(Fs const&... fs): Fs{fs}...{};

	using Fs::operator()...;
};

/// A writer with some extra functions
class JsonWriter: public Writer<StringBuffer>
{
private:

	/// A buffer
	StringBuffer buffer;

public:

	JsonWriter();

	/// Writes an ObjectT
	bool Object(ObjectT &obj);

	/// Writes an int or a double
	bool Number(Number n);

	/// Writes a generic array
	bool Array(Array &a);

	/// Writes almost anything
	bool Any(Any &a);

	/// Writes a new key
	bool Key(clsp::Key& str)
	{
		return Writer<StringBuffer>::Key(str.c_str(), str.size());
	}


	/// Gets the json
	const StringBuffer::Ch* GetString() const
	{
		return buffer.GetString();
	}
};


}
