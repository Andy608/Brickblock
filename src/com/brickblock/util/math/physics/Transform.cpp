#include "Transform.h"
#include "../MatrixUtil.h"
#include <glm/common.hpp>
using namespace bb;

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
	mPosition(position),
	mRotation(rotation),
	mScale(scale),
	mPrevPosition(position),
	mPrevRotation(rotation),
	mPrevScale(scale),
	mLerpedPosition(position),
	mLerpedRotation(rotation),
	mLerpedScale(scale),
	mTransformationMatrix(MatrixUtil::createTransformationMat(mPosition, mRotation, mScale))
{

}

Transform::~Transform()
{

}

void Transform::syncPrevTransforms()
{
	mPrevPosition = mPosition;
	mPrevRotation = mRotation;
	mPrevScale = mScale;
}

void Transform::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::setRotation(GLfloat x, GLfloat y, GLfloat z)
{
	mRotation.x = x;
	mRotation.y = y;
	mRotation.z = z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::setScale(GLfloat x, GLfloat y, GLfloat z)
{
	mScale.x = x;
	mScale.y = y;
	mScale.z = z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::setPivot(GLfloat x, GLfloat y, GLfloat z)
{
	mPivot.x = x;
	mPivot.y = y;
	mPivot.z = z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}


void Transform::addPosition(GLfloat x, GLfloat y, GLfloat z)
{
	mPosition.x += x;
	mPosition.y += y;
	mPosition.z += z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::addPosition(const glm::vec3& ANOTHER)
{
	mPosition += ANOTHER;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::addRotation(GLfloat x, GLfloat y, GLfloat z)
{
	mRotation.x += x;
	mRotation.y += y;
	mRotation.z += z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::addRotation(const glm::vec3& ANOTHER)
{
	mRotation += ANOTHER;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::addScale(GLfloat x, GLfloat y, GLfloat z)
{
	mScale.x += x;
	mScale.y += y;
	mScale.z += z;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::addScale(const glm::vec3& ANOTHER)
{
	mScale += ANOTHER;
	updateTransformationMatrix(mPosition, mRotation, mScale);
}

void Transform::lerp(const GLdouble &alpha)
{
	mLerpedPosition = glm::mix(mPrevPosition, mPosition, alpha);
	mLerpedRotation = glm::mix(mPrevRotation, mRotation, alpha);
	mLerpedScale = glm::mix(mPrevScale, mScale, alpha);

	updateTransformationMatrix(mLerpedPosition, mLerpedRotation, mLerpedScale);
}

void Transform::update()
{
	mPrevPosition = mPosition;
	mPrevRotation = mRotation;
	mPrevScale = mScale;
}

void Transform::updateTransformationMatrix(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale)
{
	mTransformationMatrix = MatrixUtil::createTransformationMat(pos, rot, scale);
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

const glm::mat4x4& Transform::getTransformationMat() const
{
	return mTransformationMatrix;
}