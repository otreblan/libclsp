#ifndef CLSP_MESSAGES_MESSAGE_H
#define CLSP_MESSAGES_MESSAGE_H

#include <string>

namespace clsp
{

using namespace std;

struct Message
{

	const static pair<string, string> jsonrpc;

	Message();
	virtual ~Message();
};

}

#endif /* CLSP_MESSAGES_MESSAGE_H */
