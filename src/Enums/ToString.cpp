#include "ToString.h"
#include <cassert>

namespace Logger {
#define STRING_ME(str) #str

	ToString::ToString(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case Logger::DEBUG:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(DEBUG));
			break;
		case Logger::INFO:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(INFO));
			break;
		case Logger::WARNING:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(WARNING));
			break;
		case Logger::ERROR:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(ERROR));
			break;
		default:
			assert(false);
			break;
		}
	}

	ToString::ToString(LogType logType)
	{
		switch (logType)
		{
		case Logger::CONSOLE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(CONSOLE));
			break;
		case Logger::TRACE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(TRACE));
			break;
		case Logger::TEXT:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(TEXT));
			break;
		case Logger::DATABASE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(DATABASE));
			break;
		default:
			assert(false);
			break;
		}
	}

	ToString::ToString(RunMode runMode)
	{
		switch (runMode)
		{
		case Logger::SEQUENTIAL:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(SEQUENTIAL));
			break;
		case Logger::CONCURRENT_THREAD:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(CONCURRENT_THREAD));
			break;
		default:
			assert(false);
			break;
		}
	}

	ToString::operator const char* ()
	{
		return (const char*)this->buffer;
	}
}