#ifndef BB_TRANSFORM_H_
#define BB_TRANSFORM_H_

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glad/glad.h>

namespace bb
{
	class Transform
	{
	public:
		glm::vec3 mPosition;
		glm::vec3 mRotation;
		glm::vec3 mScale;

		glm::vec3 mPrevPosition;
		glm::vec3 mPrevRotation;
		glm::vec3 mPrevScale;

		Transform(glm::vec3 position = glm::vec3(), glm::vec3 rotation = glm::vec3(), glm::vec3 scale = glm::vec3(1.0f));
		~Transform();

		void setPosition(GLfloat x, GLfloat y, GLfloat z);
		void setRotation(GLfloat x, GLfloat y, GLfloat z);
		void setScale(GLfloat x, GLfloat y, GLfloat z);
		void setPivot(GLfloat x, GLfloat y, GLfloat z);

		void addPosition(GLfloat x, GLfloat y, GLfloat z);
		void addPosition(const glm::vec3& ANOTHER);

		void addRotation(GLfloat x, GLfloat y, GLfloat z);
		void addRotation(const glm::vec3& ANOTHER);

		void addScale(GLfloat x, GLfloat y, GLfloat z);
		void addScale(const glm::vec3& ANOTHER);

		void lerp(const GLdouble &alpha);
		void update();

		const glm::vec3& getPosition() const;
		const glm::vec3& getRotation() const;
		const glm::vec3& getScale() const;
		const glm::vec3& getPivot() const;

		const glm::mat4x4& getTransformationMat() const;

	private:
		glm::mat4x4 mTransformationMatrix;

		void updateTransformationMatrix(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale);

		//The point the object should rotate around in local space.
		glm::vec3 mPivot;
	};
}

#endif