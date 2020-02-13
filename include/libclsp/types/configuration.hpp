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

#include <libclsp/types/objectT.hpp>

namespace clsp
{

using namespace std;

struct ConfigurationItem: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String scopeUriKey;
	const static String sectionKey;

public:
	/// The scope to get the configuration section for.
	optional<DocumentUri> scopeUri;

	/// The configuration section asked for.
	optional<String> section;

	// No parsing

	ConfigurationItem(optional<DocumentUri> scopeUri, optional<String> section);

	ConfigurationItem();

	virtual ~ConfigurationItem();
};

struct ConfigurationParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String itemsKey;

public:
	vector<ConfigurationItem> items;

	// No parsing

	ConfigurationParams(vector<ConfigurationItem> items);

	ConfigurationParams();

	virtual ~ConfigurationParams();
};

}
