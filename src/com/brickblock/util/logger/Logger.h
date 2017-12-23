#ifndef BB_LOGGER_H_
#define BB_LOGGER_H_

#include <string>
#include <glad\glad.h>
#include "../libs/spdlog/spdlog.h"

namespace bb
{
	class Logger
	{
	protected:
		const std::string mFORMAT;

		std::string getFormattedMessage(const std::string& className, std::string message);

	public:
		static const std::string DEFAULT_FORMAT;

		enum class EnumLogLocation : GLuint
		{
			CONSOLE, FILE, CONSOLE_AND_FILE
		};

		Logger(std::string loggerFormat = DEFAULT_FORMAT);
		virtual ~Logger();

		virtual void	logTrace(const std::string& className, std::string message) = 0;
		virtual void	logDebug(const std::string& className, std::string message) = 0;
		virtual void	 logInfo(const std::string& className, std::string message) = 0;
		virtual void	 logWarn(const std::string& className, std::string message) = 0;
		virtual void	logError(const std::string& className, std::string message) = 0;
		virtual void logCritical(const std::string& className, std::string message) = 0;
	};
}

#endif