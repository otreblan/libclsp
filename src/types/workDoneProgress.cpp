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

#include <libclsp/types/workDoneProgress.hpp>
#include <functional>

namespace clsp
{

using namespace std;

const pair<String, String> WorkDoneProgressBegin::kind = {"kind", "begin"};

const String WorkDoneProgressBegin::titleKey       = "title";
const String WorkDoneProgressBegin::cancellableKey = "cancellable";
const String WorkDoneProgressBegin::messageKey     = "message";
const String WorkDoneProgressBegin::percentageKey  = "percentage";

WorkDoneProgressBegin::WorkDoneProgressBegin(String title,
	optional<Boolean> cancellable,
	optional<String> message,
	optional<Number> percentage):
		title(title),
		cancellable(cancellable),
		message(message),
		percentage(percentage)
{};

WorkDoneProgressBegin::WorkDoneProgressBegin(){};
WorkDoneProgressBegin::~WorkDoneProgressBegin(){};

void WorkDoneProgressBegin::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// title:
	setterMap.emplace(
		titleKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				title = str;
				neededMap[titleKey] = true;
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

	// cancellable?:
	setterMap.emplace(
		cancellableKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				cancellable = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// message?:
	setterMap.emplace(
		messageKey,
		ValueSetter{
			// String
			[this](String str)
			{
				message = str;
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

	// percentage?:
	setterMap.emplace(
		percentageKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this](Number n)
			{
				percentage = n;
			},

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

	// Needed members
	neededMap.emplace(titleKey, 0);

	// This
	initializer.object = this;
}

void WorkDoneProgressBegin::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// title
	writer.Key(titleKey);
	writer.String(title);

	// cancellable?
	if(cancellable.has_value())
	{
		writer.Key(cancellableKey);
		writer.Bool(*cancellable);
	}

	// message?
	if(message.has_value())
	{
		writer.Key(messageKey);
		writer.String(*message);
	}

	// percentage?
	if(percentage.has_value())
	{
		writer.Key(percentageKey);
		writer.Number(*percentage);
	}
}


const pair<String, String> WorkDoneProgressReport::kind = {"kind", "report"};

const String WorkDoneProgressReport::cancellableKey = "cancellable";
const String WorkDoneProgressReport::messageKey     = "message";
const String WorkDoneProgressReport::percentageKey  = "percentage";

WorkDoneProgressReport::WorkDoneProgressReport(optional<Boolean> cancellable,
	optional<String> message,
	optional<Number> percentage):
		cancellable(cancellable),
		message(message),
		percentage(percentage)
{};

WorkDoneProgressReport::WorkDoneProgressReport(){};
WorkDoneProgressReport::~WorkDoneProgressReport(){};

void WorkDoneProgressReport::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// cancellable?:
	setterMap.emplace(
		cancellableKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			nullopt,

			// Boolean
			[this](Boolean b)
			{
				cancellable = b;
			},

			// Null
			nullopt,

			// Array
			nullopt,

			// Object
			nullopt
		}
	);

	// message?:
	setterMap.emplace(
		messageKey,
		ValueSetter{
			// String
			[this](String str)
			{
				message = str;
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

	// percentage?:
	setterMap.emplace(
		percentageKey,
		ValueSetter{
			// String
			nullopt,

			// Number
			[this](Number n)
			{
				percentage = n;
			},

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

void WorkDoneProgressReport::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// cancellable?
	if(cancellable.has_value())
	{
		writer.Key(cancellableKey);
		writer.Bool(*cancellable);
	}

	// message?
	if(message.has_value())
	{
		writer.Key(messageKey);
		writer.String(*message);
	}

	// percentage?
	if(percentage.has_value())
	{
		writer.Key(percentageKey);
		writer.Number(*percentage);
	}
}


const pair<String, String> WorkDoneProgressEnd::kind = {"kind", "end"};

const String WorkDoneProgressEnd::messageKey = "message";

WorkDoneProgressEnd::WorkDoneProgressEnd(optional<String> message):
	message(message)
{};

WorkDoneProgressEnd::WorkDoneProgressEnd(){};
WorkDoneProgressEnd::~WorkDoneProgressEnd(){};

void WorkDoneProgressEnd::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// message?:
	setterMap.emplace(
		messageKey,
		ValueSetter{
			// String
			[this](String str)
			{
				message = str;
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

void WorkDoneProgressEnd::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// message?
	if(message.has_value())
	{
		writer.Key(messageKey);
		writer.String(*message);
	}
}

const String WorkDoneProgressParams::workDoneTokenKey = "workDoneToken";

WorkDoneProgressParams::
	WorkDoneProgressParams(optional<ProgressToken> workDoneToken):
		workDoneToken(workDoneToken)
{};

WorkDoneProgressParams::WorkDoneProgressParams(){};
WorkDoneProgressParams::~WorkDoneProgressParams(){};

void WorkDoneProgressParams::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;

	// Value setters

	// workDoneToken?:
	setterMap.emplace(
		workDoneTokenKey,
		ValueSetter{
			// String
			[this](String str)
			{
				workDoneToken = str;
			},

			// Number
			[this](Number n)
			{
				workDoneToken = n;
			},

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


const String WorkDoneProgressOptions::workDoneProgressKey = "workDoneProgress";

WorkDoneProgressOptions::
	WorkDoneProgressOptions(optional<Boolean> workDoneProgress):
		workDoneProgress(workDoneProgress)
{};

WorkDoneProgressOptions::WorkDoneProgressOptions(){};
WorkDoneProgressOptions::~WorkDoneProgressOptions(){};

void WorkDoneProgressOptions::partialWrite(JsonWriter &writer)
{
	// workDoneProgress?
	if(workDoneProgress.has_value())
	{
		writer.Key(workDoneProgressKey);
		writer.Bool(*workDoneProgress);
	}
}


const String WorkDoneProgressCreateParams::tokenKey = "token";

WorkDoneProgressCreateParams::WorkDoneProgressCreateParams(ProgressToken token):
	token(token)
{};

WorkDoneProgressCreateParams::WorkDoneProgressCreateParams(){};
WorkDoneProgressCreateParams::~WorkDoneProgressCreateParams(){};

void WorkDoneProgressCreateParams::partialWrite(JsonWriter &writer)
{
	// token
	writer.Key(tokenKey);
	visit(overload(
		[&writer](Number n)
		{
			writer.Number(n);
		},
		[&writer](String& str)
		{
			writer.String(str);
		}
	), token);
}


const String WorkDoneProgressCancelParams::tokenKey = "token";

WorkDoneProgressCancelParams::WorkDoneProgressCancelParams(ProgressToken token):
	token(token)
{};

WorkDoneProgressCancelParams::WorkDoneProgressCancelParams(){};
WorkDoneProgressCancelParams::~WorkDoneProgressCancelParams(){};

void WorkDoneProgressCancelParams::fillInitializer(ObjectInitializer& initializer)
{
	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// token:
	setterMap.emplace(
		tokenKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				token = str;
				neededMap[tokenKey] = true;
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

	// Needed members
	neededMap.emplace(tokenKey, 0);

	// This
	initializer.object = this;
}


const String ProgressParams::tokenKey = "token";
const String ProgressParams::valueKey = "value";

ProgressParams::ProgressParams(ProgressToken token,
	variant<WorkDoneProgressBegin,
		WorkDoneProgressReport,
		WorkDoneProgressEnd> value):
	token(token),
	value(value)
{};

ProgressParams::ProgressParams(){};
ProgressParams::~ProgressParams(){};

void ProgressParams::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// token:
	setterMap.emplace(
		tokenKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				token = str;

				neededMap[tokenKey] = true;
			},

			// Number
			[this, &neededMap](Number n)
			{
				token = n;

				neededMap[tokenKey] = true;
			},

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

	// value:
	setterMap.emplace(
		valueKey,
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
				handler->pushInitializer();

				auto maker = new ValueMaker(*this);

				maker->fillInitializer(handler->objectStack.top());
			}
		}
	);

	// Needed members
	neededMap.emplace(tokenKey, 0);
	neededMap.emplace(valueKey, 0);

	// This
	initializer.object = this;
}


ProgressParams::ValueMaker::ValueMaker(ProgressParams &parent):
	parent(parent)
{};

ProgressParams::ValueMaker::~ValueMaker(){};


void ProgressParams::ValueMaker::fillInitializer(ObjectInitializer& initializer)
{
	// ObjectMaker
	initializer.objectMaker = unique_ptr<ObjectT>(this);

	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;

	// Value setters

	// kind:
	setterMap.emplace(
		"kind"s,
		ValueSetter{
			// String
			[this, handler, &initializer](String str)
			{
				map<String, function<void()>> kindMap =
				{
					{
						WorkDoneProgressBegin::kind.second,
						[this, &initializer]()
						{
							parent.value = WorkDoneProgressBegin();

							get<WorkDoneProgressBegin>(parent.value).
								fillInitializer(initializer);
						}
					},
					{
						WorkDoneProgressReport::kind.second,
						[this, &initializer]()
						{
							parent.value = WorkDoneProgressReport();

							get<WorkDoneProgressReport>(parent.value).
								fillInitializer(initializer);
						}
					},
					{
						WorkDoneProgressEnd::kind.second,
						[this, &initializer]()
						{
							parent.value = WorkDoneProgressEnd();

							get<WorkDoneProgressEnd>(parent.value).
								fillInitializer(initializer);
						}
					}
				};

				auto ProgressMaker = kindMap.find(str);

				if(ProgressMaker != kindMap.end())// if the kind is in the map
				{
					ProgressMaker->second();

					// No more data to the cache
					initializer.extraSetter.reset();

					// Reparse data from the cache
					cache.reParse(*handler);
				}
				else
				{
					// An exception or something
				}
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
			nullopt,
		}
	);

	// cache
	cache.fillInitializer(initializer);

	// This
	initializer.object = this;
}

void ProgressParams::partialWrite(JsonWriter &writer)
{
	// token
	writer.Key(tokenKey);
	visit(overload(
		[&writer](Number n)
		{
			writer.Number(n);
		},
		[&writer](String& str)
		{
			writer.String(str);
		}
	), token);

	// value
	writer.Key(valueKey);
	visit(overload(
		[&writer](WorkDoneProgressBegin& obj)
		{
			writer.Object(obj);
		},
		[&writer](WorkDoneProgressReport& obj)
		{
			writer.Object(obj);
		},
		[&writer](WorkDoneProgressEnd& obj)
		{
			writer.Object(obj);
		}
	), value);
}

}
