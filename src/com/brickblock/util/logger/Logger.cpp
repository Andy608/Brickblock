#include <log4cxx\basicconfigurator.h>
#include "Logger.h"

using namespace bb;

const std::wstring Logger::CONSOLE_HEADER = L"[%5p] (%c.cpp:%L) T%r - %m%n";

Logger::Logger(std::string loggerName) : mLOGGER_NAME(loggerName)
{
	mConsoleLayout = new log4cxx::PatternLayout(CONSOLE_HEADER);
	mConsoleAppender = new log4cxx::ConsoleAppender(mConsoleLayout);
	log4cxx::BasicConfigurator::configure(log4cxx::AppenderPtr(mConsoleAppender));
	log4cxx::Logger::getRootLogger()->addAppender(mConsoleAppender);
	mLogger = log4cxx::LoggerPtr(log4cxx::Logger::getLogger(mLOGGER_NAME));

	log(LEVEL_DEBUG, "Sup!");
}

Logger::~Logger()
{
	log(LEVEL_DEBUG, "Bye bitch!");
}

void Logger::log(const Level &level, std::string message)
{
	switch (level)
	{
	case LEVEL_TRACE:
		LOG4CXX_TRACE(mLogger, message);
		break;
	case LEVEL_DEBUG:
		LOG4CXX_DEBUG(mLogger, message);
		break;
	case LEVEL_WARN:
		LOG4CXX_WARN(mLogger, message);
		break;
	case LEVEL_ERROR:
		LOG4CXX_ERROR(mLogger, message);
		break;
	case LEVEL_FATAL:
		LOG4CXX_FATAL(mLogger, message);
		break;
	default:
		LOG4CXX_INFO(mLogger, message);
		break;
	}
}

void Logger::log(std::string message)
{
	log(Level::LEVEL_INFO, message);
}