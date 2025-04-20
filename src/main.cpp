
#include <iostream>
#include <TextLogger\TextLogger.h>

using namespace Log;
int main(int argc, char* argv[]) {
	std::cout << "Logger Project";

	//-------TESTING--------

	TextLoggerConfig logConfig;
	logConfig.directory = "E://Projects//Logger//Logs//";
	logConfig.fileName = "log";
	logConfig.maxFileCount = 11;
	logConfig.maxFileSize = 1024 * 1024; // 1Mb

	AbstractLogger* log = new TextLogger(logConfig);

	for (int i = 1024 * 100; i > 0; --i)
		log->Debug(new std::string("Initial Test"));

	delete log;
}