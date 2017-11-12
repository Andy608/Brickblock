#include "BBLogger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "../filesystem/directory/DirectoryList.h"
using namespace bb;

BBLogger::BBLogger(ConsoleLogger *consoleLogger, FileLogger *fileLogger) :
	mConsoleLogger(consoleLogger), mFileLogger(fileLogger)
{

}

BBLogger::~BBLogger()
{
	delete mConsoleLogger;
	delete mFileLogger;
}

void BBLogger::logTrace(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logTrace(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logTrace(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logTrace(className, message);
		mFileLogger->logTrace(className, message);
		break;
	}
}

void BBLogger::logDebug(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logDebug(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logDebug(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logDebug(className, message);
		mFileLogger->logDebug(className, message);
		break;
	}
}

void BBLogger::logInfo(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logInfo(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logInfo(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logInfo(className, message);
		mFileLogger->logInfo(className, message);
		break;
	}
}

void BBLogger::logWarn(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logWarn(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logWarn(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logWarn(className, message);
		mFileLogger->logWarn(className, message);
		break;
	}
}

void BBLogger::logError(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logError(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logError(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logError(className, message);
		mFileLogger->logError(className, message);
		break;
	}
}

void BBLogger::logCritical(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		mConsoleLogger->logCritical(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		mFileLogger->logCritical(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		mConsoleLogger->logCritical(className, message);
		mFileLogger->logCritical(className, message);
		break;
	}
}