#include "BrickType.h"
using namespace bb;

BrickType::BrickType(const EnumBrickModel& modelID, const EnumBrickDirection& directionID) :
	mMODEL_ID(modelID),
	mDIRECTION_ID(directionID)
{

}

BrickType::~BrickType()
{

}

