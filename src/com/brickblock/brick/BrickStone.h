#ifndef BB_BRICK_STONE_H_
#define BB_BRICK_STONE_H_

#include "Brick.h"

namespace bb
{
	class BrickStone : public Brick
	{
	public:
		BrickStone(const GLushort brickID, std::string unlocalizedName, const EnumBrickMaterial& brickMaterial);
		virtual ~BrickStone();
	};
}

#endif