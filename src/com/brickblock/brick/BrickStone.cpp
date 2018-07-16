#include "BrickStone.h"
using namespace bb;

BrickStone::BrickStone(const GLushort brickID, std::string unlocalizedName, const EnumBrickMaterial& brickMaterial) :
	Brick(brickID, unlocalizedName, brickMaterial)
{

}

BrickStone::~BrickStone()
{

}