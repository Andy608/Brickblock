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
	delete mAssetDirectory;
	
	delete mMeshDirectory;
	delete mShaderDirectory;
	delete mTextureDirectory;
}

void DirectoryList::init()
{
	mRootDirectory = new DirectoryLocation("", "", DirectoryLocation::RELATIVE_PATH);
	
	mLoggerDirectory = new DirectoryLocation(mRootDirectory->getPath(), "logs", DirectoryLocation::RELATIVE_PATH);
	mAssetDirectory = new DirectoryLocation(mRootDirectory->getPath(), "assets", DirectoryLocation::RELATIVE_PATH);
	
	mMeshDirectory = new DirectoryLocation(mAssetDirectory->getPath(), "meshes", DirectoryLocation::RELATIVE_PATH);
	mShaderDirectory = new DirectoryLocation(mAssetDirectory->getPath(), "shaders", DirectoryLocation::RELATIVE_PATH);
	mTextureDirectory = new DirectoryLocation(mAssetDirectory->getPath(), "textures", DirectoryLocation::RELATIVE_PATH);

	mRootDirectory->createDirectory();
	
	mLoggerDirectory->createDirectory();
	mAssetDirectory->createDirectory();
	
	mMeshDirectory->createDirectory();
	mShaderDirectory->createDirectory();
	mTextureDirectory->createDirectory();
}