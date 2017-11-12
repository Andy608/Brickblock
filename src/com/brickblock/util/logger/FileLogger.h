#ifndef BB_FILELOGGER_H_
#define BB_FILELOGGER_H_

#include "../libs/spdlog/spdlog.h"
#include "Logger.h"

namespace bb
{
	class FileLocation;

	class FileLogger : public Logger
	{
	public:
		FileLogger(std::string fileLoggerName, FileLocation *fileLocation, std::string fileLoggerFormat = Logger::DEFAULT_FORMAT);
		~FileLogger();

		void	logTrace(const std::string& className, std::string message);
		void	logDebug(const std::string& className, std::string message);
		void	 logInfo(const std::string& className, std::string message);
		void	 logWarn(const std::string& className, std::string message);
		void	logError(const std::string& className, std::string message);
		void logCritical(const std::string& className, std::string message);

	private:
		std::shared_ptr<spdlog::logger> mFileLogger;
		FileLocation *mFileLocation;
	};
}

#endif