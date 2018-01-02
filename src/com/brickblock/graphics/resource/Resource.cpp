#include "Resource.h"
using namespace bb;

Resource::Resource(ResourceManager::ResourceType packType) :
	mIsLoaded(GL_FALSE),
	mIsRegistered(GL_FALSE),
	mResourceType(packType)
{
	
}

Resource::~Resource()
{

}

GLboolean Resource::isLoaded() const
{
	return mIsLoaded;
}

GLboolean Resource::isRegistered() const
{
	return mIsRegistered;
}