#ifndef LIBCLSP_MESSAGES_MESSAGE_H
#define LIBCLSP_MESSAGES_MESSAGE_H

#include <string>

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

struct Message
{

	const static pair<String, String> jsonrpc;

	Message();
	virtual ~Message();
};

}

#endif /* LIBCLSP_MESSAGES_MESSAGE_H */
