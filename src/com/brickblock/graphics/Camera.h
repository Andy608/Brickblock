#ifndef BB_CAMERA_H_
#define BB_CAMERA_H_

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace bb
{
	class Transform;
	class Camera
	{
	public:
		Camera(glm::vec3 position);
		virtual ~Camera();

		void updateViewMatrix();
		static void updateProjectionMatrix(GLint viewportWidth, GLint viewportHeight);

		virtual void update(const GLdouble& DELTA_TIME);

		Transform* getTransform() const;

		glm::mat4 getViewMatrix() const;
		const GLfloat* getViewMatrixPtr() const;

		static glm::mat4 getProjectionMatrix();
		static const GLfloat* getProjectionMatrixPtr();

	protected:
		Transform* mTransform;

		glm::vec3 mCameraForward;
		glm::vec3 mCameraUp;
		glm::vec3 mCameraRight;

		glm::vec3 mLookDirection;

		void updateBasis();

	private:
		static const GLfloat NEAR_PLANE;
		static const GLfloat FAR_PLANE;
		static glm::mat4 perspectiveMatrix;
		static glm::mat4 orthoMatrix;

		glm::mat4 mViewMatrix;
	};
}

#endif