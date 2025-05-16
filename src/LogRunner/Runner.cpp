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
		_data._time = std::chrono::system_clock::now();
		_data._level = level;
		memcpy_s(_data._buffer, 512, message.c_str(), message.size());

		Log(this->_data);
	}

	void Runner::Log(const LogData& data)
	{
		if (_logger)
			_logger->Log(data);
	}

}
