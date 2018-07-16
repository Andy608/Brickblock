#ifndef BB_SHADERPROGRAM_H_
#define BB_SHADERPROGRAM_H_

#include "../Resource.h"
#include <string>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

namespace bb
{
	class Shader;
	class ShaderProgram : public Resource
	{
	public:
		ShaderProgram(std::string resourceID);
		~ShaderProgram();

		const ShaderProgram& operator=(const ShaderProgram& another);
		
		void load() override;
		void unload() override;

		void use() const;
		void addShader(Shader* shader);
		const GLint& getProgramID() const;

		GLuint getUniformID(std::string uniformName) const;

		void loadInt(std::string uniformName, GLint integer) const;
		void loadFloat(std::string uniformName, GLfloat floatingPoint) const;
		void loadVec3(std::string uniformName, const glm::vec3 &vec3) const;

		void loadMat3(std::string uniformName, GLboolean transposeMatrix, const glm::mat3x3& mat3) const;
		void loadMat4(std::string uniformName, GLboolean transposeMatrix, const glm::mat4x4& mat4) const;

	private:
		static const std::string CLASS_NAME;
		static const GLint ERROR_LOG_SIZE;

		GLint mProgramID;
		std::vector<Shader*> mActiveShaders;

		void compile();
	};
}

#endif 