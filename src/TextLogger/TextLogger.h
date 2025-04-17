#ifndef TEXT_LOGGER_H
#define TEXT_LOGGER_H

#include "DLogger.h"
#include <fstream>
#include "TextLoggerConfig.h"

namespace Log {

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
    class TextLogger :  public DLogger
    {

    public:
        TextLogger(TextLoggerConfig config);
        virtual ~TextLogger();

    protected:
        // Inherited via DLogger
        void Log(LogLevel type, std::string* message) override;

    private:
        void privSetFSAndFPrefix();
        void privWriteToStream(LogLevel type, std::string& message);
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