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

namespace clsp
{

using namespace std;

const String ShowMessageParams::typeKey    = "type";
const String ShowMessageParams::messageKey = "message";

ShowMessageParams::ShowMessageParams(MessageType type, String message):
	type(type),
	message(message)
{};

ShowMessageParams::ShowMessageParams(){};
ShowMessageParams::~ShowMessageParams(){};

void ShowMessageParams::partialWrite(JsonWriter &writer)
{
	// type
	writer.Key(typeKey);
	writer.Int((int)type);

	// message
	writer.Key(messageKey);
	writer.String(message);
}


const String MessageActionItem::titleKey = "title";

MessageActionItem::MessageActionItem(String title):
	title(title)
{};

MessageActionItem::MessageActionItem(){};
MessageActionItem::~MessageActionItem(){};

void MessageActionItem::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// title:
	setterMap.emplace(
		titleKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				title = str;
				neededMap[titleKey] = true;
			},

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(titleKey, 0);

	// This
	initializer.object = this;
}

void MessageActionItem::partialWrite(JsonWriter &writer)
{
	// title
	writer.Key(titleKey);
	writer.String(title);
}

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

ShowMessageRequestParams::ShowMessageRequestParams(){};
ShowMessageRequestParams::~ShowMessageRequestParams(){};

void ShowMessageRequestParams::partialWrite(JsonWriter &writer)
{
	// type
	writer.Key(typeKey);
	writer.Int((int)type);

	// message
	writer.Key(messageKey);
	writer.String(message);

	// actions?
	if(actions.has_value())
	{
		writer.Key(actionsKey);
		writer.StartArray();
		for(auto& i: *actions)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}
}

}
