#include "TextLogger.h"
#include <filesystem>
#include <ToString.h>
#include <time.h>
#include <cassert>
namespace fs = std::filesystem;
namespace ch = std::chrono;

namespace Logger {
	
	TextLogger::TextLogger(TextLoggerConfig& config)
		:_filePrefix(0),
		_config(config)
	{
		//set filestream mode
		_fsMode = std::ios::out	// set the stream as out stream(write stream).
			| std::ios::trunc;	// destroy existing data if file exists.

		//set filestream and _filePrefix
		privSetFSAndFPrefix();
	}

	TextLogger::~TextLogger()
	{
		//close out file stream
		if (this->_fsOut.is_open()) {
			this->_fsOut.flush();
			this->_fsOut.close();
		}
	}

	void TextLogger::Log(LogLevel level, const std::string& message)
	{
		//format the message and write to stream.
		privWriteToStream(level, message);
	}

	void TextLogger::privSetFSAndFPrefix()
	{
		//get directory
		fs::directory_entry logDir(this->_config.directory);

		//check if directory exists
		if (!logDir.exists()) {
			fs::create_directories(this->_config.directory);
			logDir.refresh();
		}

		//get latest file prefix
		if (!fs::is_empty(logDir)){
			
			auto lastWritten = (*fs::directory_iterator(logDir)).last_write_time();
			//auto tempLastWritten = lastWritten;
			std::string fName;

			//get last written fileName
			for (auto const& dir_entry : fs::directory_iterator(logDir)) {
				//tempLastWritten = dir_entry.last_write_time();
				
				if ((dir_entry.last_write_time() == lastWritten)) {
					//tempLastWritten = lastWritten;
					fName = dir_entry.path().stem().string();
					//get prefix out of file name.
					this->_filePrefix = std::stol(fName.substr(this->_config.fileName.size(), std::string::npos));
					break;
				}
			}

		}

		auto filePath = std::format("{0}\\{1}{2}.{3}", this->_config.directory, this->_config.fileName, this->_filePrefix, this->_config.fileExt);
		//create file out steram buffer.
		this->_fsOut = std::ofstream(filePath, std::ios::app);
	}

	void TextLogger::privWriteToStream(LogLevel level, const std::string& const message)
	{
		// Check if current file is within the file size range (maxFileSize)
		if (_fsOut.fail()) {
			assert(false, "FlieOutStream error");
		}
		if (_fsOut.tellp() >= this->_config.maxFileSize - message.size())
			privCreateNewFS();

		_fsOut << ch::floor<ch::seconds>(ch::system_clock::now())	//current time
			<< " -> "
			<< StringMe(level)										// debug level
			<< " :: "
			<< message												//message
			<< "\n";												//new line.

		_fsOut.flush();												//flush
	}

	void TextLogger::privCreateNewFS()
	{
		//overwrite exiting files if we reach maxfilecount
		++this->_filePrefix;

		if (this->_filePrefix == this->_config.maxFileCount) // zero index files prefix
			this->_filePrefix = 0;

		//set FS
		privSetFS();
	}

	void TextLogger::privSetFS()
	{
		//flush and close existing filestream
		if (this->_fsOut.is_open()) {
		
			this->_fsOut.flush();
			this->_fsOut.close();
		}

		auto filePath = std::format("{0}\\{1}{2}.{3}", this->_config.directory, this->_config.fileName, this->_filePrefix, this->_config.fileExt);
		//set new filestream
		this->_fsOut = std::ofstream(filePath, _fsMode);
	}
}
