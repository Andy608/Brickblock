#include "Zone.h"
#include "../../util/logger/BBLogger.h"
#include "../../brick/util/BrickList.h"
#include "../../brick/Brick.h"
using namespace bb;

Zone::Zone() :
	mVoxels(nullptr)
{
	BBLogger::logInfo("Zone", "Creating test Zone!");

	mVoxels = new ZoneVoxel*[ZONE_WIDTH * ZONE_HEIGHT * ZONE_LENGTH];
	mVoxels[0] = new ZoneVoxel(BrickList::STONE->getBrickID(), 
		*BrickList::STONE->getBrickType(EnumBrickModel::BRICK_1x1, EnumBrickDirection::DIRECTIONLESS), new glm::vec3());
}

Zone::~Zone()
{
	if (mVoxels)
	{
		unsigned int i;
		for (i = 0; i < VOXELS_IN_ZONE; ++i)
		{
			if (mVoxels[i])
			{
				delete mVoxels[i];
			}
		}

		delete[] mVoxels;
	}
}

void Zone::update(const GLdouble& deltaTime)
{

}

void Zone::render(const GLdouble& alpha)
{

}