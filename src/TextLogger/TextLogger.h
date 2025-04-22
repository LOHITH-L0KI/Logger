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
        TextLogger(TextLoggerConfig config);
        virtual ~TextLogger();

    protected:
        // Inherited via DLogger
        void Log(LogLevel level, const std::string& const message) override;

    private:
        void privSetFSAndFPrefix();
        void privWriteToStream(LogLevel level, const std::string& const message);
        void privCreateNewFS();
        void privSetFS();

    private:
        size_t maxFileSize;
        size_t maxFileCount;
        int filePrefix;

        std::ofstream fsOut;
        std::ios_base::openmode fsMode;

        std::string folderDir;
        std::string fileName;
        std::string fileExt;
    };
}

#endif // !TEXT_LOGGER_H