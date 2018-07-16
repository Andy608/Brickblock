#ifndef BB_ZONE_VOXEL_H_
#define BB_ZONE_VOXEL_H_

#include "../../../brick/util/BrickType.h"
#include <glm/vec3.hpp>

namespace bb
{
	class ZoneVoxel
	{
	public:
		ZoneVoxel(const GLushort& brickID, const BrickType& brickType, const glm::vec3* pDistToBrickOrigin);
		~ZoneVoxel();

	private:
		const GLushort& mBRICK_ID;
		const BrickType& mBRICK_TYPE;
		const glm::vec3* mpDISTANCE_TO_BRICK_ORIGIN;
	};
}

#endif