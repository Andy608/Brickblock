#include "ZoneVoxel.h"
using namespace bb;

ZoneVoxel::ZoneVoxel(const GLushort& brickID, const BrickType& brickType, const glm::vec3* pDistToBrickOrigin) :
	mBRICK_ID(brickID),
	mBRICK_TYPE(brickType),
	mpDISTANCE_TO_BRICK_ORIGIN(pDistToBrickOrigin)
{

}

ZoneVoxel::~ZoneVoxel()
{
	delete mpDISTANCE_TO_BRICK_ORIGIN;
}