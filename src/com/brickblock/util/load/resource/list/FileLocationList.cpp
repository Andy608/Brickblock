#include "FileLocationList.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../Resource.h"
#include "../pack/FileLocResourcePack.h"
using namespace bb;

FileLocationList *FileLocationList::instance = nullptr;

void FileLocationList::init()
{
	if (!instance)
	{
		instance = new FileLocationList();
	}
}


const FileLocationList& FileLocationList::getInstance()
{
	return *instance;
}

FileLocationList::FileLocationList() :
	testFileLocation(dynamic_cast<FileLocation&>(FileLocResourcePack::getInstance().getResource(FileLocResourcePack::LOC__TEST_TEXTURE))),
	testModelVS(dynamic_cast<FileLocation&>(FileLocResourcePack::getInstance().getResource(FileLocResourcePack::LOC__TEST_MODEL_VS))),
	testModelFS(dynamic_cast<FileLocation&>(FileLocResourcePack::getInstance().getResource(FileLocResourcePack::LOC__TEST_MODEL_FS))),
	meshFileLocation(dynamic_cast<FileLocation&>(FileLocResourcePack::getInstance().getResource(FileLocResourcePack::LOC__TEST_MESH)))
{

}