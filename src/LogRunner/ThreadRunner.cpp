#include "ThreadRunner.h"
#include "Thread_Util.h"
#include "Logger.h"

namespace Logger {

	ThreadRunner::ThreadRunner(AbstractLogger* logger)
		:Runner(logger),
		_dataPool(),
		_queue(),
		_runThread(nullptr),
		_kill(false)
	{
		this->_runThread = Thread::createAndStartThread(1, "Logger_Thread", [&]() { this->privQueueReader(); });
	}

	ThreadRunner::~ThreadRunner()
	{
		//signal reader thread to stop
		_kill.store(true);

		//Wait for runner thread to complete its work.
		if (_runThread && _runThread->joinable())
			_runThread->join();

		delete _runThread;
	}

	void ThreadRunner::Log(LogLevel level, const std::string& message)
	{
		//TODO:: have a memeory pool to build new strings.
		std::string* heapMsg = new std::string(message);
		auto data = _dataPool.allocate(heapMsg, level);

		if (data) {
			_queue.push(data);
		}
	}

	void ThreadRunner::privQueueReader()
	{
		LogData* data = nullptr;
		while (!this->_kill.load(std::memory_order_relaxed)) {

			if (_queue.pop(data)) {
				Runner::Log(data->_level, *data->_msg);
				_dataPool.dealloc(data);
				data = nullptr;
			}

		}

		//wait till all the data in queue is written
		while (_queue.pop(data)) {
			Runner::Log(data->_level, *data->_msg);
			data = nullptr;
		}
	}
}