#ifndef CLSP_MESSAGES_MESSAGE_H
#define CLSP_MESSAGES_MESSAGE_H

#include <string>

#include <clsp/messages/jsonTypes.hpp>

namespace clsp
{

using namespace std;

struct Message
{

	const static pair<String, String> jsonrpc;

	Message();
	virtual ~Message();
};

}

#endif /* CLSP_MESSAGES_MESSAGE_H */
