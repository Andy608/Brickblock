#ifndef BB_LOGGER_H_
#define BB_LOGGER_H_

#include <string>
#include <log4cxx\consoleappender.h>
#include <log4cxx\patternlayout.h>
#include <glad\glad.h>

namespace bb
{
	class Logger
	{
	public:
		enum Level : GLint {
			LEVEL_TRACE,
			LEVEL_DEBUG,
			LEVEL_INFO,
			LEVEL_WARN,
			LEVEL_ERROR,
			LEVEL_FATAL
		};

		Logger(std::string loggerName);
		~Logger();

		void log(const Level &level, std::string message);
		void log(std::string message);

	private:
		static const std::wstring CONSOLE_HEADER;
		const std::string mLOGGER_NAME;
		log4cxx::LayoutPtr mConsoleLayout;
		log4cxx::ConsoleAppenderPtr mConsoleAppender;
		log4cxx::LoggerPtr mLogger;
	};
}

#endif