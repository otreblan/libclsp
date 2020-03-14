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

#include <libclsp/server/capability.hpp>

#include <libclsp/types.hpp>

namespace clsp
{

using namespace std;

Capability::Capability(String method, JsonIO params, optional<JsonIO> result):
	method(method),
	params(params),
	result(result)
{};

Capability::~Capability(){};


Capability::JsonIO::JsonIO(optional<function<void(JsonWriter&, any&)>> writer,
	optional<function<ValueSetter(JsonHandler&, optional<any>&)>> reader):
		writer(writer),
		reader(reader)
{};

Capability::JsonIO::~JsonIO(){};


// Cancellation Support
const Capability Capability::cancelRequest = {
	// Method
	"$/cancelRequest",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<CancelParams&>(data));
		},

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<CancelParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::progress = {
	// Method
	"$/progress",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<ProgressParams&>(data));
		},

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<ProgressParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::initialize = {
	// Method
	"initialize",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<InitializeParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	{{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<InitializeResult&>(data));
		},

		// Reader
		nullopt
	}}
};

const Capability Capability::initialized = {
	// Method
	"initialized",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<InitializedParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::shutdown = {
	// Method
	"shutdown",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler&, optional<any>& data)
		{
			data = nullopt;

			return ValueSetter();
		}
	},

	// Response
	{{
		// Reader
		[](JsonWriter& writer, any&)
		{
			writer.Null();
		},

		// Writer
		nullopt
	}}
};

const Capability Capability::exit = {
	// Method
	"exit",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler&, optional<any>& data)
		{
			data = nullopt;

			return ValueSetter();
		}
	},

	// Response
	nullopt
};

const Capability Capability::windowShowMessage = {
	// Method
	"window/showMessage",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<ShowMessageParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	nullopt
};

const Capability Capability::windowShowMessageRequest = {
	// Method
	"window/showMessageRequest",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<ShowMessageRequestParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<variant<MessageActionItem, Null>>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				[&params]()
				{
					params = Null();
				},

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					auto& obj = params.emplace<MessageActionItem>();

					handler.pushInitializer();
					obj.fillInitializer(handler.objectStack.top());
				}
			};
		}
	}}
};

const Capability Capability::windowLogMessage = {
	// Method
	"window/logMessage",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<LogMessageParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	nullopt
};

const Capability Capability::windowWorkDoneProgressCreate = {
	// Method
	"window/workDoneProgress/create",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<WorkDoneProgressCreateParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler&, optional<any>& data)
		{
			data = nullopt;

			return ValueSetter();
		}
	}}
};

const Capability Capability::windowWorkDoneProgressCancel = {
	// Method
	"window/workDoneProgress/cancel",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<WorkDoneProgressCancelParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::telemetryEvent = {
	// Method
	"telemetry/event",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Any(any_cast<Any&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	nullopt
};

const Capability Capability::clientRegisterCapability = {
	// Method
	"client/registerCapability",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<RegistrationParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler&, optional<any>& data)
		{
			data = nullopt;

			return ValueSetter();
		}
	}}
};

const Capability Capability::clientUnregisterCapability = {
	// Method
	"client/unregisterCapability",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<UnregistrationParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler&, optional<any>& data)
		{
			data = nullopt;

			return ValueSetter();
		}
	}}
};


const Capability Capability::workspaceWorkspaceFolders = {
	// Method
	"workspace/workspaceFolders",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<variant<vector<WorkspaceFolder>, Null>>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				[&params]()
				{
					params = Null();
				},

				// Array
				[&handler, &params]()
				{
					auto* maker = new ObjectArrayMaker<WorkspaceFolder>
						(params.emplace<vector<WorkspaceFolder>>());

					handler.pushInitializer();
					maker->fillInitializer(handler.objectStack.top());
				},

				// Object
				nullopt
			};
		}
	}}
};

const Capability Capability::workspaceDidChangeWorkspaceFolders = {
	// Method
	"workspace/didChangeWorkspaceFolders",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<DidChangeWorkspaceFoldersParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::workspaceDidChangeConfiguration = {
	// Method
	"workspace/didChangeConfiguration’",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<DidChangeConfigurationParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::workspaceConfiguration = {
	// Method
	"workspace/configuration",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<ConfigurationParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<Array>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				[&handler, &params]()
				{
					auto* maker = new ArrayMaker(params);

					handler.pushInitializer();
					maker->fillInitializer(handler.objectStack.top());
				},

				// Object
				nullopt
			};
		}
	}}
};

const Capability Capability::workspaceDidChangeWatchedFiles = {
	// Method
	"workspace/didChangeWatchedFiles",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<DidChangeWatchedFilesParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::workspaceSymbol = {
	// Method
	"workspace/symbol",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<WorkspaceSymbolParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	{{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			visit(overload(
				[&writer](vector<SymbolInformation>& vec)
				{
					writer.StartArray();
					for(auto& i:vec)
					{
						writer.Object(i);
					}
					writer.EndArray();
				},
				[&writer](Null)
				{
					writer.Null();
				}
			),any_cast<variant<vector<SymbolInformation>, Null>&>(data));
		},

		// Reader
		nullopt
	}}
};

const Capability Capability::workspaceExecuteCommand = {
	// Method
	"workspace/executeCommand",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<ExecuteCommandParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	{{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			visit(overload(
				[&writer](Any& anyResponse)
				{
					writer.Any(anyResponse);
				},
				[&writer](Null)
				{
					writer.Null();
				}
			),any_cast<variant<Any, Null>&>(data));
		},

		// Reader
		nullopt
	}}
};

const Capability Capability::workspaceApplyEdit = {
	// Method
	"workspace/applyEdit",

	// Request
	{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			writer.Object(any_cast<ApplyWorkspaceEditParams&>(data));
		},

		// Reader
		nullopt
	},

	// Response
	{{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<ApplyWorkspaceEditResponse>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{

					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	}}
};

const Capability Capability::textDocumentDidOpen = {
	// Method
	"textDocument/didOpen",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<DidOpenTextDocumentParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::textDocumentDidChange = {
	// Method
	"textDocument/didChange",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<DidChangeTextDocumentParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::textDocumentWillSave = {
	// Method
	"textDocument/willSave",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<WillSaveTextDocumentParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	nullopt
};

const Capability Capability::textDocumentWillSaveWaitUntil = {
	// Method
	"textDocument/willSaveWaitUntil",

	// Request
	{
		// Writer
		nullopt,

		// Reader
		[](JsonHandler& handler, optional<any>& data)
		{
			auto& params = data.emplace().emplace<WillSaveTextDocumentParams>();

			return ValueSetter{
				// String
				nullopt,

				// Number
				nullopt,

				// Boolean
				nullopt,

				// Null
				nullopt,

				// Array
				nullopt,

				// Object
				[&handler, &params]()
				{
					handler.pushInitializer();
					params.fillInitializer(handler.objectStack.top());
				}
			};
		}
	},

	// Response
	{{
		// Writer
		[](JsonWriter& writer, any& data)
		{
			visit(overload(
				[&writer](vector<TextEdit>& vec)
				{
					writer.StartArray();
					for(auto& i:vec)
					{
						writer.Object(i);
					}
					writer.EndArray();
				},
				[&writer](Null)
				{
					writer.Null();
				}
			), any_cast<variant<vector<TextEdit>, Null>&>(data));
		},

		// Reader
		nullopt
	}}
};

}
