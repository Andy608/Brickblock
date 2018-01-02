#include "MeshResourcePack.h"
#include "../mesh/Mesh.h"
#include "../../../util/filesystem/file/FileLocation.h"
#include "../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

MeshResourcePack::MeshResourcePack() :
	ResourcePack(ResourceManager::ResourceType::MESH)
{

}

void MeshResourcePack::load()
{
	//Load all mess objects here.
	Mesh *testModel = new Mesh(new FileLocation(*DirectoryList::getInstance().mMeshDirectory, "test_cube", FileLocation::OBJ_EXT));

	registerResource(testModel);

	ResourcePack::load();
}
