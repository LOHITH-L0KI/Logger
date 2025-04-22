#include "TextLogger.h"
#include <filesystem>
#include <ToString.h>
#include <time.h>
namespace fs = std::filesystem;
namespace ch = std::chrono;

namespace Logger {
	
	TextLogger::TextLogger(TextLoggerConfig config)
		:filePrefix(0),
		maxFileSize(config.maxFileSize),
		maxFileCount(config.maxFileCount),
		fileName(config.fileName),
		folderDir(config.directory),
		fileExt("txt")
	{
		//set filestream mode
		fsMode = std::ios::out	// set the stream as out stream(write stream).
			| std::ios::trunc;	// destroy existing data if file exists.

		//set filestream and fileprefix
		privSetFSAndFPrefix();
	}

	TextLogger::~TextLogger()
	{
		//close out file stream
		if (this->fsOut.is_open()) {
			this->fsOut.flush();
			this->fsOut.close();
		}
	}

	void TextLogger::Log(LogLevel level, const std::string& const message)
	{
		//format the message and write to stream.
		privWriteToStream(level, message);
	}

	/// <summary>
	/// Creates the director if not present.
	/// Sets the file prefix
	/// Initializes the output file stream with the latest file prefix.
	/// </summary>
	/// <returns></returns>
	void TextLogger::privSetFSAndFPrefix()
	{
		//get directory
		fs::directory_entry logDir(this->folderDir);

		//check if directory exists
		if (!logDir.exists()) {
			fs::create_directories(this->folderDir);
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
					this->filePrefix = std::stol(fName.substr(this->fileName.size(), std::string::npos));
					break;
				}
			}

		}


											
		auto filePath = std::format("{0}{1}{2}.{3}", this->folderDir, this->fileName, this->filePrefix, this->fileExt);
		//create file out steram buffer.
		this->fsOut = std::ofstream(filePath, std::ios::app);
		//this->fsOut.seekp(0, SEEK_END);	// set the stream as out stream(write stream).
		//this->fsOut.close();
	}

	/// <summary>
	/// Writes message to file stream.
	/// </summary>
	/// <param name="message"></param>
	void TextLogger::privWriteToStream(LogLevel level, const std::string& const message)
	{
		// Check if current file is within the file size range (maxFileSize)
		if (fsOut.tellp() >= this->maxFileSize - message.size())
			privCreateNewFS();

		fsOut << ch::floor<ch::seconds>(ch::system_clock::now())	//current time
			<< " -> "
			<< StringMe(level)										// debug level
			<< " :: "
			<< message												//message
			<< "\n";												//new line.

		fsOut.flush();												//flush
	}

	/// <summary>
	/// Create new log file
	/// </summary>
	void TextLogger::privCreateNewFS()
	{
		//overwrite exiting files if we reach maxfilecount
		++this->filePrefix;

		if (this->filePrefix == this->maxFileCount) // zero index files prefix
			this->filePrefix = 0;

		//set FS
		privSetFS();
	}

	/// <summary>
	/// Closes any exisiting open filestream and sets new file stream.
	/// </summary>
	void TextLogger::privSetFS()
	{
		//flush and close existing filestream
		if (this->fsOut.is_open()) {
		
			this->fsOut.flush();
			this->fsOut.close();
		}

		auto filePath = std::format("{0}{1}{2}.{3}", this->folderDir, this->fileName, this->filePrefix, this->fileExt);
		//set new filestream
		this->fsOut = std::ofstream(filePath, fsMode);
	}
}
