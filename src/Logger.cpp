#include "Logger.h"
#include "ThreadRunner.h"

namespace Logger {

	Log* Log::_log = nullptr;

	Log::~Log()
	{
		if (_out)
			delete this->_out;
	}

	Log::Log(LogType type, RunMode mode)
		:_out(nullptr)
	{

		switch (mode)
		{
		case Logger::SEQUENTIAL:
			_out = new Runner(type);
			break;
		case Logger::CONCURRENT_THREAD:
			_out = new ThreadRunner(type);
			Log::Debug("Logger Thread Started:");
			break;
		default:
			break;
		}
	}

	void Log::Configuration(LogType type, RunMode mode)
	{
		if (Log::privGetLogger() == nullptr) {
			Log::_log = new Log(type, mode);
		}
	}

	void Log::Destroy()
	{
		if (Log::_log)
			delete Log::_log;
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