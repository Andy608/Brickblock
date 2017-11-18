#include <fstream>
#include "Shader.h"
#include "../../../util/filesystem/file/reader/StringFileReader.h"
#include "../../../util/filesystem/file/FileLocation.h"
#include "../../../util/logger/BBLogger.h"
using namespace bb;

const std::string Shader::CLASS_NAME = "Shader.cpp";
const GLint Shader::ERROR_LOG_SIZE = 512;

Shader::Shader(const EnumShaderType& SHADER_TYPE, FileLocation* shaderLocation) :
	mSHADER_TYPE(SHADER_TYPE), mShaderLocation(shaderLocation)
{

}

Shader::~Shader()
{
	if (mIsLoaded)
	{
		unload();
	}

	delete mShaderLocation;
}

void Shader::load()
{
	extractFromFile();
	compile();
	mIsLoaded = GL_TRUE;
	BBLogger::getLogger().logDebug(CLASS_NAME, mShaderCode, Logger::EnumLogLocation::CONSOLE_AND_FILE);
}

void Shader::unload()
{
	glDeleteShader(mShaderID);
	mIsLoaded = GL_FALSE;
}

void Shader::compile()
{
	if (mSHADER_TYPE == Shader::EnumShaderType::VERTEX)
	{
		mShaderID = glCreateShader(GL_VERTEX_SHADER);
	}
	else
	{
		mShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	}

	const GLchar *shaderCode = mShaderCode.c_str();
	GLint compiled;
	GLchar errorLog[ERROR_LOG_SIZE];

	glShaderSource(mShaderID, 1, &shaderCode, NULL);
	glCompileShader(mShaderID);
	glGetShaderiv(mShaderID, GL_COMPILE_STATUS, &compiled);

	if (!compiled)
	{
		glGetShaderInfoLog(mShaderID, ERROR_LOG_SIZE, NULL, errorLog);
		BBLogger::getLogger().logError(CLASS_NAME, "Could not compile shader: " + std::string(errorLog), Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}
	else
	{
		BBLogger::getLogger().logDebug(CLASS_NAME, "Successfully compiled shader!", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}
}

const Shader::EnumShaderType& Shader::getShaderType() const
{
	return mSHADER_TYPE;
}

const FileLocation& Shader::getShaderLocation() const
{
	return *mShaderLocation;
}

const GLint& Shader::getGLShaderID() const
{
	return mShaderID;
}

void Shader::extractFromFile()
{
	StringFileReader::getInstance().getContents(*mShaderLocation, mShaderCode);
}