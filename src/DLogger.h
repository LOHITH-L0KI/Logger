#ifndef DLOGGER_H
#define DLOGGER_H

#include "AbstractLogger.h"
#include "LogLevel.h"

namespace Log {

    class DLogger : public AbstractLogger
    {

    public:
        virtual void Log(LogLevel type, std::string* message) = 0;
        virtual ~DLogger() {};

    private:
        std::string* privBuildMessage(std::string* message, std::exception* exp);

        // Inherited via Logger
        void Debug(std::string* message, std::exception* exp) override;
        void Info(std::string* message, std::exception* exp) override;
        void Warning(std::string* message, std::exception* exp) override;
        void Error(std::string* message, std::exception* exp) override;


    };

}

#endif // !DLOGGER_H