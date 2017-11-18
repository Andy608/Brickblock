#include "Resource.h"
using namespace bb;

Resource::Resource()
{

}

Resource::~Resource()
{

}

GLboolean Resource::isLoaded() const
{
	return mIsLoaded;
}