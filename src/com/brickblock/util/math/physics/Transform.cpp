#include "Transform.h"
using namespace bb;

//right handed system
glm::vec3 Transform::WORLD_RIGHT	= glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 Transform::WORLD_UP		= glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 Transform::WORLD_FORWARD	= glm::vec3(0.0f, 0.0f, 1.0f);

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
	mPosition(position),
	mRotation(rotation),
	mScale(scale)
{

}

Transform::~Transform()
{

}

void Transform::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
}

void Transform::setRotation(GLfloat x, GLfloat y, GLfloat z)
{
	mRotation.x = x;
	mRotation.y = y;
	mRotation.z = z;
}

void Transform::setScale(GLfloat x, GLfloat y, GLfloat z)
{
	mScale.x = x;
	mScale.y = y;
	mScale.z = z;
}

void Transform::setPivot(GLfloat x, GLfloat y, GLfloat z)
{
	mPivot.x = x;
	mPivot.y = y;
	mPivot.z = z;
}


void Transform::addPosition(GLfloat x, GLfloat y, GLfloat z)
{
	mPosition.x += x;
	mPosition.y += y;
	mPosition.z += z;
}

void Transform::addPosition(const glm::vec3& ANOTHER)
{
	mPosition += ANOTHER;
}

void Transform::addRotation(GLfloat x, GLfloat y, GLfloat z)
{
	mRotation.x += x;
	mRotation.y += y;
	mRotation.z += z;
}

void Transform::addRotation(const glm::vec3& ANOTHER)
{
	mRotation += ANOTHER;
}

void Transform::addScale(GLfloat x, GLfloat y, GLfloat z)
{
	mScale.x += x;
	mScale.y += y;
	mScale.z += z;
}

void Transform::addScale(const glm::vec3& ANOTHER)
{
	mScale += ANOTHER;
}

const glm::vec3& Transform::getPosition() const
{
	return mPosition;
}

const glm::vec3& Transform::getRotation() const
{
	return mRotation;
}

const glm::vec3& Transform::getScale() const
{
	return mScale;
}

const glm::vec3& Transform::getPivot() const
{
	return mPivot;
}