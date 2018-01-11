#ifndef BB_MATHHELER_H_
#define BB_MATHHELPER_H_

#include <glad/glad.h>
#include <glm/vec3.hpp>

namespace bb
{
	struct MathHelper
	{
	public:
		static GLfloat PI;

		static GLfloat toRadians(const GLfloat& degrees);
		static GLfloat toDegrees(const GLfloat& radians);

		static GLfloat magnitudeSquared(glm::vec3 &vec);
	};
}

#endif