#ifndef BB_TRANSFORM_H_
#define BB_TRANSFORM_H_

#include <glm\vec3.hpp>
#include <glad\glad.h>

namespace bb
{
	class Transform
	{
	public:
		//right handed system
		static glm::vec3 WORLD_UP;
		static glm::vec3 WORLD_RIGHT;
		static glm::vec3 WORLD_FORWARD;

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

		const glm::vec3& getPosition() const;
		const glm::vec3& getRotation() const;
		const glm::vec3& getScale() const;
		const glm::vec3& getPivot() const;

	private:
		glm::vec3 mPosition;
		glm::vec3 mRotation;
		glm::vec3 mScale;

		//The point the object should rotate around in local space.
		glm::vec3 mPivot;
	};
}

#endif