#ifndef CLSP_MESSAGES_RESPONSEMESSAGE_H
#define CLSP_MESSAGES_RESPONSEMESSAGE_H

#include <variant>
#include <optional>

#include <clsp/messages/jsonTypes.hpp>
#include <clsp/messages/message.hpp>
#include <clsp/messages/object.hpp>

namespace clsp
{

using namespace std;

class ResponseMessage: public Message
{

private:
	// Key, value, pair types.
	// In json-rpc all keys are strings.

	using idValue = variant<Number, String, Null>;
	using idPair  = pair<String, idValue>;

	/// The request id.
	idPair id;


	using resultValue = variant<String, Number, Boolean, Object, Null>;
	using resultPair  = optional<pair<String, resultValue>>;

	/// The result of a request. This member is REQUIRED on success.
	/// This member MUST NOT exist if there was an error invoking the method.
	resultPair result;

	//TODO: error

public:
	ResponseMessage();
	virtual ~ResponseMessage();
};

}

#endif /* CLSP_MESSAGES_RESPONSEMESSAGE_H */
