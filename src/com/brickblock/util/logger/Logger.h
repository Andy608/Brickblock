#ifndef BB_LOGGER_H_
#define BB_LOGGER_H_

#include <string>
#include <glad\glad.h>

#include "../libs/spdlog/spdlog.h"

namespace bb
{
	class Logger
	{
	public:
		Logger(std::string loggerFormat);
		~Logger();

		void	logTrace(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);
		void	logDebug(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);
		void	 logInfo(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);
		void	 logWarn(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);
		void	logError(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);
		void logCritical(const std::string& className, std::string message, GLboolean logToFile = GL_FALSE);

	private:
		const std::string mFORMAT;
		std::shared_ptr<spdlog::logger> mConsoleLogger;

		std::string getFormattedMessage(const std::string& className, std::string message);

	};
}

#endif