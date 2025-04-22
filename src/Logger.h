#ifndef LOGGER_H
#define LOGGER_H
#include <format>
#include <string>
#include <string_view>

#include <LogType.h>
#include <LogLevel.h>
#include <RunMode.h>

namespace Logger {

	class Runner;
	class Log {

	//BUILDERS
	public:
		Log() = delete;
		Log(const Log&) = delete;
		Log operator = (const Log&) = delete;

		~Log();

	private:
		Log(LogType type, RunMode mode);
			

	//INITIALIZER
	public:
		static void Configuration(LogType type, RunMode mode);

		static void Destroy();

	//METHODS		
	public:
		template<typename... A>
		static inline void Debug(const std::string& fmt, A&&... args){
			privSend(LogLevel::DEBUG, BuildMessage(fmt, args...));
		}
		
		template<typename... A>
		static inline void Info(const std::string& fmt, A&&... args){
			privSend(LogLevel::INFO, BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Error(const std::string& fmt, A&&... args){
			privSend(LogLevel::ERROR, BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Warning(const std::string& fmt, A&&... args){
			privSend(LogLevel::WARNING, BuildMessage(fmt, args...));
		}

	private:
		template<typename...A>
		static inline std::string BuildMessage(std::string_view fmt, A&&... placeholders) {
			return std::vformat(fmt, std::make_format_args(std::forward<A>(placeholders)...));
		}

		static void privSend(LogLevel level, const std::string& msg);
		static Log* privGetLogger();

	//DATA
	private:
		Runner* _out;
		static Log* _log;
	};
}

#endif // !LOGGER_H

