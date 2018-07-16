#include "StringFileReader.h"
#include "../FileLocation.h"
#include "../../../logger/BBLogger.h"
using namespace bb;

const std::string StringFileReader::CLASS_NAME = "StringFileReader.cpp";

StringFileReader::StringFileReader() :
	mReadStream(new std::ifstream()), mStringStream(new std::stringstream())
{

}

StringFileReader::~StringFileReader()
{
	delete mReadStream;
	delete mStringStream;
}

void StringFileReader::getContents(const FileLocation& FILE, std::string& fileContents)
{
	mReadStream->open(FILE.getPath(), std::ifstream::in);

	if (mReadStream->is_open())
	{
		mStringStream->str(std::string());
		*mStringStream << mReadStream->rdbuf();
		fileContents = mStringStream->str();
		//BBLogger::logDebug(CLASS_NAME, "File Contents : " + fileContents, Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}
	else
	{
		BBLogger::logError(CLASS_NAME, "Unable to read file: " + FILE.getPath(), Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}

	mReadStream->close();
}

void StringFileReader::getContentsByLine(const FileLocation& FILE, std::vector<std::string>& fileContents)
{
	mReadStream->open(FILE.getPath(), std::ifstream::in);

	if (mReadStream->is_open())
	{
		fileContents.clear();
		std::string line;

		while (std::getline(*mReadStream, line))
		{
			fileContents.push_back(line);
		}
	}
	else
	{
		BBLogger::logError(CLASS_NAME, "Unable to read file: " + FILE.getPath(), Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}

	mReadStream->close();
}