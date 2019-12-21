#include <libclsp/messages/responseMessage.hpp>

namespace libclsp
{

using namespace std;

const String ResponseMessage::idKey     = "id";
const String ResponseMessage::resultKey = "result";
const String ResponseMessage::errorKey  = "error";


ResponseMessage::ResponseMessage(idValue _id, resultValue _result):
	id(idKey, _id),
	result({resultKey, _result})
	{};

}
