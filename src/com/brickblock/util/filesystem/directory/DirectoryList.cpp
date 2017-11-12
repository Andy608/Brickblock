#include "DirectoryList.h"
#include "DirectoryLocation.h"
using namespace bb;

DirectoryList::DirectoryList()
{

}

DirectoryList::~DirectoryList()
{
	delete mRootDirectory;
	delete mLoggerDirectory;
}

void DirectoryList::init()
{
	mRootDirectory = new DirectoryLocation("", "", DirectoryLocation::RELATIVE_PATH);
	mLoggerDirectory = new DirectoryLocation(mRootDirectory->getPath(), "logs", DirectoryLocation::RELATIVE_PATH);

	mRootDirectory->createDirectory();
	mLoggerDirectory->createDirectory();
}