#ifndef BB_BRICKINFO_H_
#define BB_BRICKINFO_H_

#include <glad/glad.h>

namespace bb
{
	struct BrickInfo
	{
		enum class BrickModelID : GLushort //0 - 65,535
		{
			PLATE_1x1,
			PLATE_1x2,
			PLATE_1x3,
			BRICK_1x1,
		};

		enum class BrickMaterial : GLuint
		{
			GRASS,
			DIRT,
			STONE,
			GLASS,
			ICE
		};
	};
}

#endif