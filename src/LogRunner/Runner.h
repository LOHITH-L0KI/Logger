#include <LogLevel.h>
#include <string>
#include "LogType.h"

#ifndef RUNNER_H
#define RUNNER_H

namespace Logger {
	
	class AbstractLogger;

	/// <summary>
	/// Base Runner.
	/// </summary>
	class Runner
	{
	//BUILDERS
	public:
		Runner() = delete;
		Runner(const Runner&) = delete;
		Runner& operator= (const Runner&) = delete;

		Runner(LogType type);

		virtual ~Runner();

	//METHODS
	public:
		virtual void Log(LogLevel level, const std::string& const message);

	private:
		void privSetLogger(LogType type);

	//DATA
	private:
		AbstractLogger* _logger;
	};
}


#endif // !RUNNER_H