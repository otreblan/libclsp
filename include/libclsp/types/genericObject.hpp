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

#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;


/// An object with no predefined key-value pairs.
struct GenericObject: public ObjectT
{
private:
	struct ArrayMaker: public ObjectT
	{
		/// The generic object where the array is constructed
		GenericObject& parent;

		/// The key of the array
		string key;

		//====================   Parsing   ======================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//=======================================================================//


		ArrayMaker(GenericObject& parent, string key);

		virtual ~ArrayMaker();
	};

protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	/// Key-value pairs of anything
	map<String, Any> children;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//====================   Writing   ======================================//

	/// This is for writing the json
	virtual void write(JsonWriter &writer);

	//====================   Reparsing   ====================================//

	/// This calls events on the handler with its children
	void reParse(JsonHandler& handler);

	//=======================================================================//


	GenericObject(map<String, Any> children);

	GenericObject();

	virtual ~GenericObject();
};

}
