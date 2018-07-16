#ifndef BB_BRICK_UTIL_H_
#define BB_BRICK_UTIL_H_

#include <glad/glad.h>

namespace bb
{
	//For now. This will be moved somewhere else where a material is a class and each material can be created with values like
	//light reflectivity, sound and texture.
	enum class EnumBrickMaterial : GLushort //0 - 65,535
	{
		GRASS,
		DIRT,
		STONE,
		GLASS,
		ICE
	};

	enum class EnumBrickModel : GLushort //0 - 65,535
	{
		PLATE_1x1,
		PLATE_1x2,
		PLATE_1x3,
		BRICK_1x1
	};

	enum class EnumBrickDirection : GLubyte //0-255
	{
		DIRECTIONLESS,
		EAST,
		NORTH,
		WEST,
		SOUTH
	};
}

#endif