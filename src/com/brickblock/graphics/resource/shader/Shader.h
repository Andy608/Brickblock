#ifndef BB_SHADER_H_
#define BB_SHADER_H_

#include <string>
#include <glad/glad.h>
#include "../Resource.h"

namespace bb
{
	class FileLocation;
	class Shader : public Resource
	{
	public:

		enum class EnumShaderType : GLuint
		{
			VERTEX,
			FRAGMENT
		};

		Shader(const EnumShaderType& SHADER_TYPE, FileLocation* shaderLocation);
		~Shader();

		void load()   override;
		void unload() override;

		const EnumShaderType& getShaderType() const;
		const FileLocation& getShaderLocation() const;
		const GLint& getGLShaderID() const;

	private:
		static const std::string CLASS_NAME;
		static const GLint ERROR_LOG_SIZE;

		const EnumShaderType& mSHADER_TYPE;
		FileLocation* mShaderLocation;
		std::string mShaderCode;
		GLint mShaderID;

		void extractFromFile();
		void compile();
	};
}

#endif