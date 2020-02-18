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

#include <libclsp/types/publishDiagnostic.hpp>

namespace clsp
{

using namespace std;

const String PublishDiagnosticsClientCapabilities::
	relatedInformationKey = "relatedInformation";

const String PublishDiagnosticsClientCapabilities::
	tagSupportKey         = "tagSupport";

const String PublishDiagnosticsClientCapabilities::
	versionSupportKey     = "versionSupport";

PublishDiagnosticsClientCapabilities::
	PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
		optional<TagSupport> tagSupport,
		optional<Boolean> versionSupport):
			relatedInformation(relatedInformation),
			tagSupport(tagSupport),
			versionSupport(versionSupport)
{};

PublishDiagnosticsClientCapabilities::PublishDiagnosticsClientCapabilities(){};

PublishDiagnosticsClientCapabilities::
	~PublishDiagnosticsClientCapabilities()
{};

void PublishDiagnosticsClientCapabilities::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// relatedInformation?:
	setterMap.emplace(
		relatedInformationKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				relatedInformation = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// tagSupport?:
	setterMap.emplace(
		tagSupportKey,
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
			nullopt,

			// Object
			[this, handler]()
			{
				tagSupport.emplace();

				handler->pushInitializer();
				tagSupport->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// versionSupport?:
	setterMap.emplace(
		versionSupportKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				versionSupport = b;
			},

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


const String PublishDiagnosticsClientCapabilities::TagSupport::
	valueSetKey = "valueSet";

PublishDiagnosticsClientCapabilities::TagSupport::
	TagSupport(vector<DiagnosticTag> valueSet):
		valueSet(valueSet)
{};

PublishDiagnosticsClientCapabilities::TagSupport::TagSupport(){};
PublishDiagnosticsClientCapabilities::TagSupport::~TagSupport(){};

void PublishDiagnosticsClientCapabilities::TagSupport::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// valueSet:
	setterMap.emplace(
		valueSetKey,
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
			[this, handler, &neededMap]()
			{
				auto* maker = new ValueSetMaker(valueSet);

				handler->pushInitializer();
				maker->fillInitializer(handler->objectStack.top());

				neededMap[valueSetKey] = true;
			},

			// Object
			nullopt
		}
	);

	// Needed members
	neededMap.emplace(valueSetKey, 0);

	// This
	initializer.object = this;
}

PublishDiagnosticsClientCapabilities::TagSupport::ValueSetMaker::
	ValueSetMaker(vector<DiagnosticTag>& parentArray):
		parentArray(parentArray)
{};

PublishDiagnosticsClientCapabilities::TagSupport::ValueSetMaker::
	~ValueSetMaker()
{};

void PublishDiagnosticsClientCapabilities::TagSupport::ValueSetMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto& extraSetter = initializer.extraSetter;

	// Value setters

	// DiagnosticTag[]
	extraSetter =
	{
		// String
		nullopt,

		// Number
		[this](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				parentArray.emplace_back((DiagnosticTag)i);
			}

			// Nothing is added by default

		},

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


const String PublishDiagnosticsParams::uriKey         = "uri";
const String PublishDiagnosticsParams::versionKey     = "version";
const String PublishDiagnosticsParams::diagnosticsKey = "diagnostics";

PublishDiagnosticsParams::PublishDiagnosticsParams(DocumentUri uri,
	optional<Number> version,
	vector<Diagnostic> diagnostics):
		uri(uri),
		version(version),
		diagnostics(diagnostics)
{};

PublishDiagnosticsParams::PublishDiagnosticsParams(){};
PublishDiagnosticsParams::~PublishDiagnosticsParams(){};

void PublishDiagnosticsParams::partialWrite(JsonWriter &writer)
{
	// uri
	writer.Key(uriKey);
	writer.String(uri);

	// version?
	if(version.has_value())
	{
		writer.Key(versionKey);
		writer.Number(*version);
	}

	// diagnostics
	writer.Key(diagnosticsKey);
	writer.StartArray();
	for(auto& i: diagnostics)
	{
		writer.Object(i);
	}
	writer.EndArray();
}

}
