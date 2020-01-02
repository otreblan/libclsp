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

#include <libclsp/messages/objectT.hpp>

namespace libclsp
{

using namespace std;
using namespace rapidjson;


void ObjectT::partialWrite( [[maybe_unused]] Writer<StringBuffer> &ww){};
void ObjectT::write( [[maybe_unused]] Writer<StringBuffer> &ww){};

ObjectT::ObjectT(){};
ObjectT::~ObjectT(){};

void ObjectT::NumberWriter::operator()(int n)
{
	writer.Int(n);
}

void ObjectT::NumberWriter::operator()(double n)
{
	writer.Double(n);
}

}
