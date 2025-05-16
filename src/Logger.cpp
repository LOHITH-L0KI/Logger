#include "Logger.h"
#include "ThreadRunner.h"

namespace Logger {

	Log* Log::_log = nullptr;

	Log::~Log()
	{
		if (_out)
			delete this->_out;
	}

	Log::Log(AbstractLogger*& logger, RunMode mode)
		:_out(nullptr)
	{
		privConfigLoggerMode(mode, logger);
	}

	void Log::Destroy()
	{
		if (Log::_log)
			delete Log::_log;
	}

	void Log::privConfigLoggerMode(RunMode mode, AbstractLogger*& logger)
	{
		switch (mode)
		{
		case Logger::SEQUENTIAL:
			_out = new Runner(logger);
			break;
		case Logger::CONCURRENT_THREAD: {
			auto tOut = new ThreadRunner(logger);
			tOut->Run();
			_out = tOut;

			Log::Debug("Logger Thread Started:");
		}
			break;
		default:
			break;
		}
	}

	void Log::privSend(LogLevel level, const std::string& msg)
	{
		if (Log::_log)
			Log::_log->_out->Log(level, msg);
	}
	
	Log* Log::privGetLogger()
	{
		return Log::_log;
	}
}