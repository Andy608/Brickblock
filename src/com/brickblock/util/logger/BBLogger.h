#ifndef BB_BBLOGGER_H_
#define BB_BBLOGGER_H_

#include "../filesystem/Directory/DirectoryList.h"
#include "../filesystem/directory/DirectoryLocation.h"
#include "../filesystem/file/FileLocation.h"
#include "Logger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

namespace bb
{
	class BBLogger
	{
	public:
		static void	logTrace(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);
		static void	logDebug(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);
		static void	 logInfo(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);
		static void	 logWarn(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);
		static void	logError(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);
		static void logCritical(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION = Logger::EnumLogLocation::CONSOLE_AND_FILE);

	private:
		const std::string mFORMAT;
		ConsoleLogger *mConsoleLogger;
		FileLogger *mFileLogger;

		BBLogger(ConsoleLogger *consoleLogger, FileLogger *fileLogger);
		~BBLogger();

		static BBLogger& getLogger()
		{
			static ConsoleLogger *consoleLogger = new ConsoleLogger("BBConsoleLogger", Logger::DEFAULT_FORMAT, spdlog::level::trace);
			static FileLocation *fileLoggerLocation = new FileLocation("log_file", *DirectoryList::getInstance().mLoggerDirectory, "log", FileLocation::TXT_EXT);
			static FileLogger *fileLogger = new FileLogger("BBFileLogger", fileLoggerLocation, Logger::DEFAULT_FORMAT, spdlog::level::trace);
			static BBLogger instance(consoleLogger, fileLogger);
			return instance;
		}
	};
}

#endif