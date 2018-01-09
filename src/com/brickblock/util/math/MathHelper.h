#ifndef BB_MATHHELER_H_
#define BB_MATHHELPER_H_

#include <glad/glad.h>

namespace bb
{
	struct MathHelper
	{
	public:
		static GLfloat PI;

		static GLfloat toRadians(const GLfloat& degrees);
		static GLfloat toDegrees(const GLfloat& radians);
		//static void toRadians(GLfloat& degrees);
		//static void toDegrees(GLfloat& radians);
	};
}

#endif