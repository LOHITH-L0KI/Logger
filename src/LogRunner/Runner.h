#include <LogLevel.h>
#include <string>

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

		Runner(AbstractLogger* logger);

		virtual ~Runner();

	//METHODS
	public:
		virtual void Log(LogLevel level, const std::string& message);

	//DATA
	private:
		AbstractLogger* _logger;
	};
}


#endif // !RUNNER_H