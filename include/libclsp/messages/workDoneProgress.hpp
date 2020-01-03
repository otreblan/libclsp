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

#include <libclsp/messages/jsonTypes.hpp>

namespace libclsp
{

using namespace std;

/// To start progress reporting a $/progress notification
/// with the following payload must be sent:
///
/// kind: 'begin'
///
/// title: String
///
/// cancellable?: Boolean
///
/// message?: String
///
/// percentage?: Number
///
struct WorkDoneProgressBegin
{

	const static pair<String, String> kind;


	const static String titleKey;

	/// Mandatory title of the progress operation. Used to briefly inform about
	/// the kind of operation being performed.
	///
	/// Examples: "Indexing" or "Linking dependencies".
	String title;


	const static String cancellableKey;

	/// Controls if a cancel button should show to allow the user to cancel the
	/// long running operation. Clients that don't support cancellation are allowed
	/// to ignore the setting.
	optional<Boolean> cancellable;


	const static String messageKey;

	/// Optional, more detailed associated progress message. Contains
	/// complementary information to the `title`.
	///
	/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
	/// If unset, the previous progress message (if any) is still valid.
	optional<String> message;


	const static String percentageKey;

	/// Optional progress percentage to display (value 100 is considered 100%).
	/// If not provided infinite progress is assumed and clients are allowed
	/// to ignore the `percentage` value in subsequent in report notifications.
	///
	/// The value should be steadily rising. Clients are free to ignore values
	/// that are not following this rule.
	optional<Number> percentage;


	WorkDoneProgressBegin(String title,
		optional<Boolean> cancellable,
		optional<String> message,
		optional<Number> percentage);

	virtual ~WorkDoneProgressBegin();

};


/// Reporting progress is done using the following payload:
///
/// kind: 'report'
///
/// cancellable?: Boolean
///
/// message?: String
///
/// percentage?: Number
///
struct WorkDoneProgressReport
{
	const static pair<String, String> kind;


	const static String cancellableKey;

	/// Controls enablement state of a cancel button. This property is only valid if a cancel
	/// button got requested in the `WorkDoneProgressStart` payload.
	///
	/// Clients that don't support cancellation or don't support control the button's
	/// enablement state are allowed to ignore the setting.
	optional<Boolean> cancellable;


	const static String messageKey;

	/// Optional, more detailed associated progress message. Contains
	/// complementary information to the `title`.
	///
	/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
	/// If unset, the previous progress message (if any) is still valid.
	optional<String> message;


	const static String percentageKey;

	/// Optional progress percentage to display (value 100 is considered 100%).
	/// If not provided infinite progress is assumed and clients are allowed
	/// to ignore the `percentage` value in subsequent in report notifications.
	///
	/// The value should be steadily rising. Clients are free to ignore values
	/// that are not following this rule.
	optional<Number> percentage;

	WorkDoneProgressReport(optional<Boolean> cancellable,
		optional<String> message,
		optional<Number> percentage);

	virtual ~WorkDoneProgressReport();
};

struct WorkDoneProgressEnd
{

	const static pair<String, String> kind;


	const static String messageKey;

	/// Optional, a final message indicating to for example indicate
	/// the outcome of the operation.
	optional<String> message;


	WorkDoneProgressEnd(optional<String> message);

	virtual ~WorkDoneProgressEnd();
};

/// A parameter literal used to pass a work done progress token.
///
/// workDoneToken?: ProgressToken
///
struct WorkDoneProgressParams
{
	const static String workDoneTokenKey;

	/// An optional token that a server can use to report work done progress.
	optional<ProgressToken> workDoneToken;


	WorkDoneProgressParams(optional<ProgressToken> workDoneToken);
	virtual ~WorkDoneProgressParams();
};

/// Options to signal work done progress support in server capabilities.
///
/// workDoneProgress?: boolean
///
struct WorkDoneProgressOptions
{
	const static String workDoneProgressKey;

	optional<Boolean> workDoneProgress;


	WorkDoneProgressOptions(optional<ProgressToken> workDoneProgress);
	virtual ~WorkDoneProgressOptions();
};

/// The window/workDoneProgress/create request is sent from the server to
/// the client to ask the client to create a work done progress.
///
/// token: ProgressToken
///
struct WorkDoneProgressCreateParams
{

	const static String tokenKey;

	/// The token to be used to report progress.
	ProgressToken token;


	WorkDoneProgressCreateParams(ProgressToken token);
	virtual ~WorkDoneProgressCreateParams();
};

}
