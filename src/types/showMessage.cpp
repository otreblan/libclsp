// A C++17 library for language servers.
// Copyright © 2019-2020 otreblan
//
// libclsp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libclsp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

#include <libclsp/types/showMessage.hpp>

namespace libclsp
{

using namespace std;

const String ShowMessageParams::typeKey    = "type";
const String ShowMessageParams::messageKey = "message";

ShowMessageParams::ShowMessageParams(MessageType type, String message):
	type(type),
	message(message)
{};

ShowMessageParams::ShowMessageParams():
	type(),
	message()
{};

ShowMessageParams::~ShowMessageParams(){};


MessageActionItem::MessageActionItem(String title):
	title(title)
{};

MessageActionItem::MessageActionItem():
	title()
{};

MessageActionItem::~MessageActionItem(){};


const String ShowMessageRequestParams::typeKey    = "type";
const String ShowMessageRequestParams::messageKey = "message";
const String ShowMessageRequestParams::actionsKey = "actions";

ShowMessageRequestParams::ShowMessageRequestParams(MessageType type,
	String message,
	optional<vector<MessageActionItem>> actions):
		type(type),
		message(message),
		actions(actions)
{};

ShowMessageRequestParams::ShowMessageRequestParams():
	type(),
	message(),
	actions()
{};

ShowMessageRequestParams::~ShowMessageRequestParams(){};

}
