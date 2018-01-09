#include "Resource.h"
using namespace bb;

Resource::Resource(std::string resourceID, const ResourceType &packType) :
	mID(resourceID),
	mIsLoaded(GL_FALSE),
	mIsRegistered(GL_FALSE),
	mResourceType(packType)
{
	
}

Resource::~Resource()
{

}

const std::string& Resource::getID() const
{
	return mID;
}

GLboolean Resource::isLoaded() const
{
	return mIsLoaded;
}

GLboolean Resource::isRegistered() const
{
	return mIsRegistered;
}

const Resource::ResourceType& Resource::getType() const
{
	return mResourceType;
}