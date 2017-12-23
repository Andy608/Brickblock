#ifndef BB_BBLOGGER_H_
#define BB_BBLOGGER_H_

#include "../filesystem/Directory/DirectoryList.h"
#include "../filesystem/directory/DirectoryLocation.h"
#include "../filesystem/file/FileLocation.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

namespace bb
{
	class ConsoleLogger;
	class FileLogger;

	class BBLogger
	{
	private:
		const std::string mFORMAT;
		ConsoleLogger *mConsoleLogger;
		FileLogger *mFileLogger;

		BBLogger(ConsoleLogger *consoleLogger, FileLogger *fileLogger);
		~BBLogger();

	public:
		static BBLogger& getLogger()
		{
			static ConsoleLogger *consoleLogger = new ConsoleLogger("BBConsoleLogger", Logger::DEFAULT_FORMAT, spdlog::level::trace);
			static FileLocation *fileLoggerLocation = new FileLocation(*DirectoryList::getInstance().mLoggerDirectory, "log", FileLocation::TXT_EXT);
			static FileLogger *fileLogger = new FileLogger("BBFileLogger", fileLoggerLocation, Logger::DEFAULT_FORMAT, spdlog::level::trace);
			static BBLogger instance(consoleLogger, fileLogger);
			return instance;
		}

		void	logTrace(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
		void	logDebug(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
		void	 logInfo(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
		void	 logWarn(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
		void	logError(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
		void logCritical(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION);
	};
}

#endif