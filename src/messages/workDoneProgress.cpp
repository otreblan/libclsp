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

#include <libclsp/messages/workDoneProgress.hpp>

namespace libclsp
{

using namespace std;

const pair<String, String> WorkDoneProgressBegin::kind = {"kind", "begin"};

const String WorkDoneProgressBegin::titleKey       = "title";
const String WorkDoneProgressBegin::cancellableKey = "cancellable";
const String WorkDoneProgressBegin::messageKey     = "message";
const String WorkDoneProgressBegin::percentageKey  = "percentage";

WorkDoneProgressBegin::WorkDoneProgressBegin(String title,
	optional<Boolean> cancellable,
	optional<String> message,
	optional<Number> percentage):
		title(title),
		cancellable(cancellable),
		message(message),
		percentage(percentage)
{};

WorkDoneProgressBegin::WorkDoneProgressBegin():
	title(),
	cancellable(),
	message(),
	percentage()
{};

WorkDoneProgressBegin::~WorkDoneProgressBegin(){};


const pair<String, String> WorkDoneProgressReport::kind = {"kind", "report"};

const String WorkDoneProgressReport::cancellableKey = "cancellable";
const String WorkDoneProgressReport::messageKey     = "message";
const String WorkDoneProgressReport::percentageKey  = "percentage";

WorkDoneProgressReport::WorkDoneProgressReport(optional<Boolean> cancellable,
	optional<String> message,
	optional<Number> percentage):
		cancellable(cancellable),
		message(message),
		percentage(percentage)
{};

WorkDoneProgressReport::WorkDoneProgressReport():
	cancellable(),
	message(),
	percentage()
{};

WorkDoneProgressReport::~WorkDoneProgressReport(){};


const pair<String, String> WorkDoneProgressEnd::kind = {"kind", "end"};

const String WorkDoneProgressEnd::messageKey = "message";

WorkDoneProgressEnd::WorkDoneProgressEnd(optional<String> message):
	message(message)
{};

WorkDoneProgressEnd::WorkDoneProgressEnd():
	message()
{};

WorkDoneProgressEnd::~WorkDoneProgressEnd(){};


const String WorkDoneProgressParams::workDoneTokenKey = "workDoneToken";

WorkDoneProgressParams::
	WorkDoneProgressParams(optional<ProgressToken> workDoneToken):
		workDoneToken(workDoneToken)
{};

WorkDoneProgressParams::WorkDoneProgressParams():
	workDoneToken()
{};

WorkDoneProgressParams::~WorkDoneProgressParams(){};


const String WorkDoneProgressOptions::workDoneProgressKey = "workDoneProgress";

WorkDoneProgressOptions::
	WorkDoneProgressOptions(optional<ProgressToken> workDoneProgress):
		workDoneProgress(workDoneProgress)
{};

WorkDoneProgressOptions::WorkDoneProgressOptions():
	workDoneProgress()
{};

WorkDoneProgressOptions::~WorkDoneProgressOptions(){};


const String WorkDoneProgressCreateParams::tokenKey = "token";

WorkDoneProgressCreateParams::WorkDoneProgressCreateParams(ProgressToken token):
	token(token)
{};

WorkDoneProgressCreateParams::WorkDoneProgressCreateParams():
	token()
{};

WorkDoneProgressCreateParams::~WorkDoneProgressCreateParams(){};

}
