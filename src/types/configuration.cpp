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

#include <libclsp/types/configuration.hpp>

namespace libclsp
{

using namespace std;

const String ConfigurationItem::scopeUriKey = "scopeUri";
const String ConfigurationItem::sectionKey  = "section";

ConfigurationItem::ConfigurationItem(optional<DocumentUri> scopeUri,
	optional<String> section):
		scopeUri(scopeUri),
		section(section)
{};

ConfigurationItem::ConfigurationItem(){};
ConfigurationItem::~ConfigurationItem(){};


const String ConfigurationParams::itemsKey = "items";

ConfigurationParams::ConfigurationParams(vector<ConfigurationItem> items):
	items(items)
{};

ConfigurationParams::ConfigurationParams(){};
ConfigurationParams::~ConfigurationParams(){};

}
