#include "ConsoleLogger.h"
using namespace bb;

const std::string ConsoleLogger::CLASS_NAME = "ConsoleLogger.cpp";

ConsoleLogger::ConsoleLogger(std::string consoleLoggerName, std::string consoleLoggerFormat, spdlog::level::level_enum loggerLevel) : Logger(consoleLoggerFormat),
	mConsoleLogger(spdlog::stdout_color_mt(consoleLoggerName))
{
	mConsoleLogger->set_pattern(mFORMAT);
	mConsoleLogger->set_level(loggerLevel);
	logInfo(CLASS_NAME, "Creating console logger!");
}

ConsoleLogger::~ConsoleLogger()
{
	//logInfo(CLASS_NAME, "Deleting console logger.");
}

void ConsoleLogger::logTrace(const std::string& className, std::string message)
{
	mConsoleLogger->trace(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}

void ConsoleLogger::logDebug(const std::string& className, std::string message)
{
	mConsoleLogger->debug(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}

void ConsoleLogger::logInfo(const std::string& className, std::string message)
{
	mConsoleLogger->info(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}

void ConsoleLogger::logWarn(const std::string& className, std::string message)
{
	mConsoleLogger->warn(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}

void ConsoleLogger::logError(const std::string& className, std::string message)
{
	mConsoleLogger->error(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}

void ConsoleLogger::logCritical(const std::string& className, std::string message)
{
	mConsoleLogger->critical(getFormattedMessage(className, message));
	mConsoleLogger->flush();
}
