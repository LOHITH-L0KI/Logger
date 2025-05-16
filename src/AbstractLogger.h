#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H

#include <string>
#include "LogLevel.h"
#include "Runner.h"

namespace Logger {

	class AbstractLogger
	{
	public:
		virtual void Log(const Runner::LogData& data) = 0;
		virtual ~AbstractLogger() {};
	};

}

#endif // !ABSTRACT_LOGGER_H