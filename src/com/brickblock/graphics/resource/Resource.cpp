#include "Resource.h"
using namespace bb;

Resource::Resource() :
	mIsLoaded(GL_FALSE)
{
	
}

Resource::~Resource()
{

}

GLboolean Resource::isLoaded() const
{
	return mIsLoaded;
}