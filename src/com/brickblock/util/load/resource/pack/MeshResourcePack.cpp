#include "MeshResourcePack.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
#include "FileLocResourcePack.h"
#include "../mesh/MeshFactory.h"
#include "../list/FileLocationList.h"
#include "../list/MeshList.h"
using namespace bb;

MeshResourcePack *MeshResourcePack::instance = nullptr;

const std::string MeshResourcePack::MESH__TEST = "mesh__test";

void MeshResourcePack::init()
{
	if (!instance)
	{
		instance = new MeshResourcePack("mesh");
	}
}

MeshResourcePack::MeshResourcePack(std::string resourceID) :
	ResourcePack(resourceID)
{

}

void MeshResourcePack::load()
{
	const FileLocResourcePack& fileLoc = FileLocResourcePack::getInstance();

	//Load all mess objects here.
	Mesh *testMesh = new Mesh(MESH__TEST, FileLocationList::getInstance().meshFileLocation);

	registerResource(testMesh);

	ResourcePack::load();
	
	MeshList::init();
}
