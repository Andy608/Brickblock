#ifndef BB_VERTEX_H_
#define BB_VERTEX_H_

#include <vector>
#include <glad/glad.h>

namespace bb
{
	/*struct Vertex
	{
		Vertex(glm::vec3 pos, glm::vec2 tex, glm::vec3 norm);
		glm::vec3 mPosition;
		glm::vec2 mTexture;
		glm::vec3 mNormal;
	};*/

	struct Vertex
	{
		Vertex(GLuint pos, GLuint tex, GLuint norm);
		GLuint mPositionIndex;
		GLuint mTextureIndex;
		GLuint mNormalIndex;

		GLboolean operator==(const Vertex& another);
	};
}

#endif