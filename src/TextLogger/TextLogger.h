#ifndef TEXT_LOGGER_H
#define TEXT_LOGGER_H

#include <fstream>
#include "TextLoggerConfig.h"
#include "AbstractLogger.h"

namespace Logger {

    //----------REQUIREMENTS--------------
    /*
    * Folder Directiry
    * FileName
    * File Preffix
    * File Extension
    * MaxFileSize
    * MaxFileCount
    * FileWriter
    */

    /// <summary>
    /// Writes logs to a text file.
    /// </summary>
    class TextLogger :  public AbstractLogger
    {

    public:
        TextLogger(TextLoggerConfig& config);
        virtual ~TextLogger();

    protected:

        // Inherited via DLogger
        void Log(LogLevel level, const std::string& message) override;

    private:

        /// <summary>
        /// Creates the director if not present.
        /// Sets the file prefix
        /// Initializes the output file stream with the latest file prefix.
        /// </summary>
        /// <returns></returns>
        void privSetFSAndFPrefix();

        /// <summary>
        /// Writes message to file stream.
        /// </summary>
        /// <param name="message"></param>
        void privWriteToStream(LogLevel level, const std::string& message);
        
        /// <summary>
        /// Create new log file
        /// </summary>
        void privCreateNewFS();

        /// <summary>
        /// Closes any exisiting open filestream and sets new file stream.
        /// </summary>
        void privSetFS();

    private:
        
        int _filePrefix;
        TextLoggerConfig _config;
        std::ofstream _fsOut;
        std::ios_base::openmode _fsMode;
    };
}

#endif // !TEXT_LOGGER_H