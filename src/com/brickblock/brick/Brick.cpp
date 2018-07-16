#include "Brick.h"
using namespace bb;

Brick::Brick(const GLushort brickID, const std::string unlocalizedName, const EnumBrickMaterial& brickMaterial) :
	mBRICK_ID(brickID),
	mUNLOCALIZED_NAME(unlocalizedName),
	mMATERIAL(brickMaterial),
	mpBrickTypes(new std::unordered_set<const BrickType*>())
{

}

Brick::~Brick()
{
	std::unordered_set<const BrickType*>::iterator iter;

	for (iter = mpBrickTypes->begin(); iter != mpBrickTypes->end(); ++iter)
	{
		BBLogger::logWarn("Brick", "Deleting brick type.");
		delete *iter;
	}

	delete mpBrickTypes;
}

void Brick::addBrickType(const BrickType* brickType)
{
	if (mpBrickTypes->find(brickType) != mpBrickTypes->end())
	{
		BBLogger::logWarn("Brick", "Brick already has that brick type.");
		delete brickType;
	}
	else
	{
		BBLogger::logTrace("Brick", "Adding BrickType: [ ModelID: " + std::to_string(static_cast<int>(brickType->mMODEL_ID))
			+ "| DirectionID: " + std::to_string(static_cast<int>(brickType->mDIRECTION_ID)));
		mpBrickTypes->insert(brickType);
	}
}

const GLushort& Brick::getBrickID() const
{
	return mBRICK_ID;
}

const std::string& Brick::getUnlocalizedName() const
{
	return mUNLOCALIZED_NAME;
}

const EnumBrickMaterial& Brick::getMaterialType() const
{
	return mMATERIAL;
}

const BrickType* Brick::getBrickType(const EnumBrickModel& modelID, const EnumBrickDirection& directionID) const
{
	const BrickType* type = nullptr;

	//This is coming back false for some reason
	if (mpBrickTypes->find(&BrickType(modelID, directionID)) != mpBrickTypes->end())
	{
		type = *mpBrickTypes->find(&BrickType(modelID, directionID));
	}
	else
	{
		BBLogger::logError("Brick", "Could not find BrickType for Brick. Returning null.");
	}

	return type;
}