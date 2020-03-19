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

#include <any>

#include <libclsp/server/jsonHandler.hpp>
#include <libclsp/server/jsonWriter.hpp>
#include <libclsp/types/objectT.hpp>

namespace clsp
{

using namespace std;

struct Capability
{
	/// The name of the method
	String method;

	struct JsonIO
	{
		/// A function to write the params or result.
		optional<function<void(JsonWriter&, any&)>> writer;

		/// A function to parse the params or result.
		optional<function<ValueSetter(JsonHandler&, optional<any>&)>> reader;

		JsonIO(optional<function<void(JsonWriter&, any&)>> writer,
			optional<function<ValueSetter(JsonHandler&, optional<any>&)>> reader);

		virtual ~JsonIO();
	};

	/// Functions to read/write the params of a RequestMessage or a
	/// NotificationMessage.
	JsonIO params;

	/// Functions to read/write the result of a ResponseMessage.
	/// Ommited for notifications.
	optional<JsonIO> result;

	Capability(String method, JsonIO params, optional<JsonIO> result);

	virtual ~Capability();

	// Default capabilities
	const static Capability cancelRequest;
	const static Capability progress;
	const static Capability initialize;
	const static Capability initialized;
	const static Capability shutdown;
	const static Capability exit;
	const static Capability windowShowMessage;
	const static Capability windowShowMessageRequest;
	const static Capability windowLogMessage;
	const static Capability windowWorkDoneProgressCreate;
	const static Capability windowWorkDoneProgressCancel;
	const static Capability telemetryEvent;
	const static Capability clientRegisterCapability;
	const static Capability clientUnregisterCapability;
	const static Capability workspaceWorkspaceFolders;
	const static Capability workspaceDidChangeWorkspaceFolders;
	const static Capability workspaceDidChangeConfiguration;
	const static Capability workspaceConfiguration;
	const static Capability workspaceDidChangeWatchedFiles;
	const static Capability workspaceSymbol;
	const static Capability workspaceExecuteCommand;
	const static Capability workspaceApplyEdit;
	const static Capability textDocumentDidOpen;
	const static Capability textDocumentDidChange;
	const static Capability textDocumentWillSave;
	const static Capability textDocumentWillSaveWaitUntil;
	const static Capability textDocumentDidSave;
	const static Capability textDocumentDidClose;
	const static Capability textDocumentPublishDiagnostics;
	const static Capability textDocumentCompletion;
};

}
