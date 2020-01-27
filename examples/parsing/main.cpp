#include <iostream>

#include <libclsp/server.hpp>
#include <libclsp/types.hpp>

using namespace std;
using namespace clsp;

int main()
{


	// The object to save the parsed json
	Position p;

	// A handler that gets events from the reader
	JsonHandler handler;

	// This puts an empty initializer on the top of the stack of the handler.
	// And when the the handler gets the StartObject() a empty initializer is
	// pushed on the top of the handler stack.
	// Then the object fills the initializer with a map of keys to its setters.
	handler.objectStack.emplace().extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		[&handler, &p]()
		{
			handler.pushInitializer();

			p.fillInitializer(handler.objectStack.top());
		}
	};

	// The json
	StringStream s("{\"line\":10,\"character\":2.5}");

	// The reader that sends events to the handler
	Reader r;

	// The parsing itself
	r.Parse(s, handler);

	// get<> is used because Number is an alias to variant<int, double>
	cout << "line:" << get<int>(p.line) << '\n';
	cout << "character:" << get<double>(p.character) << '\n';

	return 0;
}
