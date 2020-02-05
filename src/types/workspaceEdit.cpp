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

#include <stdexcept>

#include <libclsp/types/workspaceEdit.hpp>

namespace clsp
{

using namespace std;

const String WorkspaceEdit::changesKey         = "changes";
const String WorkspaceEdit::documentChangesKey = "documentChanges";

WorkspaceEdit::WorkspaceEdit(optional<Changes> changes,
	optional<
		variant<
			vector<TextDocumentEdit>,
			vector<
				variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>
			>
		>
	> documentChanges):
		changes(changes),
		documentChanges(documentChanges)
{};

WorkspaceEdit::WorkspaceEdit(){};
WorkspaceEdit::~WorkspaceEdit(){};


const boost::bimap<ResourceOperationKind::Kind, String>
ResourceOperationKind::kindMap =
	boost::assign::list_of<boost::bimap<Kind, String>::relation>
		(Kind::Create, "create")
		(Kind::Rename, "rename")
		(Kind::Delete, "delete");

ResourceOperationKind::ResourceOperationKind(Kind kind):
	kind(kind)
{};

ResourceOperationKind::ResourceOperationKind(String kind)
{
	auto newKind = kindMap.right.find(kind);

	if(newKind != kindMap.right.end())
	{
		this->kind = newKind->second;
	}
	else
	{
		throw invalid_argument("Kind not found in the map");
	}
}

ResourceOperationKind::~ResourceOperationKind(){};

const ResourceOperationKind ResourceOperationKind::Create = Kind::Create;
const ResourceOperationKind ResourceOperationKind::Rename = Kind::Rename;
const ResourceOperationKind ResourceOperationKind::Delete = Kind::Delete;


const boost::bimap<FailureHandlingKind::Kind, String>
FailureHandlingKind::kindMap =
	boost::assign::list_of<boost::bimap<Kind, String>::relation>
		(Kind::Abort,                 "abort")
		(Kind::Transactional,         "transactional")
		(Kind::TextOnlyTransactional, "textOnlyTransactional")
		(Kind::Undo,                  "undo");

FailureHandlingKind::FailureHandlingKind(Kind kind):
	kind(kind)
{};

FailureHandlingKind::FailureHandlingKind(String kind)
{
	auto newKind = kindMap.right.find(kind);

	if(newKind != kindMap.right.end())
	{
		this->kind = newKind->second;
	}
	else
	{
		throw invalid_argument("Kind not found in the map");
	}
}

FailureHandlingKind::~FailureHandlingKind(){};

const FailureHandlingKind FailureHandlingKind::Abort = Kind::Abort,
	FailureHandlingKind::Transactional               = Kind::Transactional,
	FailureHandlingKind::TextOnlyTransactional       = Kind::TextOnlyTransactional,
	FailureHandlingKind::Undo                        = Kind::Undo;


WorkspaceEdit::Changes::Changes(map<DocumentUri, vector<TextEdit>> changes):
	changes(changes)
{};

WorkspaceEdit::Changes::Changes(){};
WorkspaceEdit::Changes::~Changes(){};


const String WorkspaceEditClientCapabilities::
	documentChangesKey    = "documentChanges";

const String WorkspaceEditClientCapabilities::
	resourceOperationsKey = "resourceOperations";

const String WorkspaceEditClientCapabilities::
	failureHandlingKey    = "failureHandling";

WorkspaceEditClientCapabilities::
	WorkspaceEditClientCapabilities(optional<Boolean> documentChanges,
		optional<vector<ResourceOperationKind>> resourceOperations,
		optional<FailureHandlingKind> failureHandling):
			documentChanges(documentChanges),
			resourceOperations(resourceOperations),
			failureHandling(failureHandling)
{};

WorkspaceEditClientCapabilities::WorkspaceEditClientCapabilities(){};
WorkspaceEditClientCapabilities::~WorkspaceEditClientCapabilities(){};

void WorkspaceEditClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// documentChanges?:
	setterMap.emplace(
		documentChangesKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				documentChanges = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// resourceOperations?:
	setterMap.emplace(
		resourceOperationsKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			nullopt,

			// Null
			nullopt,

			// Array
			[this, handler]()
			{
				resourceOperations.emplace();

				handler->pushInitializer();

				auto* maker = new ResourceOperationsMaker(resourceOperations.value());

				maker->fillInitializer(handler->objectStack.top());

			},

			// Object
			nullopt
		}
	);

	// failureHandling?:
	setterMap.emplace(
		failureHandlingKey,
		ValueSetter{
			// String
			[this](String str)
			{
				failureHandling = str;
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

	// This
	initializer.object = this;
}

WorkspaceEditClientCapabilities::ResourceOperationsMaker::
	ResourceOperationsMaker(vector<ResourceOperationKind> &parentArray):
		parentArray(parentArray)
{};

WorkspaceEditClientCapabilities::ResourceOperationsMaker::
	~ResourceOperationsMaker()
{};

void WorkspaceEditClientCapabilities::ResourceOperationsMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// ResourceOperationKind[]
	extraSetter =
	{
		// String
		[this](String str)
		{
			parentArray.emplace_back(str);
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
	};

	// This
	initializer.object = this;
}

}
