#include "MatrixUtil.h"
#include <glm/gtx/rotate_vector.hpp>
#include "MathHelper.h"
using namespace bb;

//right handed system
glm::vec3 MatrixUtil::WORLD_RIGHT = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 MatrixUtil::WORLD_UP = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 MatrixUtil::WORLD_FORWARD = glm::vec3(0.0f, 0.0f, 1.0f);

void MatrixUtil::rotateAboutXAxis(glm::vec3& vec, GLfloat angle)
{
	vec = glm::rotateX(vec, angle);
}

void MatrixUtil::rotateAboutYAxis(glm::vec3& vec, GLfloat angle)
{
	vec = glm::rotateY(vec, angle);
}

void MatrixUtil::rotateAboutZAxis(glm::vec3& vec, GLfloat angle)
{
	vec = glm::rotateZ(vec, angle);
}

glm::mat4x4 MatrixUtil::createTranslationMat(const glm::vec3 &position)
{
	glm::mat4x4 translationMat;
	return glm::translate(translationMat, position);
}

glm::mat4x4 MatrixUtil::createRotationMat(const glm::vec3 &rotation)
{
	glm::mat4x4 rotationMat;
	rotationMat = glm::rotate(rotationMat, MathHelper::toRadians(rotation.x), WORLD_RIGHT);
	rotationMat = glm::rotate(rotationMat, MathHelper::toRadians(rotation.y), WORLD_UP);
	rotationMat = glm::rotate(rotationMat, MathHelper::toRadians(rotation.z), WORLD_FORWARD);
	return rotationMat;
}

glm::mat4x4 MatrixUtil::createScaleMat(const glm::vec3 &scale)
{
	glm::mat4x4 scaleMat;
	return glm::scale(scaleMat, scale);
}

//Roatation sent in degrees
glm::mat4x4 MatrixUtil::createTransformationMat(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
{
	return createTranslationMat(position) * createRotationMat(rotation) * createScaleMat(scale);
}

std::string MatrixUtil::to_string(const glm::mat4x4 &mat)
{
	std::string s = "\n[\n";

	GLuint row, col;
	for (col = 0; col < 4; ++col)
	{
		for (row = 0; row < 4; ++row)
		{
			s.append(std::to_string(mat[col][row]));

			if (row != 3)
			{
				s.append(", ");
			}
		}
		
		s.append("\n");
	}

	s.append("]\n");

	return s;
}