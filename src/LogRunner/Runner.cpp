#include "Runner.h"
#include <cassert>
#include "AbstractLogger.h"
#include "TextLogger.h"

namespace Logger {
	
	Runner::Runner(LogType type)
		:_logger(nullptr)
	{
		privSetLogger(type);
	}

	Runner::~Runner()
	{
		delete _logger;
	}

	void Runner::Log(LogLevel level, const std::string& const message)
	{
		assert(_logger, "Logger Type is not defined");

		_logger->Log(level, message);
	}

	void Runner::privSetLogger(LogType type)
	{
		if (this->_logger)
			assert(false, "Logger is aready set.\n");

		switch (type)
		{
		case Logger::CONSOLE:
			break;
		case Logger::TRACE:
			break;
		case Logger::TEXT:
		{

			TextLoggerConfig logConfig;
			logConfig.directory = "E://Projects//Logger//Logs//";
			logConfig.fileName = "log";
			logConfig.maxFileCount = 11;
			logConfig.maxFileSize = 10 * 1024; //10 kb

			_logger = new TextLogger(logConfig);

		};
		break;
		case Logger::DATABASE:
			break;
		default:
			break;
		}
	}
}
