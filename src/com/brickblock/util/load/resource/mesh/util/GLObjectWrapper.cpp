#include "GLObjectWrapper.h"
using namespace bb;

const GLuint GLObjectWrapper::SIZE = 1;

GLObjectWrapper::GLObjectWrapper()
{

}

GLObjectWrapper::~GLObjectWrapper()
{

}

const GLuint& GLObjectWrapper::getID() const
{
	return mID;
}