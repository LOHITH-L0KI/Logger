#include "Logger.h"
#include "ThreadRunner.h"

namespace Logger {

	Runner* Log::_runner = nullptr;

	void Log::Destroy()
	{
		if (Log::_runner)
			delete Log::_runner;
	}

	void Log::privConfigLoggerMode(RunMode mode, AbstractLogger*& logger)
	{
		switch (mode)
		{
		case Logger::SEQUENTIAL:
			_runner = new Runner(logger);
			break;
		case Logger::CONCURRENT_THREAD: {
			auto tOut = new ThreadRunner(logger);
			tOut->Run();
			_runner = tOut;

			Log::Debug("Logger Thread Started:");
		}
			break;
		default:
			break;
		}
	}

	void Log::privSend(LogLevel level, const std::string& msg)
	{
		if (Log::_runner)
			Log::_runner->Log(level, msg);
	}
}