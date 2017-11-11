/*#ifndef BB_LOGGER_H_
#define BB_LOGGER_H_

#include <string>
#include <glad\glad.h>
#include <log4cxx\logger.h>

namespace bb
{
	class Logger
	{
	public:
		enum Level : GLint 
		{
			LEVEL_TRACE,
			LEVEL_DEBUG,
			LEVEL_INFO,
			LEVEL_WARN,
			LEVEL_ERROR,
			LEVEL_FATAL
		};

		Logger(std::string loggerName, const Level& minimumLogLevel = Logger::LEVEL_TRACE);
		~Logger();

		void setMinimumLevel(const Level& minimumLogLevel);

		void log(const Level &level, std::string message);
		void log(std::string message);

		const std::string& getName() const;

	private:
		const std::string mLOGGER_NAME;
		Level mMinimumLoggerLevel;
		log4cxx::LoggerPtr mLogger;
	};
}

#endif*/