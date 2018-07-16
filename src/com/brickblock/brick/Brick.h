#ifndef BB_BRICK_H_
#define BB_BRICK_H_

#include <glad/glad.h>
#include <string>
#include "../util/logger/BBLogger.h"
#include "util/BrickUtil.h"
#include "util/BrickType.h"
#include <unordered_set>

namespace bb
{
	class Brick
	{
		friend class BrickRegistrar;
		friend class BrickList;

	public:
		//For now. Luminosity, hardness, and others will come later.
		Brick(const GLushort brickID, std::string unlocalizedName, const EnumBrickMaterial& brickMaterial);
		virtual ~Brick() = 0;

		const GLushort& getBrickID() const;
		const std::string& getUnlocalizedName() const;
		const EnumBrickMaterial& getMaterialType() const;

		const BrickType* getBrickType(const EnumBrickModel& modelID, const EnumBrickDirection& directionID) const;

	private:
		std::unordered_set<const BrickType*>* mpBrickTypes;

		Brick(const Brick &copy) = delete;
		void operator=(const Brick &copy) = delete;

		//Bricks facing each direction. They all have the same id, but have different metadata values.
		//When brick is dropped it drops directionless BrickItem. When placed, depending on the direction, the correct brick gets returned from this list.

		const GLushort mBRICK_ID;
		const std::string mUNLOCALIZED_NAME;
		const EnumBrickMaterial& mMATERIAL;

		void addBrickType(const BrickType* brickType);
	};
}

#endif