#include "Logger.h"
#include "LogLevel.h"

namespace Log {

    class DLogger : public Logger
    {

    public:
        virtual void Log(LogLevel type, std::string* message) = 0;

    private:
        std::string* privBuildMessage(std::string& message, std::exception* exp);

        // Inherited via Logger
        void Debug(std::string message, std::exception* exp) override;
        void Info(std::string message, std::exception* exp) override;
        void Warning(std::string message, std::exception* exp) override;
        void Error(std::string message, std::exception* exp) override;


    };

}
