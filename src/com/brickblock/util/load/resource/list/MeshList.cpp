#include "MeshList.h"
#include "../mesh/Mesh.h"
#include "../pack/MeshResourcePack.h"
using namespace bb;

MeshList *MeshList::instance = nullptr;

void MeshList::init()
{
	if (!instance)
	{
		instance = new MeshList();
	}
}


const MeshList& MeshList::getInstance()
{
	return *instance;
}


MeshList::MeshList() :
	testMesh(dynamic_cast<Mesh&>(MeshResourcePack::getInstance().getResource(MeshResourcePack::MESH__TEST)))
{
	
}