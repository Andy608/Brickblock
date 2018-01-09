#ifndef BB_SHADERPROGRAM_H_
#define BB_SHADERPROGRAM_H_

#include "../Resource.h"
#include <string>
#include <vector>

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
		void loadMat4(std::string uniformName, GLboolean transposeMatrix, const GLfloat* matrixPtr) const;

	private:
		static const std::string CLASS_NAME;
		static const GLint ERROR_LOG_SIZE;

		GLint mProgramID;
		std::vector<Shader*> mActiveShaders;

		void compile();
	};
}

#endif 