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
#include <libclsp/types/objectT.hpp>

namespace clsp
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
private:
	const static String typeKey;
	const static String messageKey;

public:
	/// The message type. See {@link MessageType}.
	MessageType type;

	/// The actual message.
	String message;


	// No parsing


	ShowMessageParams(MessageType type, String message);

	ShowMessageParams();

	virtual ~ShowMessageParams();
};

/// The message action items to present.
///
/// title: String
///
struct MessageActionItem: public ObjectT
{
private:
	const static String titleKey;

public:
	/// A short title like 'Retry', 'Open Log' etc.
	String title;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	MessageActionItem(String title);

	MessageActionItem();

	virtual ~MessageActionItem();
};

struct ShowMessageRequestParams
{
private:
	const static String typeKey;
	const static String messageKey;
	const static String actionsKey;

public:
	/// The message type. See {@link MessageType}.
	MessageType type;

	/// The actual message.
	String message;

	/// The message action items to present.
	optional<vector<MessageActionItem>> actions;

	// No parsing

	ShowMessageRequestParams(MessageType type,
		String message,
		optional<vector<MessageActionItem>> actions);

	ShowMessageRequestParams();

	virtual ~ShowMessageRequestParams();
};

}
