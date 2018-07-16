#ifndef BB_MATRIXUTIL_H_
#define BB_MATRIXUTIL_H_

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <string>

namespace bb
{
	struct MatrixUtil
	{
		//right handed system
		static glm::vec3 WORLD_UP;
		static glm::vec3 WORLD_RIGHT;
		static glm::vec3 WORLD_FORWARD;

		static void rotateAboutXAxis(glm::vec3 &vec, GLfloat angle);
		static void rotateAboutYAxis(glm::vec3 &vec, GLfloat angle);
		static void rotateAboutZAxis(glm::vec3 &vec, GLfloat angle);

		static glm::mat4x4 createTranslationMat(const glm::vec3 &position);
		static glm::mat4x4 createRotationMat(const glm::vec3 &rotation);
		static glm::mat4x4 createScaleMat(const glm::vec3 &scale);

		static glm::mat3x3 createNormalMat(const glm::mat4 &transformationMat, const glm::mat4 &viewMat);

		static glm::mat4x4 createTransformationMat(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale);
	
		static std::string to_string(const glm::mat4x4 &mat);
	};
}

#endif