#ifndef THREAD_RUNNER_H
#define THREAD_RUNNER_H

#include "LFC_Queue.h"
#include "Pool.h"
#include <Runner.h>
#include <atomic>
#include <thread>

using namespace Util;

namespace Logger {

	class ThreadRunner : public Runner
	{
	//STRUCT: LOG DATA.
	private:
		struct LogData {

			LogData()
				:_msg(nullptr),
				_level(LogLevel::UNDEFINED)
			{	}

			LogData(const std::string* const msg, LogLevel level)
				:_msg(msg),
				_level(level)
			{	}

			const std::string* const _msg;
			LogLevel _level;
		};

	//BUILDERS
	public:
		ThreadRunner() = delete;
		ThreadRunner(const ThreadRunner&) = delete;
		ThreadRunner& operator= (const ThreadRunner&) = delete;

		ThreadRunner(AbstractLogger* logger);
		~ThreadRunner() override;

	//METHODS
	public:
		//Builds LogData and writes data to queue.
		void Log(LogLevel level, const std::string& message) override;

	private:
		void privQueueReader();

	//DATA
	private:

		//memory pool to create logData objects
		Pool<LogData, 1 << 5> _dataPool;

		//data queue to hold logs from client
		LFC_Queue<LogData*, 1 << 6> _queue;

		//thread writing logs to output
		std::thread* _runThread;

		//kill command
		std::atomic_bool _kill;
	};
}

#endif // !THREAD_RUNNER_H
