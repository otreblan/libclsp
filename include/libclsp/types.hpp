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

#include <libclsp/types/applyWorkspaceEdit.hpp>
#include <libclsp/types/cancelParams.hpp>
#include <libclsp/types/codeAction.hpp>
#include <libclsp/types/codeLens.hpp>
#include <libclsp/types/colorPresentation.hpp>
#include <libclsp/types/command.hpp>
#include <libclsp/types/completion.hpp>
#include <libclsp/types/configuration.hpp>
#include <libclsp/types/declaration.hpp>
#include <libclsp/types/definition.hpp>
#include <libclsp/types/diagnostic.hpp>
#include <libclsp/types/didChangeConfiguration.hpp>
#include <libclsp/types/didChangeTextDocument.hpp>
#include <libclsp/types/didChangeWatchedFiles.hpp>
#include <libclsp/types/didChangeWorkspaceFolders.hpp>
#include <libclsp/types/didCloseTextDocument.hpp>
#include <libclsp/types/didOpenTextDocument.hpp>
#include <libclsp/types/didSaveTextDocument.hpp>
#include <libclsp/types/documentColor.hpp>
#include <libclsp/types/documentFilter.hpp>
#include <libclsp/types/documentFormatting.hpp>
#include <libclsp/types/documentLink.hpp>
#include <libclsp/types/documentOnTypeFormatting.hpp>
#include <libclsp/types/documentRangeFormatting.hpp>
#include <libclsp/types/executeCommand.hpp>
#include <libclsp/types/fileResourceChanges.hpp>
#include <libclsp/types/foldingRange.hpp>
#include <libclsp/types/highlight.hpp>
#include <libclsp/types/hover.hpp>
#include <libclsp/types/implementation.hpp>
#include <libclsp/types/jsonTypes.hpp>
#include <libclsp/types/location.hpp>
#include <libclsp/types/locationLink.hpp>
#include <libclsp/types/logMessage.hpp>
#include <libclsp/types/markupContent.hpp>
#include <libclsp/types/message.hpp>
#include <libclsp/types/notificationMessage.hpp>
#include <libclsp/types/objectT.hpp>
#include <libclsp/types/partialResult.hpp>
#include <libclsp/types/position.hpp>
#include <libclsp/types/range.hpp>
#include <libclsp/types/reference.hpp>
#include <libclsp/types/registration.hpp>
#include <libclsp/types/rename.hpp>
#include <libclsp/types/responseMessage.hpp>
#include <libclsp/types/selectionRange.hpp>
#include <libclsp/types/showMessage.hpp>
#include <libclsp/types/signatureHelp.hpp>
#include <libclsp/types/staticRegistration.hpp>
#include <libclsp/types/symbol.hpp>
#include <libclsp/types/textDocumentIdentifier.hpp>
#include <libclsp/types/textDocumentItem.hpp>
#include <libclsp/types/textDocumentPosition.hpp>
#include <libclsp/types/textDocumentRegistration.hpp>
#include <libclsp/types/textDocumentSync.hpp>
#include <libclsp/types/textEdit.hpp>
#include <libclsp/types/typeDefinition.hpp>
#include <libclsp/types/willSaveTextDocument.hpp>
#include <libclsp/types/workDoneProgress.hpp>
#include <libclsp/types/workspaceEdit.hpp>
#include <libclsp/types/workspaceFolder.hpp>
