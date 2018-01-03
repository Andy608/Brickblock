#ifndef BB_MATRIXUTIL_H_
#define BB_MATRIXUTIL_H_

#include <glad/glad.h>
#include <glm/vec3.hpp>

namespace bb
{
	struct MatrixUtil
	{
		static void rotateAboutXAxis(glm::vec3& vec, GLfloat angle);
		static void rotateAboutYAxis(glm::vec3& vec, GLfloat angle);
		static void rotateAboutZAxis(glm::vec3& vec, GLfloat angle);
	};
}

#endif