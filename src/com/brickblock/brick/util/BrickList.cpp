#include "BrickList.h"

#include "../../util/logger/BBLogger.h"
#include "BrickRegistrar.h"
using namespace bb;

const BrickStone* BrickList::STONE = nullptr;

void BrickList::createBricks()
{
	BrickStone* stone = new BrickStone(0, "stone_brick", EnumBrickMaterial::STONE);
	//Move this to BrickFactory class and have methods to make this more streamlined.
	//BrickFactory::addModelType(0-100, All directions);
	stone->addBrickType(new BrickType(EnumBrickModel::BRICK_1x1));
	stone->addBrickType(new BrickType(EnumBrickModel::PLATE_1x1));
	STONE = stone;
}

void BrickList::registerBricks()
{
	BrickRegistrar::registerBrick(STONE);
}