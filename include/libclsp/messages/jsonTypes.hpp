#ifndef CLSP_MESSAGES_JSONTYPES_H
#define CLSP_MESSAGES_JSONTYPES_H

#include <string>
#include <variant>

namespace clsp
{

using namespace std;

// Primitive json-rpc types
using String  = string;
using Number  = int;
using Boolean = bool;
using Null    = monostate;

}

#endif /* CLSP_MESSAGES_JSONTYPES_H */
