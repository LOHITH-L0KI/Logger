#ifndef TO_STRING_H
#define TO_STRING_H

#include <string>
#include "LogLevel.h"
#include "LogType.h"

namespace Logger {

#define StringMe(enumVal) ToString(enumVal)

	class ToString
	{

	public:
		ToString(LogLevel logLevel);
		ToString(LogType logType);

		operator const char* ();

	public:
		static const size_t BUFFER_SIZE = 64;
		char buffer[BUFFER_SIZE];
	};
}

#endif // !TO_STRING_H
