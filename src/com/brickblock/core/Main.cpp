#include <iostream>
#include "Brickblock.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "../util/libs/spdlog/spdlog.h"
using namespace bb;

int main(int argc, int **argv)
{
	GLint exitResult = EXIT_SUCCESS;
	Brickblock *brickblock = nullptr;

	//[%5p] (%c.cpp:%L) T%r - %m%n
	//L"%d{MM/dd/yyyy} %d{%I:%M:%S} [%5p | Thread: %t] (%c.cpp:%L) T%r	- %m%n";
	spdlog::set_pattern("[%x %r] %l (Logger:%n) - %v");
	auto console = spdlog::stdout_color_mt("console");
	console->info("Welcome to spdlog!");
	console->error("Some error message with arg{}..", 1);
	spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name) function");

	console->warn("Easy padding in numbers like {:08d}", 12);
	console->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	console->info("Support for floats {:03.2f}", 1.23456);
	console->info("Positional args are {1} {0}..", "too", "supported");
	console->debug("{:>30}", "right aligned");

	// Create basic file logger (not rotated)
	auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
	my_logger->info("Some log message");
	my_logger->flush();

	DirectoryLocation *directoryTest = nullptr;
	FileLocation *fileLocation = nullptr;

	//Brickblock::bbLogger.logInfo("Main.cpp", "TESTING");

	try
	{
		directoryTest = new DirectoryLocation("", "BITCH", true);
		directoryTest->createDirectory();

		fileLocation = new FileLocation(*directoryTest, "hello", FileLocation::TXT_EXT);
		console->info(fileLocation->getName());
		console->info(fileLocation->getExt());
		console->info(fileLocation->getNameAndExt());
		console->info(fileLocation->getParentDirectory().getPath());
		console->info(fileLocation->getParentPath());
		console->info(fileLocation->getPath());
		console->info(fileLocation->isCreated());
		fileLocation->createFile();
		console->info(fileLocation->isCreated());

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
	
	delete directoryTest;
	delete fileLocation;

	return exitResult;
}