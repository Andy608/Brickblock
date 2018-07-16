#include "FileLogger.h"
#include "../filesystem/file/FileLocation.h"
#include "BBLogger.h"
using namespace bb;

FileLogger::FileLogger(std::string fileLoggerName, FileLocation *fileLocation, std::string fileLoggerFormat, spdlog::level::level_enum loggerLevel) :
	Logger(fileLoggerFormat), mFileLocation(fileLocation), mFileLogger(spdlog::basic_logger_mt(fileLoggerName, fileLocation->getPath()))
{
	mFileLogger->set_pattern(mFORMAT);
	mFileLogger->set_level(loggerLevel);

	if (!mFileLocation->isExist())
	{
		mFileLocation->createFile();
	}
}

FileLogger::~FileLogger()
{
	delete mFileLocation;
}

void FileLogger::logTrace(const std::string& className, std::string message)
{
	mFileLogger->trace(getFormattedMessage(className, message));
	mFileLogger->flush();
}

void FileLogger::logDebug(const std::string& className, std::string message)
{
	mFileLogger->debug(getFormattedMessage(className, message));
	mFileLogger->flush();
}

void FileLogger::logInfo(const std::string& className, std::string message)
{
	mFileLogger->info(getFormattedMessage(className, message));
	mFileLogger->flush();
}

void FileLogger::logWarn(const std::string& className, std::string message)
{
	mFileLogger->warn(getFormattedMessage(className, message));
	mFileLogger->flush();
}

void FileLogger::logError(const std::string& className, std::string message)
{
	mFileLogger->error(getFormattedMessage(className, message));
	mFileLogger->flush();
}

void FileLogger::logCritical(const std::string& className, std::string message)
{
	mFileLogger->critical(getFormattedMessage(className, message));
	mFileLogger->flush();
}
