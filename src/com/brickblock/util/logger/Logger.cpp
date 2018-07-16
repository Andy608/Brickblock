#include "Logger.h"
using namespace bb;

const std::string Logger::DEFAULT_FORMAT = "[%x %r] %l (Logger:%n) %v";

Logger::Logger(std::string loggerFormat) : mFORMAT(loggerFormat)
{
	
}

Logger::~Logger()
{

}

std::string Logger::getFormattedMessage(const std::string& className, std::string message)
{
	return "[" + className + ".cpp] - " + message;
}