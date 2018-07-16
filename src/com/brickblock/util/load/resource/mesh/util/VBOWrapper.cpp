#include "VBOWrapper.h"
using namespace bb;

VBOWrapper::VBOWrapper(const BufferType& BUFFER_TYPE, std::vector<GLfloat> buffer, GLuint elementsPerVertex) :
	GLObjectWrapper(), 
	mBUFFER_TYPE(BUFFER_TYPE), 
	mBufferData(buffer), 
	mElementsPerVertex(elementsPerVertex),
	mVertexCount(mBufferData.size() / elementsPerVertex)
{
	createID();
}

VBOWrapper::~VBOWrapper()
{
	glDeleteBuffers(SIZE, &mID);
	mBufferData.clear();
}

void VBOWrapper::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, mID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mBufferData.size(), &mBufferData[0], GL_STATIC_DRAW);
}

void VBOWrapper::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const GLuint& VBOWrapper::getElementsPerVertex() const
{
	return mElementsPerVertex;
}

const GLuint& VBOWrapper::getVertexCount() const
{
	return mVertexCount;
}

const std::vector<GLfloat>& VBOWrapper::getBufferData() const
{
	return mBufferData;
}

void VBOWrapper::createID()
{
	glGenBuffers(SIZE, &mID);
}