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

#include <libclsp/types/diagnostic.hpp>

namespace libclsp
{

using namespace std;

const String Diagnostic::rangeKey              = "range";
const String Diagnostic::severityKey           = "severity";
const String Diagnostic::codeKey               = "code";
const String Diagnostic::sourceKey             = "source";
const String Diagnostic::messageKey            = "message";
const String Diagnostic::tagsKey               = "tags";
const String Diagnostic::relatedInformationKey = "relatedInformation";

Diagnostic::Diagnostic(Range range,
	optional<DiagnosticSeverity> severity,
	optional<variant<Number, String>> code,
	optional<String> source,
	String message,
	optional<vector<DiagnosticTag>> tags,
	optional<vector<DiagnosticRelatedInformation>> relatedInformation):
		range(range),
		severity(severity),
		code(code),
		source(source),
		message(message),
		tags(tags),
		relatedInformation(relatedInformation)
{};

Diagnostic::Diagnostic(){};
Diagnostic::~Diagnostic(){};

void Diagnostic::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// range:
	setterMap.emplace(
		rangeKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->preFillInitializer();

				range.fillInitializer(handler->objectStack.top());

				neededMap[rangeKey] = true;
			}
		}
	);

	// severity?:
	setterMap.emplace(
		severityKey,
		ValueSetter{
			// String
			{},

			// Number
			[this](Number n)
			{
				if(holds_alternative<int>(n))
				{
					int i = get<int>(n);

					if(i > 0 && i <= 4) // Enum bounds
					{
						severity = (DiagnosticSeverity)i;
						return;
					}
				}

				// Nothing by default
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// code?:
	setterMap.emplace(
		codeKey,
		ValueSetter{
			// String
			[this](String str)
			{
				code = str;
			},

			// Number
			[this](Number n)
			{
				code = n;
			},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// source?:
	setterMap.emplace(
		sourceKey,
		ValueSetter{
			// String
			[this](String str)
			{
				source = str;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// message?:
	setterMap.emplace(
		messageKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				message = str;

				neededMap[messageKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// tags?:
	setterMap.emplace(
		tagsKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{

				tags = vector<DiagnosticTag>();

				auto* maker = new TagsMaker;
				maker->parent = this;

				handler->preFillInitializer();
				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{}
		}
	);

	// relatedInformation?:
	setterMap.emplace(
		relatedInformationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			[this, handler]()
			{

				relatedInformation = vector<DiagnosticRelatedInformation>();

				auto* maker = new RelatedInformationMaker;
				maker->parent = this;

				handler->preFillInitializer();
				maker->fillInitializer(handler->objectStack.top());
			},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(rangeKey, 0);
	neededMap.emplace(messageKey, 0);

	// This
	initializer.object = this;
}

void Diagnostic::TagsMaker::fillInitializer(ObjectInitializer& initializer)
{
	auto& extraSetter = initializer.extraSetter;
	auto& Vector = parent->tags.value();

	// Value setters

	// DiagnosticTag[]
	extraSetter =
	{
		// String
		{},

		// Number
		[&Vector](Number n)
		{
			if(holds_alternative<int>(n))
			{
				int i = get<int>(n);

				if(i > 0 && i <= 2) // Enum bounds
				{
					Vector.emplace_back((DiagnosticTag)i);
					return;
				}
			}

			// Nothing is added by default

		},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		{}
	};

	// This
	initializer.object = this;

	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);
}

void Diagnostic::RelatedInformationMaker::
	fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& extraSetter = initializer.extraSetter;
	auto& Vector = parent->relatedInformation.value();

	// Value setters

	// DiagnosticRelatedInformation[]
	extraSetter =
	{
		// String
		{},

		// Number
		{},

		// Boolean
		{},

		// Null
		{},

		// Array
		{},

		// Object
		[&Vector, handler]()
		{
			auto& obj = Vector.emplace_back();

			handler->preFillInitializer();

			obj.fillInitializer(handler->objectStack.top());
		}
	};

	// This
	initializer.object = this;

	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);
}


const String DiagnosticRelatedInformation::locationKey = "location";
const String DiagnosticRelatedInformation::messageKey  = "message";

DiagnosticRelatedInformation::DiagnosticRelatedInformation(Location location,
	String message):
		location(location),
		message(message)
{};

DiagnosticRelatedInformation::DiagnosticRelatedInformation(){};
DiagnosticRelatedInformation::~DiagnosticRelatedInformation(){};

void DiagnosticRelatedInformation::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// location;
	setterMap.emplace(
		locationKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->preFillInitializer();

				location.fillInitializer(handler->objectStack.top());

				neededMap[locationKey] = true;
			}
		}
	);

	// message:
	setterMap.emplace(
		messageKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				message = str;

				neededMap[messageKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// Needed members
	neededMap.emplace(locationKey, 0);
	neededMap.emplace(messageKey, 0);

	// This
	initializer.object = this;
}

}
