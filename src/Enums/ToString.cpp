#include "ToString.h"
#include <cassert>

namespace Log {
#define STRING_ME(str) #str

	ToString::ToString(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case Log::DEBUG:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(DEBUG));
			break;
		case Log::INFO:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(INFO));
			break;
		case Log::WARNING:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(WARNING));
			break;
		case Log::ERROR:
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
		case Log::CONSOLE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(CONSOLE));
			break;
		case Log::TRACE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(TRACE));
			break;
		case Log::TEXT:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(TEXT));
			break;
		case Log::DATABASE:
			strcpy_s(this->buffer, ToString::BUFFER_SIZE, STRING_ME(DATABASE));
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