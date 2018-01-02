#include "VAOWrapper.h"
#include "VBOWrapper.h"
using namespace bb;

VAOWrapper::VAOWrapper()
{
	createID();
}

VAOWrapper::~VAOWrapper()
{
	glDeleteVertexArrays(SIZE, &mID);
}

void VAOWrapper::bind() const
{
	glBindVertexArray(mID);
}

void VAOWrapper::unbind() const
{
	glBindVertexArray(0);
}

void VAOWrapper::bindVBOToVAO(GLuint bufferIndex, VBOWrapper &bufferData)
{
	glVertexAttribPointer(bufferIndex, bufferData.getElementsPerVertex(), GL_FLOAT, GL_FALSE, sizeof(GLfloat) * bufferData.getElementsPerVertex(), (GLvoid*)0);
	glEnableVertexAttribArray(bufferIndex);
}

void VAOWrapper::createID()
{
	glGenVertexArrays(SIZE, &mID);
}