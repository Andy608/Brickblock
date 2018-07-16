#ifndef BB_BRICK_TYPE_H_
#define BB_BRICK_TYPE_H_

#include "BrickUtil.h"

namespace bb
{
	class BrickType
	{
		friend class Brick;

	public:
		BrickType(const EnumBrickModel& modelID, const EnumBrickDirection& directionID = EnumBrickDirection::DIRECTIONLESS);
		~BrickType();

	private:
		const EnumBrickModel& mMODEL_ID;
		const EnumBrickDirection& mDIRECTION_ID;
	};
}

#endif