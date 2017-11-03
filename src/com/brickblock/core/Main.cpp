#include <iostream>
#include "Brickblock.h"
#include "../util/logger/LoggerUtil.h"
using namespace bb;

int main(int argc, int **argv)
{
	LoggerUtil::init();
	LoggerUtil::initConsoleAppender();
	//DirectoryUtil::init();
	//LoggerUtil::initFileAppender();
	
	Logger logger = Logger("main");
	logger.setMinimumLevel(Logger::LEVEL_TRACE);

	GLint exitResult = EXIT_SUCCESS;
	Brickblock *brickblock = nullptr;

	logger.log(Logger::LEVEL_INFO, "Starting the game!");

	try
	{
		brickblock = Brickblock::init(argc, argv);
		brickblock->start();
	}
	catch (std::string e)
	{
		logger.log(Logger::LEVEL_ERROR, e);
		exitResult = EXIT_FAILURE;
	}
	catch (log4cxx::helpers::Exception& e)
	{
		logger.log(Logger::LEVEL_ERROR, e.what());
		exitResult = EXIT_FAILURE;
	}

	if (brickblock != nullptr)
	{
		delete brickblock;
	}

	logger.log(Logger::LEVEL_INFO, "Exiting the game!");
	std::cin.get();

	return exitResult;
}