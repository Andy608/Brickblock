#ifndef BB_SHADER_H_
#define BB_SHADER_H_

#include <string>
#include <glad/glad.h>
#include "../Resource.h"
#include "../../../../util/filesystem/file/FileLocation.h"

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

		Shader(std::string resourceID, const EnumShaderType& SHADER_TYPE, const FileLocation& shaderLocation);
		~Shader();

		const Shader& operator=(const Shader& another);

		void load()   override;
		void unload() override;

		const EnumShaderType& getShaderType() const;
		const FileLocation& getShaderLocation() const;
		const GLint& getGLShaderID() const;

	private:
		static const std::string CLASS_NAME;
		static const GLint ERROR_LOG_SIZE;

		const EnumShaderType& mSHADER_TYPE;
		const FileLocation& mShaderLocation;
		std::string mShaderCode;
		GLint mShaderID;

		void extractFromFile();
		void compile();
	};
}

#endif