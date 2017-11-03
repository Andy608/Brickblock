#include <log4cxx\basicconfigurator.h>
#include "Logger.h"

using namespace bb;

Logger::Logger(std::string loggerName) : 
	mLOGGER_NAME(loggerName),
	mLogger(log4cxx::LoggerPtr(log4cxx::Logger::getLogger(mLOGGER_NAME)))
{

}

Logger::~Logger()
{

}

void Logger::setMinimumLevel(const Level& minimumLogLevel)
{
	mMinimumLoggerLevel = minimumLogLevel;
	switch (mMinimumLoggerLevel)
	{
	case Level::LEVEL_TRACE:
		mLogger->setLevel(log4cxx::Level::getTrace());
		break;
	case Level::LEVEL_DEBUG:
		mLogger->setLevel(log4cxx::Level::getDebug());
		break;
	case Level::LEVEL_WARN:
		mLogger->setLevel(log4cxx::Level::getWarn());
		break;
	case Level::LEVEL_ERROR:
		mLogger->setLevel(log4cxx::Level::getError());
		break;
	case Level::LEVEL_FATAL:
		mLogger->setLevel(log4cxx::Level::getFatal());
		break;
	default:
		mLogger->setLevel(log4cxx::Level::getInfo());
		break;
	}
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

const std::string& Logger::getName() const
{
	return mLOGGER_NAME;
}