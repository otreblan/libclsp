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
#include <libclsp/types/genericObject.hpp>

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
struct WorkDoneProgressBegin: public ObjectT
{
private:
	const static String titleKey;
	const static String cancellableKey;
	const static String messageKey;
	const static String percentageKey;

public:
	const static pair<String, String> kind;

	/// Mandatory title of the progress operation. Used to briefly inform about
	/// the kind of operation being performed.
	///
	/// Examples: "Indexing" or "Linking dependencies".
	String title;

	/// Controls if a cancel button should show to allow the user to cancel the
	/// long running operation. Clients that don't support cancellation are allowed
	/// to ignore the setting.
	optional<Boolean> cancellable;

	/// Optional, more detailed associated progress message. Contains
	/// complementary information to the `title`.
	///
	/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
	/// If unset, the previous progress message (if any) is still valid.
	optional<String> message;

	/// Optional progress percentage to display (value 100 is considered 100%).
	/// If not provided infinite progress is assumed and clients are allowed
	/// to ignore the `percentage` value in subsequent in report notifications.
	///
	/// The value should be steadily rising. Clients are free to ignore values
	/// that are not following this rule.
	optional<Number> percentage;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	WorkDoneProgressBegin(String title,
		optional<Boolean> cancellable,
		optional<String> message,
		optional<Number> percentage);

	WorkDoneProgressBegin();

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
struct WorkDoneProgressReport: public ObjectT
{
private:
	const static String cancellableKey;
	const static String messageKey;
	const static String percentageKey;

public:
	const static pair<String, String> kind;

	/// Controls enablement state of a cancel button. This property is only valid if a cancel
	/// button got requested in the `WorkDoneProgressStart` payload.
	///
	/// Clients that don't support cancellation or don't support control the button's
	/// enablement state are allowed to ignore the setting.
	optional<Boolean> cancellable;

	/// Optional, more detailed associated progress message. Contains
	/// complementary information to the `title`.
	///
	/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
	/// If unset, the previous progress message (if any) is still valid.
	optional<String> message;

	/// Optional progress percentage to display (value 100 is considered 100%).
	/// If not provided infinite progress is assumed and clients are allowed
	/// to ignore the `percentage` value in subsequent in report notifications.
	///
	/// The value should be steadily rising. Clients are free to ignore values
	/// that are not following this rule.
	optional<Number> percentage;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	WorkDoneProgressReport(optional<Boolean> cancellable,
		optional<String> message,
		optional<Number> percentage);

	WorkDoneProgressReport();

	virtual ~WorkDoneProgressReport();
};

/// Signaling the end of a progress reporting is done using the following
/// payload
///
/// kind: 'end'
///
/// message?: String
///
struct WorkDoneProgressEnd: public ObjectT
{
private:
	const static String messageKey;

public:
	const static pair<String, String> kind;

	/// Optional, a final message indicating to for example indicate
	/// the outcome of the operation.
	optional<String> message;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	WorkDoneProgressEnd(optional<String> message);

	WorkDoneProgressEnd();

	virtual ~WorkDoneProgressEnd();
};

/// A parameter literal used to pass a work done progress token.
///
/// workDoneToken?: ProgressToken
///
struct WorkDoneProgressParams: public virtual ObjectT
{
private:
	const static String workDoneTokenKey;

public:
	/// An optional token that a server can use to report work done progress.
	optional<ProgressToken> workDoneToken;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	WorkDoneProgressParams(optional<ProgressToken> workDoneToken);

	WorkDoneProgressParams();

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

	// No parsing


	WorkDoneProgressOptions(optional<ProgressToken> workDoneProgress);

	WorkDoneProgressOptions();

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

	// No parsing


	WorkDoneProgressCreateParams(ProgressToken token);

	WorkDoneProgressCreateParams();

	virtual ~WorkDoneProgressCreateParams();
};

/// $/progress parameters
///
/// token: ProgressToken
///
/// value: WorkDoneProgressBegin | WorkDoneProgressReport | WorkDoneProgressEnd
///
struct ProgressParams: public ObjectT
{
private:
	const static String tokenKey;
	const static String valueKey;

	struct ValueMaker: public ObjectT
	{
		/// The object where value is
		ProgressParams &parent;

		/// A cache for the values recieved before kind:
		GenericObject cache;

		//====================   Parsing   ==================================//

		/// This fills an ObjectInitializer
		virtual void fillInitializer(ObjectInitializer& initializer);

		// Using default isValid()

		//===================================================================//

		ValueMaker(ProgressParams &parent);

		virtual ~ValueMaker();
	};

public:
	/// The progress token provided by the client or server.
	ProgressToken token;

	/// The progress data.
	variant<WorkDoneProgressBegin,
		WorkDoneProgressReport,
		WorkDoneProgressEnd> value;


	//====================   Parsing   ======================================//

	/// This fills an ObjectInitializer
	virtual void fillInitializer(ObjectInitializer& initializer);

	// Using default isValid()

	//=======================================================================//


	ProgressParams(ProgressToken token,
		variant<WorkDoneProgressBegin,
			WorkDoneProgressReport,
			WorkDoneProgressEnd> value);

	ProgressParams();

	virtual ~ProgressParams();
};

}
