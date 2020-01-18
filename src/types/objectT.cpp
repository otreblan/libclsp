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

#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;
using namespace rapidjson;


void ObjectT::fillInitializer( [[maybe_unused]] JsonHandler& handler){};
void ObjectT::partialWrite( [[maybe_unused]] Writer<StringBuffer> &writer){};
void ObjectT::write( [[maybe_unused]] Writer<StringBuffer> &writer){};

bool ObjectT::isValid(JsonHandler& handler)
{
	auto& neededMap = handler.objectStack.top().neededMap;

	for(auto initializedPair: neededMap)
	{
		// If a needed value is left uninitialized
		if(!initializedPair.second)
		{
			return false;
		}
	}

	return true;
}

ObjectT::ObjectT(){};
ObjectT::~ObjectT(){};

void writeNumber(Writer<StringBuffer> &writer, Number n)
{
	visit(overload
	(
		[&writer](int n)
		{
			writer.Int(n);
		},
		[&writer](double n)
		{
			writer.Double(n);
		}
	), n);
}

void writeArray(Writer<StringBuffer> &writer, Array &a)
{
	writer.StartArray();
	for(const auto &ii:a)
	{
		visit(overload
		(
			[&writer](String ii)
			{
				writer.String(ii.c_str());
			},
			[&writer](Number ii)
			{
				writeNumber(writer, ii);
			},
			[&writer](Boolean ii)
			{
				writer.Bool(ii);
			},
			[&writer](Null)
			{
				writer.Null();
			},
			[&writer](Object ii)
			{
				ii->write(writer);
			}
		), ii);
	}
	writer.EndArray();
}

void writeAny(Writer<StringBuffer> &writer, Any &a)
{
	visit(overload
	(
		[&writer](String ii)
		{
			writer.String(ii.c_str());
		},
		[&writer](Number ii)
		{
			writeNumber(writer, ii);
		},
		[&writer](Boolean ii)
		{
			writer.Bool(ii);
		},
		[&writer](Null)
		{
			writer.Null();
		},
		[&writer](Object ii)
		{
			ii->write(writer);
		},
		[&writer](Array &ii)
		{
			writeArray(writer, ii);
		}
	), a);
}

}
