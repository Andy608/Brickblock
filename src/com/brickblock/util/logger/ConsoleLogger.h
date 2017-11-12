#ifndef BB_CONSOLELOGGER_H_
#define BB_CONSOLELOGGER_H_

#include "../libs/spdlog/spdlog.h"
#include "Logger.h"

namespace bb
{
	class ConsoleLogger : public Logger
	{
	public:
		ConsoleLogger(std::string consoleLoggerName, std::string consoleLoggerFormat = Logger::DEFAULT_FORMAT);
		~ConsoleLogger();

		void	logTrace(const std::string& className, std::string message);
		void	logDebug(const std::string& className, std::string message);
		void	 logInfo(const std::string& className, std::string message);
		void	 logWarn(const std::string& className, std::string message);
		void	logError(const std::string& className, std::string message);
		void logCritical(const std::string& className, std::string message);

	private:
		static const std::string CLASS_NAME;
		std::shared_ptr<spdlog::logger> mConsoleLogger;
	};
}

#endif