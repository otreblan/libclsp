#ifndef LIBCLSP_MESSAGES_JSONTYPES_H
#define LIBCLSP_MESSAGES_JSONTYPES_H

#include <string>
#include <variant>

namespace libclsp
{

using namespace std;

// Primitive json-rpc types
using String  = string;
using Number  = int;
using Boolean = bool;
using Null    = monostate;

}

#endif /* LIBCLSP_MESSAGES_JSONTYPES_H */
