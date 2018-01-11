#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../util/logger/BBLogger.h"
#include "../../util/math/MatrixUtil.h"
#include "../../util/math/MathHelper.h"
#include "../../input/setting/GameSettings.h"
#include <GLFW/glfw3.h>
using namespace bb;

const GLfloat Camera::NEAR_PLANE = 0.001f;
const GLfloat Camera::FAR_PLANE = 100.0f;
glm::mat4 Camera::perspectiveMatrix;
glm::mat4 Camera::orthoMatrix;

Camera::Camera(glm::vec3 position) :
	mTransform(new Transform(position)),
	mLookDirection(glm::vec3(0.0, 0.0, -1.0))
{
	updateBasis();
	updateViewMatrix();
}


Camera::~Camera()
{
	delete mTransform;
}


void Camera::updateViewMatrix()
{
	mLookDirection = glm::vec3(0.0, 0.0, -1.0);
	MatrixUtil::rotateAboutXAxis(mLookDirection, mTransform->mLerpedRotation.x);
	MatrixUtil::rotateAboutYAxis(mLookDirection, mTransform->mLerpedRotation.y);
	MatrixUtil::rotateAboutZAxis(mLookDirection, mTransform->mLerpedRotation.z);
	mLookDirection = glm::normalize(mLookDirection);

	mViewMatrix = glm::lookAt(mTransform->mLerpedPosition, mTransform->mLerpedPosition + mLookDirection, mCameraUp);
}

void Camera::updateProjectionMatrix(GLint viewportWidth, GLint viewportHeight)
{
	BBLogger::logDebug("Camera.cpp", std::to_string(viewportWidth) + ", " + std::to_string(viewportHeight));

	//if (GraphicsOptions::isPerspective)
	perspectiveMatrix = glm::perspective(
		glm::radians(57.0f),
		static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight),
		NEAR_PLANE,
		FAR_PLANE);
	//else
	orthoMatrix = glm::ortho(
		-static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight),
		static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight),
		-1.0f,
		1.0f,
		NEAR_PLANE, FAR_PLANE);
}


void Camera::update(const GLdouble& deltaTime)
{
	mTransform->update();

	if (GameSettings::getMoveForwardKey().isPressed())
	{
		mMoveDirection = mCameraForward;
	}

	if (GameSettings::getMoveBackwardKey().isPressed())
	{
		mMoveDirection += -mCameraForward;
	}

	if (GameSettings::getMoveLeftKey().isPressed())
	{
		mMoveDirection -= mCameraRight;
	}

	if (GameSettings::getMoveRightKey().isPressed())
	{
		mMoveDirection += mCameraRight;
	}

	if (MathHelper::magnitudeSquared(mMoveDirection) > 0)
	{
		mMoveDirection = glm::normalize(mMoveDirection);
		mTransform->addPosition((float)(5.0 * deltaTime) * mMoveDirection);
	}

	mMoveDirection.x = 0.0f;
	mMoveDirection.y = 0.0f;
	mMoveDirection.z = 0.0f;
}

void Camera::render(const GLdouble &alpha)
{
	mTransform->lerp(alpha);
	updateBasis();
	updateViewMatrix();
}

void Camera::updateBasis()
{
	mCameraForward = mLookDirection;
	mCameraRight = glm::normalize(glm::cross(mCameraForward, MatrixUtil::WORLD_UP));
	mCameraUp = glm::cross(mCameraRight, mCameraForward);
}


Transform* Camera::getTransform() const
{
	return mTransform;
}


glm::mat4 Camera::getViewMatrix() const
{
	return mViewMatrix;
}


const GLfloat* Camera::getViewMatrixPtr() const
{
	return glm::value_ptr(mViewMatrix);
}


glm::mat4 Camera::getProjectionMatrix()
{
	//if (GraphicsOptions::isPerspective)
	return perspectiveMatrix;
	//else
	//return orthoMatrix;
}


const GLfloat* Camera::getProjectionMatrixPtr()
{
	//if (GraphicsOptions::isPerspective)
	return glm::value_ptr(perspectiveMatrix);
	//else
	//return glm::value_ptr(orthoMatrix);
}