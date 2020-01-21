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

#include <libclsp/server/jsonWriter.hpp>
#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;


JsonWriter::JsonWriter():
	Writer<StringBuffer>(buffer)
{};

bool JsonWriter::Object(ObjectT &obj)
{
	obj.write(*this);

	return true;
}

bool JsonWriter::Number(libclsp::Number n)
{
	bool result;

	visit(overload
	(
		[this, &result](int n)
		{
			result = Int(n);
		},
		[this, &result](double n)
		{
			result = Double(n);
		}
	), n);

	return result;
}

bool JsonWriter::Array(libclsp::Array &a)
{
	bool result = true;

	StartArray();
	for(const auto &ii: a)
	{
		visit(overload
		(
			[this, &result](libclsp::String str)
			{
				result &= String(str);
			},
			[this, &result](libclsp::Number n)
			{
				result &= Number(n);
			},
			[this, &result](Boolean b)
			{
				result &= Bool(b);
			},
			[this, &result](libclsp::Null)
			{
				result &= Null();
			},
			[this, &result](libclsp::Object obj)
			{
				result &= Object(*obj);
			}
		), ii);
	}
	EndArray();

	return result;
}

bool JsonWriter::Any(libclsp::Any &a)
{
	bool result;

	visit(overload
	(
		[this, &result](libclsp::String str)
		{
			result = String(str);
		},
		[this, &result](libclsp::Number n)
		{
			result = Number(n);
		},
		[this, &result](Boolean b)
		{
			result = Bool(b);
		},
		[this, &result](libclsp::Null)
		{
			result = Null();
		},
		[this, &result](libclsp::Object obj)
		{
			result = Object(*obj);
		},
		[this, &result](libclsp::Array &a)
		{
			result = Array(a);
		}
	), a);

	return result;
}

}
