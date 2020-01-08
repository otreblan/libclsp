# A C++17 library for language servers.
# Copyright © 2019-2020 otreblan
#
# libclsp is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libclsp is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

target_sources(${PROJECT_NAME}
	PRIVATE
		applyWorkspaceEdit.cpp
		cancelParams.cpp
		command.cpp
		completion.cpp
		configuration.cpp
		declaration.cpp
		definition.cpp
		diagnostic.cpp
		didChangeConfiguration.cpp
		didChangeTextDocument.cpp
		didChangeWatchedFiles.cpp
		didChangeWorkspaceFolders.cpp
		didCloseTextDocument.cpp
		didOpenTextDocument.cpp
		didSaveTextDocument.cpp
		documentFilter.cpp
		executeCommand.cpp
		fileResourceChanges.cpp
		hover.cpp
		jsonTypes.cpp
		location.cpp
		locationLink.cpp
		logMessage.cpp
		markupContent.cpp
		message.cpp
		notificationMessage.cpp
		objectT.cpp
		partialResult.cpp
		position.cpp
		range.cpp
		registration.cpp
		responseMessage.cpp
		showMessage.cpp
		signatureHelp.cpp
		staticRegistration.cpp
		textDocumentIdentifier.cpp
		textDocumentItem.cpp
		textDocumentPosition.cpp
		textDocumentRegistration.cpp
		textDocumentSync.cpp
		textEdit.cpp
		willSaveTextDocument.cpp
		workDoneProgress.cpp
		workspaceEdit.cpp
		workspaceFolder.cpp
)
