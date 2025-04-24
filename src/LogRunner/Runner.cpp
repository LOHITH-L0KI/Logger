#include "Runner.h"
#include <cassert>
#include "AbstractLogger.h"
#include "TextLogger.h"
#include <filesystem>

namespace Logger {
	
	Runner::Runner(AbstractLogger* logger)
		:_logger(logger)
	{
	}

	Runner::~Runner()
	{
		delete _logger;
	}

	void Runner::Log(LogLevel level, const std::string& message)
	{
		assert(_logger != nullptr, "Logger Type is not defined");

		if(_logger)
		_logger->Log(level, message);
	}
}
