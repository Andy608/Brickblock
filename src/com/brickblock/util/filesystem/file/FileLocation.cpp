#include <fstream>
#include "FileLocation.h"
#include "../directory/DirectoryLocation.h"
#include "../../logger/BBLogger.h"
using namespace bb;

const std::string FileLocation::TXT_EXT = ".txt";
const std::string FileLocation::PNG_EXT = ".png";
const std::string FileLocation::OBJ_EXT = ".obj";
const std::string FileLocation::VS_EXT = ".vs";
const std::string FileLocation::FS_EXT = ".fs";

FileLocation::FileLocation(const DirectoryLocation& PARENT_DIR, std::string fileName, const std::string& EXT) :
	mPARENT_DIRECTORY(PARENT_DIR), mFILE_NAME(fileName), mFILE_EXTENSION(EXT), mIsCreated(GL_FALSE)
{

}

FileLocation::~FileLocation()
{
	
}

const FileLocation& FileLocation::operator=(const FileLocation& another)
{
	return another;
}

std::string FileLocation::getName() const
{
	return mFILE_NAME;
}

const std::string& FileLocation::getExt() const
{
	return mFILE_EXTENSION;
}

std::string FileLocation::getNameAndExt() const
{
	return mFILE_NAME + mFILE_EXTENSION;
}

std::string FileLocation::getParentPath() const
{
	return mPARENT_DIRECTORY.getPath();
}

std::string FileLocation::getPath() const
{
	if (mPARENT_DIRECTORY.getPath().length() == 0)
	{
		return getNameAndExt();
	}
	else
	{
		return mPARENT_DIRECTORY.getPath() + "/" + getNameAndExt();
	}
}

const DirectoryLocation& FileLocation::getParentDirectory() const
{
	return mPARENT_DIRECTORY;
}

GLboolean FileLocation::isExist()
{
	std::ifstream inFileStream(getPath());
	mIsCreated = inFileStream.good();
	return mIsCreated;
}

GLboolean FileLocation::createFile()
{
	std::ofstream outFileStream;

	outFileStream.open(getPath(), std::fstream::app);

	if (outFileStream.good())
	{
		mIsCreated = GL_TRUE;
	}
	else
	{
		mIsCreated = GL_FALSE;
	}

	outFileStream.close();

	return mIsCreated;
}