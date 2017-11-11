/*#ifndef BB_LOGGERUTIL_H_
#define BB_LOGGERUTIL_H_

#include <log4cxx\consoleappender.h>
#include <log4cxx\fileappender.h>
#include <log4cxx\patternlayout.h>
#include <string>
#include "Logger.h"
#include "FileDirectory.h"
#include "FileLocation.h"

namespace bb
{
	class LoggerUtil
	{
	public:
		static LoggerUtil *instance;

		static LoggerUtil* init();
		static void initConsoleAppender();
		static void initFileAppender();

		~LoggerUtil();

	private:
		static const std::wstring CONSOLE_HEADING;
		static const std::wstring FILE_HEADING;
		static Logger *logger;

		static GLboolean isConsoleAppender;
		static GLboolean isFileAppender;

		const FileDirectory* mLOGGER_DIRECTORY;
		const FileLocation* mLOG_FILE;

		log4cxx::LayoutPtr mConsoleLayout;
		log4cxx::LayoutPtr mFileLayout;
		log4cxx::ConsoleAppenderPtr mConsoleAppender;
		log4cxx::FileAppenderPtr mFileAppender;

		LoggerUtil();
	};
}

#endif*/