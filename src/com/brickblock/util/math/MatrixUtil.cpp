#include "MatrixUtil.h"
#include <glm/gtx/rotate_vector.hpp>
using namespace bb;

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