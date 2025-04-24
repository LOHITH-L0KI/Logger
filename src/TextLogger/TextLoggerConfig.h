#ifndef TEXT_LOGGER_CONFIG_H
#define TEXT_LOGGER_CONFIG_H

#include <string>
#include <filesystem>

namespace Logger {

	struct TextLoggerConfig {
		
	private:
		inline static const std::string _DEFAULT_DIRECTORY = std::filesystem::current_path().append("Logs").string();
		inline static const std::string _DEFAULT_FILE_NAME = "log";
		inline static const std::string _DEFAULT_FILE_EXT = "txt";
		inline static const int _DEFAULT_MAX_FILE_SIZE = 1024 * 1024; // 1 MB
		inline static const int _DEFAULT_MAX_FILE_COUNT = 10;

	public:
		std::string directory = _DEFAULT_DIRECTORY;
		std::string fileName = _DEFAULT_FILE_NAME;
		std::string fileExt = _DEFAULT_FILE_EXT;
		int maxFileSize = _DEFAULT_MAX_FILE_SIZE;
		int maxFileCount = _DEFAULT_MAX_FILE_COUNT;

	};
}

#endif // !TEXT_LOGGER_CONFIG_H