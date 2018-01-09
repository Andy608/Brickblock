#include "MathHelper.h"
using namespace bb;

GLfloat MathHelper::PI = 3.14159265359f;

GLfloat MathHelper::toRadians(const GLfloat &degrees)
{
	return degrees * PI / 180.0f;
}

GLfloat MathHelper::toDegrees(const GLfloat &radians)
{
	return radians * 180.0f / PI;
}

/*void MathHelper::toRadians(GLfloat &degrees)
{
	degrees *= PI / 180.0f;
}

void MathHelper::toDegrees(GLfloat &radians)
{
	radians *= 180.0f / PI;
}*/