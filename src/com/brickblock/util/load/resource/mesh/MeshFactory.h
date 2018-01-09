#ifndef BB_MESHFACTORY_H_
#define BB_MESHFACTORY_H_

#include <string>
#include <glad/glad.h>
#include "../../../../util/filesystem/file/FileLocation.h"
#include "Mesh.h"

namespace bb
{
	class Mesh;
	struct MeshFactory
	{
		static void loadMeshDataFromFile(Mesh& mesh, const FileLocation &meshFileLocation);


	private:
		static const char SPACE_DELIMITER;
		static const char SLASH_DELIMITER;

		static const std::string VERTEX_DELIMITER;
		static const std::string VERTEX_TEX_COORD_DELIMITER;
		static const std::string VERTEX_NORMAL_DELIMITER;
		static const std::string FACE_DELIMITER;

		static const GLuint INDEX_DELIMITER_START;
		static const GLuint INDEX_DELIMITER_END;

		static void addFloatsFromString(std::string line, std::vector<GLfloat>& data, GLuint beginIndex, const char DELIMITER);
		static void getIntsFromString(std::string line, std::vector<GLint>& data, GLuint beginIndex, const char DELIMITER);
	};
}

#endif