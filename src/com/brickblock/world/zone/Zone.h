#ifndef BB_ZONE_H_
#define BB_ZONE_H_

#include <glm/vec3.hpp>
#include "../../brick/util/BrickType.h"
#include "voxel/ZoneVoxel.h"

namespace bb
{
	class Zone
	{
	public:
		Zone();
		~Zone();

		void update(const GLdouble& deltaTime);
		void render(const GLdouble& alpha);

	private:
		static const int ZONE_WIDTH = 16;
		static const int ZONE_HEIGHT = 48;
		static const int ZONE_LENGTH = 16;
		static const int VOXELS_IN_ZONE = ZONE_WIDTH * ZONE_HEIGHT * ZONE_LENGTH;

		glm::vec3 mZoneCoord;
		
		//1D array holds 3D zone information.
		ZoneVoxel** mVoxels;
	};
}

#endif