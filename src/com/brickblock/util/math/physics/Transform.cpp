#include "Transform.h"
using namespace bb;

Transform::Transform() :
	mPosition(glm::vec3()),
	mRotation(glm::vec3()),
	mScale(glm::vec3())
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