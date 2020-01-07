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

#pragma once

#include <optional>

#include <libclsp/types/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

enum class MessageType
{
	/// An error message.
	Error = 1,

	/// A warning message.
	Warning = 2,

	/// An information message.
	Info = 3,

	/// A log message.
	Log = 4
};

/// The show message notification is sent from a server to a client to ask
/// the client to display a particular message in the user interface.
///
/// type: MessageType
///
/// message: String
///
struct ShowMessageParams
{

	const static String typeKey;

	/// The message type. See {@link MessageType}.
	MessageType type;


	const static String messageKey;

	/// The actual message.
	String message;


	ShowMessageParams(MessageType type, String message);

	ShowMessageParams();

	virtual ~ShowMessageParams();
};

/// The message action items to present.
///
/// title: String
///
struct MessageActionItem
{
	const static String titleKey;

	/// A short title like 'Retry', 'Open Log' etc.
	String title;

	MessageActionItem(String title);

	MessageActionItem();

	virtual ~MessageActionItem();
};

struct ShowMessageRequestParams
{

	const static String typeKey;

	/// The message type. See {@link MessageType}.
	MessageType type;


	const static String messageKey;

	/// The actual message.
	String message;


	const static String actionsKey;

	/// The message action items to present.
	optional<vector<MessageActionItem>> actions;

	ShowMessageRequestParams(MessageType type,
		String message,
		optional<vector<MessageActionItem>> actions);

	ShowMessageRequestParams();

	virtual ~ShowMessageRequestParams();
};

}
