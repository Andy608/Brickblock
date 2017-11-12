#include "DirectoryLocation.h"
#include "../StringUtil.h"
using namespace bb;


DirectoryLocation::DirectoryLocation(std::string parentPath, std::string directoryName, const EnumPathType& PATH_TYPE) :
	mPARENT_PATH(parentPath), mDIRECTORY_NAME(directoryName), mIS_PATH_RELATIVE(PATH_TYPE), mIsCreated(GL_FALSE)
{
	
}

DirectoryLocation::~DirectoryLocation()
{
	//logger.log(Logger::LEVEL_DEBUG, "DELETING DIRECTORY LOCATION");
}

std::string DirectoryLocation::getPath() const
{
	if (mPARENT_PATH.length() > 0)
	{
		return mPARENT_PATH + "/" + mDIRECTORY_NAME;
	}
	else
	{
		return mDIRECTORY_NAME;
	}
}

std::string DirectoryLocation::getParentPath() const
{
	return mPARENT_PATH;
}

std::string DirectoryLocation::getDirectoryName() const
{
	return mDIRECTORY_NAME;
}

GLboolean DirectoryLocation::isPathRelative() const
{
	return mIS_PATH_RELATIVE;
}

GLboolean DirectoryLocation::createDirectory()
{
	try
	{
		if (CreateDirectoryW(StringUtil::stow(getPath()).c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
		{
			mIsCreated = GL_TRUE;
			//logger.log(Logger::LEVEL_DEBUG, "Valid directory at: \'" + getPath() + "\'.");
		}
		else
		{
			mIsCreated = GL_FALSE;
			//throw std::invalid_argument("Could not create directory with path: \'" + getPath() + "\'.");
		}
	}
	catch (const std::exception& e)
	{
		e.what();
		//logger.log(Logger::LEVEL_ERROR, e.what());
	}

	return mIsCreated;
}

GLboolean DirectoryLocation::isDirectoryCreated() const
{
	return mIsCreated;
}

DirectoryLocation::operator std::string() const
{
	return mDIRECTORY_NAME;
}