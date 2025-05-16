#ifndef LOGGER_H
#define LOGGER_H
#include <format>
#include <string>
#include <string_view>
#include <assert.h>

#include "LogType.h"
#include "LogLevel.h"
#include "RunMode.h"
#include "TextLogger.h"
#include "TextLoggerConfig.h"

namespace Logger {

	struct DBConfig {};
	struct ConsoleConfig {};
	struct TraceConfig {};

	//CONFIGURATION
	template<LogType logtype>
	struct ConfigSelector;

	template <> struct ConfigSelector<LogType::TEXT> { using Type = TextLoggerConfig; };
	template <> struct ConfigSelector<LogType::DATABASE> { using Type = DBConfig; };
	template <> struct ConfigSelector<LogType::CONSOLE> { using Type = ConsoleConfig; };
	template <> struct ConfigSelector<LogType::TRACE> { using Type = TraceConfig; };

	class Runner;
	class Log {

	//BUILDERS
	public:
		Log() = delete;
		Log(const Log&) = delete;
		Log operator = (const Log&) = delete;

		~Log();

	private:
		Log(AbstractLogger*& logger, RunMode mode);

	//INITIALIZER
	public:
		
		template<LogType logType>
		static inline void Configure(RunMode mode, ConfigSelector<logType>::Type config) {

			if (Log::_log)
				Log::Warning("Tryed to reconfigure Logger.");
			else {
				AbstractLogger* logger = privConfigLoggerType<logType>(config);
				Log::_log = new Log(logger, mode);
				assert(Log::_log);
				
				if(Log::_log)
					Log::Info("Successfully Configured Logger");
			}
		}

		static void Destroy();

	//METHODS		
	public:
		template<typename... A>
		static inline void Debug(const std::string_view fmt, const A&... args){
			privSend(LogLevel::DEBUG, BuildMessage(fmt, args...));
		}
		
		template<typename... A>
		static inline void Info(const std::string_view fmt, const A&... args){
			privSend(LogLevel::INFO, BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Error(const std::string_view fmt, const A&... args){
			privSend(LogLevel::ERROR, BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Warning(const std::string_view fmt, const A&... args){
			privSend(LogLevel::WARNING, BuildMessage(fmt, args...));
		}

	private:
		template<typename...A>
		static inline std::string BuildMessage(std::string_view fmt, A&&... placeholders) {
			return std::vformat(fmt, std::make_format_args(std::forward<A>(placeholders)...));
		}

		template<LogType logType, typename _Config>
		static inline AbstractLogger* privConfigLoggerType(_Config& config) {

			AbstractLogger* outLog = nullptr;
			switch (logType)
			{
			case Logger::CONSOLE:
				break;
			case Logger::TRACE:
				break;
			case Logger::TEXT: {
				if (std::is_same<_Config, typename ConfigSelector<logType>::Type>::value) {
					outLog = new TextLogger(config);
				}
				else {
					TextLoggerConfig defConfig;
					outLog = new TextLogger(defConfig);
				}
			}
				break;
			case Logger::DATABASE:
				break;
			default:
				break;
			}

			return outLog;
		}

		void privConfigLoggerMode(RunMode mode, AbstractLogger*& logger);
		static void privSend(LogLevel level, const std::string& msg);
		static Log* privGetLogger();

	//DATA
	private:
		Runner* _out;
		static Log* _log;
	};
}

#endif // !LOGGER_H

