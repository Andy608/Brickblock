#include <iostream>
#include "Brickblock.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "../util/libs/spdlog/spdlog.h"
#include "../util/filesystem/directory/DirectoryList.h"
#include "../util/logger/BBLogger.h"
using namespace bb;

static const std::string CLASS_NAME = "Main.cpp";

int main(int argc, int **argv)
{
	GLint exitResult = EXIT_SUCCESS;
	Brickblock *brickblock = nullptr;
	DirectoryList::getInstance().init();
	
	/*BBLogger::logTrace(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::logDebug(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::logInfo(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::logWarn(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::logError(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::logCritical(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);

	BBLogger::logTrace(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::logDebug(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::logInfo(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::logWarn(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::logError(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::logCritical(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);

	BBLogger::logTrace(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::logDebug(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::logInfo(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::logWarn(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::logError(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::logCritical(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);*/

	try
	{
		brickblock = &Brickblock::getInstance();
		brickblock->start(argc, argv);
	}
	catch (std::string e)
	{
		exitResult = EXIT_FAILURE;
	}
	catch (...)
	{
		BBLogger::logCritical(CLASS_NAME, "Well this is awkward... There was a crash that I couldn't recover from.");
	}

	std::cin.get();
	return exitResult;
}