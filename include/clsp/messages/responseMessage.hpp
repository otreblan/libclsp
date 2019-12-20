#ifndef CLSP_MESSAGES_RESPONSEMESSAGE_H
#define CLSP_MESSAGES_RESPONSEMESSAGE_H

#include <variant>

#include <clsp/messages/jsonTypes.hpp>
#include <clsp/messages/message.hpp>

namespace clsp
{

using namespace std;

class ResponseMessage: public Message
{
private:

public:
	ResponseMessage();
	virtual ~ResponseMessage();
};

}

#endif /* CLSP_MESSAGES_RESPONSEMESSAGE_H */
