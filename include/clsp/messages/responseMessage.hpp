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

	const static String idKey;
	using idValue = variant<Number, String, Null>;
	using idPair  = pair<const String, idValue>;

	/// The request id.
	idPair id;


	const static String resultKey;
	using resultValue = variant<String, Number, Boolean, Object, Null>;
	using resultPair  = optional<pair<const String, resultValue>>;

	/// The result of a request. This member is REQUIRED on success.
	/// This member MUST NOT exist if there was an error invoking the method.
	resultPair result;

	//TODO: error
	const static String errorKey;

public:
	ResponseMessage(idValue _id, resultValue _result);
	virtual ~ResponseMessage();
};

}

#endif /* CLSP_MESSAGES_RESPONSEMESSAGE_H */
