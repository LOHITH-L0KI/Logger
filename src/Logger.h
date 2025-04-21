#ifndef LOGGER_H
#define LOGGER_H
#include <AbstractLogger.h>
#include <format>
#include <string>
#include <string_view>

namespace Logger {

	static class Log {

	//METHODS		
	public:
		template<typename... A>
		static inline void Debug(const std::string& fmt, A&&... args){
			std::string* msg = new std::string(BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Info(std::string& fmt, A&&... args){
			std::string* msg = new std::string(BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Error(std::string& fmt, A&&... args){
			std::string* msg = new std::string(BuildMessage(fmt, args...));
		}

		template<typename... A>
		static inline void Warning(std::string& fmt, A&&... args){
			std::string* msg = new std::string(BuildMessage(fmt, args...));
		}

	private:
		template<typename...A>
		inline static std::string BuildMessage(std::string_view fmt, A&&... placeholders) {
			return std::vformat(fmt, std::make_format_args(placeholders...));
		}

	//DATA
	private:
		static AbstractLogger* _logInst;

	};
}

#endif // !LOGGER_H

