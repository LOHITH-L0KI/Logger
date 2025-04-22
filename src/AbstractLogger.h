#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H

#include <string>
#include "LogLevel.h"

namespace Logger {

	class AbstractLogger
	{
	public:
		virtual void Log(LogLevel level, const std::string& const message) = 0;
		virtual ~AbstractLogger() {};
	};

}

#endif // !ABSTRACT_LOGGER_H