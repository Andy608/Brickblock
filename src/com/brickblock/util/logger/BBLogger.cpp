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
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logTrace(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logTrace(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logTrace(className, message);
		fileLogger->logTrace(className, message);
		break;
	}
}

void BBLogger::logDebug(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logDebug(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logDebug(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logDebug(className, message);
		fileLogger->logDebug(className, message);
		break;
	}
}

void BBLogger::logInfo(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logInfo(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logInfo(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logInfo(className, message);
		fileLogger->logInfo(className, message);
		break;
	}
}

void BBLogger::logWarn(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logWarn(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logWarn(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logWarn(className, message);
		fileLogger->logWarn(className, message);
		break;
	}
}

void BBLogger::logError(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logError(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logError(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logError(className, message);
		fileLogger->logError(className, message);
		break;
	}
}

void BBLogger::logCritical(const std::string& className, std::string message, const Logger::EnumLogLocation& LOG_LOCATION)
{
	BBLogger &logger = getLogger();
	ConsoleLogger *consoleLogger = logger.mConsoleLogger;
	FileLogger *fileLogger = logger.mFileLogger;

	switch (LOG_LOCATION)
	{
	case Logger::EnumLogLocation::CONSOLE:
		consoleLogger->logCritical(className, message);
		break;
	case Logger::EnumLogLocation::FILE:
		fileLogger->logCritical(className, message);
		break;
	case Logger::EnumLogLocation::CONSOLE_AND_FILE:
		consoleLogger->logCritical(className, message);
		fileLogger->logCritical(className, message);
		break;
	}
}