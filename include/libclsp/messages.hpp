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

#include <libclsp/messages/applyWorkspaceEdit.hpp>
#include <libclsp/messages/cancelParams.hpp>
#include <libclsp/messages/configuration.hpp>
#include <libclsp/messages/diagnostic.hpp>
#include <libclsp/messages/didChangeConfiguration.hpp>
#include <libclsp/messages/didChangeWatchedFiles.hpp>
#include <libclsp/messages/didChangeWorkspaceFolders.hpp>
#include <libclsp/messages/documentFilter.hpp>
#include <libclsp/messages/executeCommand.hpp>
#include <libclsp/messages/fileResourceChanges.hpp>
#include <libclsp/messages/jsonTypes.hpp>
#include <libclsp/messages/location.hpp>
#include <libclsp/messages/locationLink.hpp>
#include <libclsp/messages/logMessage.hpp>
#include <libclsp/messages/markupContent.hpp>
#include <libclsp/messages/message.hpp>
#include <libclsp/messages/notificationMessage.hpp>
#include <libclsp/messages/objectT.hpp>
#include <libclsp/messages/position.hpp>
#include <libclsp/messages/range.hpp>
#include <libclsp/messages/registration.hpp>
#include <libclsp/messages/responseMessage.hpp>
#include <libclsp/messages/showMessage.hpp>
#include <libclsp/messages/staticRegistration.hpp>
#include <libclsp/messages/textDocumentIdentifier.hpp>
#include <libclsp/messages/textDocumentItem.hpp>
#include <libclsp/messages/textDocumentPosition.hpp>
#include <libclsp/messages/textDocumentRegistration.hpp>
#include <libclsp/messages/textDocumentSync.hpp>
#include <libclsp/messages/textEdit.hpp>
#include <libclsp/messages/workDoneProgress.hpp>
#include <libclsp/messages/workspaceEdit.hpp>
#include <libclsp/messages/workspaceFolder.hpp>
