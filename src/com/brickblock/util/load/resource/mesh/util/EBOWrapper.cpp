#include "EBOWrapper.h"

namespace bb
{
	EBOWrapper::EBOWrapper(std::vector<GLint> indices) :
		mIndiceList(indices)
	{
		createID();
	}

	EBOWrapper::~EBOWrapper()
	{
		glDeleteBuffers(SIZE, &mID);
		mIndiceList.clear();
	}

	void EBOWrapper::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLint) * mIndiceList.size(), &mIndiceList[0], GL_STATIC_DRAW);
	}

	void EBOWrapper::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	const GLuint EBOWrapper::getIndiceCount() const
	{
		return mIndiceList.size();
	}

	const std::vector<GLint> EBOWrapper::getIndices() const
	{
		return mIndiceList;
	}

	void EBOWrapper::createID()
	{
		glGenBuffers(SIZE, &mID);
	}
}