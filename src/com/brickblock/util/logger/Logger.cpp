#include "Logger.h"
using namespace bb;

Logger::Logger(std::string loggerFormat) :
	mFORMAT(loggerFormat), mConsoleLogger(spdlog::stdout_color_mt("bbLogger"))
{
	mConsoleLogger->set_pattern(mFORMAT);
	mConsoleLogger->info("Creating Brickblock Logger!");
}

Logger::~Logger()
{

}

void Logger::logTrace(const std::string& className, std::string message, GLboolean logToFile)
{
	std::string logMessage = getFormattedMessage(className, message);
	mConsoleLogger->trace(logMessage);

	if (logToFile)
	{

	}
}

void Logger::logDebug(const std::string& className, std::string message, GLboolean logToFile)
{

}

void Logger::logInfo(const std::string& className, std::string message, GLboolean logToFile)
{

}

void Logger::logWarn(const std::string& className, std::string message, GLboolean logToFile)
{

}

void Logger::logError(const std::string& className, std::string message, GLboolean logToFile)
{

}

void Logger::logCritical(const std::string& className, std::string message, GLboolean logToFile)
{

}

std::string Logger::getFormattedMessage(const std::string& className, std::string message)
{
	return "[" + className + "] - " + message;
}