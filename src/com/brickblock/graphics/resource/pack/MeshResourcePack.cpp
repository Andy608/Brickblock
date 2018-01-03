#include "MeshResourcePack.h"
#include "../../../util/filesystem/file/FileLocation.h"
#include "../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

Mesh* MeshResourcePack::testMesh = nullptr;

MeshResourcePack::MeshResourcePack() :
	ResourcePack(ResourceManager::ResourceType::MESH)
{

}

void MeshResourcePack::load()
{
	//Load all mess objects here.
	testMesh = new Mesh(new FileLocation(*DirectoryList::getInstance().mMeshDirectory, "test_cube", FileLocation::OBJ_EXT));

	registerResource(testMesh);

	ResourcePack::load();
}
