#ifndef TEXT_LOGGER_CONFIG_H
#define TEXT_LOGGER_CONFIG_H

#include <string>

namespace Log {

	struct TextLoggerConfig {
		
		std::string fileName;
		std::string directory;
		int maxFileSize;
		int maxFileCount;
	};
}

#endif // !TEXT_LOGGER_CONFIG_H