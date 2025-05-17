#include <LogLevel.h>
#include <string>
#include <chrono>

#ifndef RUNNER_H
#define RUNNER_H

namespace Logger {
	
	class AbstractLogger;

	/// <summary>
	/// Base Runner.
	/// </summary>
	class Runner
	{
		//STRUCT: LOG DATA.
	public:
		struct LogData {

			LogData()
				:_time(),
				_level(LogLevel::UNDEFINED)
			{
				memset(_buffer, 0x0, 512);
			}

			LogData(const std::string& msg, LogLevel level)
				:_time(std::chrono::system_clock::now()),
				_level(level)
			{
				memcpy_s(_buffer, 512, msg.c_str(), msg.size() + 1);
			}

			std::chrono::time_point<std::chrono::system_clock> _time;
			LogLevel _level;
			char _buffer[512];
		};


	//BUILDERS
	public:
		Runner() = delete;
		Runner(const Runner&) = delete;
		Runner& operator= (const Runner&) = delete;

		Runner(AbstractLogger* logger);

		virtual ~Runner();

	//METHODS
	public:
		virtual void Log(LogLevel level, const std::string& message);

	protected:
		void Log(const LogData& data);

	//DATA
	private:
		AbstractLogger* _logger;
		LogData _data;
	};
}


#endif // !RUNNER_H