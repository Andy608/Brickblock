#include "ShaderProgram.h"
#include "Shader.h"
#include "../../../util/logger/BBLogger.h"
using namespace bb;

const std::string ShaderProgram::CLASS_NAME = "ShaderProgram.cpp";
const GLint ShaderProgram::ERROR_LOG_SIZE = 512;

ShaderProgram::ShaderProgram() :
	mActiveShaders(std::vector<Shader*>()),
	mProgramID(0)
{

}

ShaderProgram::~ShaderProgram()
{
	BBLogger::logInfo(CLASS_NAME, "Deleting Shader Program...", Logger::EnumLogLocation::CONSOLE_AND_FILE);

	if (mIsLoaded)
	{
		unload();
	}
}

void ShaderProgram::load()
{
	compile();
	mIsLoaded = GL_TRUE;
}

void ShaderProgram::unload()
{
	glDeleteProgram(mProgramID);
	mActiveShaders.clear();
}

void ShaderProgram::use() const
{
	glUseProgram(mProgramID);
}

void ShaderProgram::addShader(Shader* shader)
{
	mActiveShaders.push_back(shader);
}

const GLint& ShaderProgram::getProgramID() const
{
	return mProgramID;
}

GLuint ShaderProgram::getUniformID(std::string uniformName) const
{
	return glGetUniformLocation(mProgramID, uniformName.c_str());
}

void ShaderProgram::loadInt(std::string uniformName, GLint integer) const
{
	glUniform1i(getUniformID(uniformName), integer);
}

void ShaderProgram::loadFloat(std::string uniformName, GLfloat floatingPoint) const
{
	glUniform1f(getUniformID(uniformName), floatingPoint);
}

void ShaderProgram::loadMat4(std::string uniformName, GLboolean transposeMatrix, const GLfloat* matrixPtr) const
{
	glUniformMatrix4fv(getUniformID(uniformName), 1, transposeMatrix, matrixPtr);
}

void ShaderProgram::compile()
{
	if (mIsLoaded)
	{
		return;
	}

	mProgramID = glCreateProgram();

	for (GLuint i = 0; i < mActiveShaders.size(); ++i)
	{
		BBLogger::logInfo(CLASS_NAME, "Attaching shader: " + mActiveShaders.at(i)->getShaderLocation().getNameAndExt(), Logger::EnumLogLocation::CONSOLE_AND_FILE);
		glAttachShader(mProgramID, mActiveShaders.at(i)->getGLShaderID());
	}

	glLinkProgram(mProgramID);

	GLint compiled;
	GLchar errorLog[ERROR_LOG_SIZE];

	glGetProgramiv(mProgramID, GL_LINK_STATUS, &compiled);

	if (!compiled)
	{
		glGetProgramInfoLog(mProgramID, ERROR_LOG_SIZE, NULL, errorLog);
	}
	else
	{
		BBLogger::logInfo(CLASS_NAME, "Successfully compiled shader program: " + mProgramID, Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}
}
