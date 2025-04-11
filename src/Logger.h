#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <exception>

namespace Log {

	class Logger
	{
	public:
		virtual void Debug(std::string message, std::exception* exp = nullptr) = 0;
		virtual void Info(std::string message, std::exception* exp = nullptr) = 0;
		virtual void Warning(std::string message, std::exception* exp = nullptr) = 0;
		virtual void Error(std::string message, std::exception* exp = nullptr) = 0;

		virtual ~Logger() {};
	};

}

#endif // !LOGGER_H