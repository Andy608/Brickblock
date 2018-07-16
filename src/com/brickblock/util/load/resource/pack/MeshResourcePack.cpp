#include "MeshResourcePack.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

MeshResourcePack *MeshResourcePack::instance = nullptr;

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
	//Load all mess objects here.
	mCubeMesh = new Mesh("mesh__cube", new FileLocation(*DirectoryList::getInstance().mMeshDirectory, "test_cube", FileLocation::OBJ_EXT));

	mStandardBrickTop = new Mesh("mesh__standard_brick_top", new FileLocation(*DirectoryList::getInstance().mBrickMeshDirectory, "top", FileLocation::OBJ_EXT));
	mStandardBrickBottom = new Mesh("mesh__standard_brick_bottom", new FileLocation(*DirectoryList::getInstance().mBrickMeshDirectory, "bottom", FileLocation::OBJ_EXT));
	mStandardBrickSide = new Mesh("mesh__standard_brick_side", new FileLocation(*DirectoryList::getInstance().mBrickMeshDirectory, "wall_south", FileLocation::OBJ_EXT));

	mStandardBrickTest = new Mesh("mesh__standard_brick_test", new FileLocation(*DirectoryList::getInstance().mBrickMeshDirectory, "brick_final", FileLocation::OBJ_EXT));

	registerResource(mCubeMesh);
	registerResource(mStandardBrickTop);
	registerResource(mStandardBrickBottom);
	registerResource(mStandardBrickSide);
	registerResource(mStandardBrickTest);

	ResourcePack::load();
}
