#include <iostream>
#include "Brickblock.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "../util/libs/spdlog/spdlog.h"
#include "../util/filesystem/directory/DirectoryList.h"
using namespace bb;

static const std::string CLASS_NAME = "Main.cpp";

int main(int argc, int **argv)
{
	GLint exitResult = EXIT_SUCCESS;
	Brickblock *brickblock = nullptr;
	DirectoryList::getInstance().init();
	
	BBLogger::getLogger().logTrace(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::getLogger().logDebug(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::getLogger().logInfo(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::getLogger().logWarn(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::getLogger().logError(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);
	BBLogger::getLogger().logCritical(CLASS_NAME, "CONSOLE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE);

	BBLogger::getLogger().logTrace(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::getLogger().logDebug(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::getLogger().logInfo(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::getLogger().logWarn(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::getLogger().logError(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);
	BBLogger::getLogger().logCritical(CLASS_NAME, "FILE HELLO WORLD!!!", Logger::EnumLogLocation::FILE);

	BBLogger::getLogger().logTrace(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::getLogger().logDebug(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::getLogger().logInfo(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::getLogger().logWarn(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::getLogger().logError(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	BBLogger::getLogger().logCritical(CLASS_NAME, "CONSOLE AND FILE HELLO WORLD!!!", Logger::EnumLogLocation::CONSOLE_AND_FILE);


	try
	{
		brickblock = Brickblock::init(argc, argv);
		brickblock->start();
	}
	catch (std::string e)
	{
		exitResult = EXIT_FAILURE;
	}
	catch (...)
	{
		//logger.log(Logger::LEVEL_FATAL, "Well this is awkward... There was a crash that I can't recover from :(");
	}

	if (brickblock != nullptr)
	{
		delete brickblock;
	}

	return exitResult;
}