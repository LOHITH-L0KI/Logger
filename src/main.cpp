
#include <iostream>
#include <TextLogger\TextLogger.h>
#include <Logger.h>

using namespace Logger;
int main(int argc, char* argv[]) {
	std::cout << "Logger Project";

	//-------TESTING--------
	TextLoggerConfig tc;
	Log::Configure<LogType::TEXT>(RunMode::SEQUENTIAL, tc);
	
	std::string msg;
	Log::Debug(msg, 1, 2, "sd");
	Log::Debug("asjk", 1, 2, "sd");

	for (int i = 1024 * 100; i > 0; --i)
		Log::Debug(std::string("Initial Test"));

	Log::Destroy();

}