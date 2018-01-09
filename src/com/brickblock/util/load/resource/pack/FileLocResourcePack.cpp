#include "FileLocResourcePack.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
#include "../list/FileLocationList.h"
using namespace bb;

FileLocResourcePack *FileLocResourcePack::instance = nullptr;

const std::string FileLocResourcePack::LOC__TEST_MODEL_VS = "loc__test_model_vs";
const std::string FileLocResourcePack::LOC__TEST_MODEL_FS = "loc__test_model_fs";
const std::string FileLocResourcePack::LOC__TEST_MESH	 = "loc__test_mesh";
const std::string FileLocResourcePack::LOC__TEST_TEXTURE = "loc__test_texture";

void FileLocResourcePack::init()
{
	if (!instance)
	{
		instance = new FileLocResourcePack("file_location");
	}
}

FileLocResourcePack::FileLocResourcePack(std::string resourceID) :
	ResourcePack(resourceID)
{

}

void FileLocResourcePack::load()
{
	//Shader File Locations
	FileLocation *modelVSLocation = new FileLocation(LOC__TEST_MODEL_VS, *DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::VS_EXT);
	FileLocation *modelFSLocation = new FileLocation(LOC__TEST_MODEL_FS, *DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::FS_EXT);

	//Mesh File Locations.
	FileLocation *testMeshLocation = new FileLocation(LOC__TEST_MESH, *DirectoryList::getInstance().mMeshDirectory, "test_cube", FileLocation::OBJ_EXT);

	FileLocation *testImageLocation = new FileLocation(LOC__TEST_TEXTURE, *DirectoryList::getInstance().mTextureDirectory, "test_img", FileLocation::PNG_EXT);

	//Register Shader Locations.
	registerResource(modelVSLocation);
	registerResource(modelFSLocation);
	
	//Register Image Locations.
	registerResource(testImageLocation);

	//Register Mesh Locations.
	registerResource(testMeshLocation);

	ResourcePack::load();
	
	FileLocationList::init();
}
