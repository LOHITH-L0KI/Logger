#include "DLogger.h"

namespace Log {
	
	void DLogger::Debug(std::string message, std::exception* exp)
	{
		Log(LogLevel::DEBUG, privBuildMessage(message, exp));
	}

	void DLogger::Info(std::string message, std::exception* exp)
	{
		Log(LogLevel::INFO, privBuildMessage(message, exp));
	}

	void DLogger::Warning(std::string message, std::exception* exp)
	{
		Log(LogLevel::WARNING, privBuildMessage(message, exp));
	}

	void DLogger::Error(std::string message, std::exception* exp)
	{
		Log(LogLevel::ERROR, privBuildMessage(message, exp));
	}

	std::string* DLogger::privBuildMessage(std::string& message, std::exception* exp)
	{
		std::string* msg = new std::string(message);

		//add expetion message if any
		if (exp)
			msg->append(exp->what());

		return msg;
	}

}