#include "Camera.h"
#include "../util/math/physics/Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../util/logger/BBLogger.h"
#include "../util/math/MatrixUtil.h"
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
	mTransform->setRotation(
		mTransform->getRotation().x /*+ 0.01f*/,
		mTransform->getRotation().y,
		mTransform->getRotation().z);
	
	mLookDirection = glm::vec3(0.0, 0.0, -1.0);
	MatrixUtil::rotateAboutXAxis(mLookDirection, mTransform->getRotation().x);
	MatrixUtil::rotateAboutYAxis(mLookDirection, mTransform->getRotation().y);
	MatrixUtil::rotateAboutZAxis(mLookDirection, mTransform->getRotation().z);

	/*BBLogger::logDebug("Camera.cpp",
		std::to_string(mLookDirection.x) + ", " +
		std::to_string(mLookDirection.y) + ", " +
		std::to_string(mLookDirection.z)
	);*/

	mViewMatrix = glm::lookAt(mTransform->getPosition(), mTransform->getPosition() + mLookDirection, mCameraUp);
}

void Camera::updateProjectionMatrix(GLint viewportWidth, GLint viewportHeight)
{
	BBLogger::logDebug("Camera.cpp", std::to_string(viewportWidth) + ", " + std::to_string(viewportHeight));

	//if (GraphicsOptions::isPerspective)
	perspectiveMatrix = glm::perspective(
		glm::radians(67.0f),
		static_cast<GLfloat>(viewportWidth) / static_cast<GLfloat>(viewportHeight),
		NEAR_PLANE,
		FAR_PLANE);
	//else
	orthoMatrix = glm::ortho(
		-static_cast<GLfloat>(viewportWidth) / 2.0f,
		static_cast<GLfloat>(viewportWidth) / 2.0f,
		-static_cast<GLfloat>(viewportHeight) / 2.0f,
		static_cast<GLfloat>(viewportHeight) / 2.0f,
		NEAR_PLANE, FAR_PLANE);
}


void Camera::update(const GLdouble& DELTA_TIME)
{
	/*if (InputTracker::instance->getCameraForwardKey().isPressed())
	{
		logger.log(Logger::Level::LEVEL_DEBUG, std::to_string(mTransform->getPosition().x) + ", " +
			std::to_string(mTransform->getPosition().y) + ", " +
			std::to_string(mTransform->getPosition().z));
		mTransform->setPosition(mTransform->getPosition().x, mTransform->getPosition().y, mTransform->getPosition().z - 1);
	}

	if (InputTracker::instance->getCameraBackwardKey().isPressed())
	{
		logger.log(Logger::Level::LEVEL_DEBUG, std::to_string(mTransform->getPosition().x) + ", " +
			std::to_string(mTransform->getPosition().y) + ", " +
			std::to_string(mTransform->getPosition().z));
		mTransform->setPosition(mTransform->getPosition().x, mTransform->getPosition().y, mTransform->getPosition().z + 1);
	}*/

	updateBasis();
	updateViewMatrix();
}

void Camera::updateBasis()
{
	mCameraForward = glm::normalize(mLookDirection);
	mCameraRight = glm::normalize(glm::cross(mCameraForward, Transform::WORLD_UP));
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