#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H

#include <string>
#include <exception>

namespace Logger {

	class AbstractLogger
	{
	public:
		virtual void Debug(std::string* message, std::exception* exp = nullptr) = 0;
		virtual void Info(std::string* message, std::exception* exp = nullptr) = 0;
		virtual void Warning(std::string* message, std::exception* exp = nullptr) = 0;
		virtual void Error(std::string* message, std::exception* exp = nullptr) = 0;

		virtual ~AbstractLogger() {};
	};

}

#endif // !ABSTRACT_LOGGER_H