#include "ResourcePack.h"
#include "../../../../util/logger/BBLogger.h"
using namespace bb;

ResourcePack::ResourcePack(std::string resourceID) :
	Resource(resourceID, Resource::ResourceType::PACK),
	mResources(new std::vector<Resource*>)
{

}

ResourcePack::~ResourcePack()
{
	if (mResources != nullptr)
	{
		unload();
		mResources->clear();
		delete mResources;
	}
}

void ResourcePack::registerResource(Resource *resource)
{
	if (resource->isRegistered())
	{
		BBLogger::logWarn("ResourcePack.cpp", "Resource is already registered.");
	}
	else
	{
		//Add resource to pack.
		BBLogger::logDebug("ResourcePack.cpp", "Registering: " + resource->getID());
		mResources->push_back(resource);

		//Set the resource to be registered.
		resource->mIsRegistered = GL_TRUE;
	}
}

Resource& ResourcePack::getResource(std::string resourceID) const
{
	GLuint i;
	for (i = 0; i < mResources->size(); ++i)
	{
		Resource* resource = mResources->at(i);
		if (resource->mID == resourceID)
		{
			return *resource;
		}
	}

	throw std::invalid_argument("Resource not found: " + resourceID);
}

void ResourcePack::load()
{
	//This is the super class method.
	//Items get added to list in subclass,
	//and then this method is called.
	
	BBLogger::logTrace("ResourcePack.cpp", "SIZE: " + std::to_string(mResources->size()));

	GLuint i;
	for (i = 0; i < mResources->size(); ++i)
	{
		mResources->at(i)->load();
	}
}

void ResourcePack::unload()
{
	GLuint i;
	for (i = 0; i < mResources->size(); ++i)
	{
		mResources->at(i)->unload();
	}

	mResources->clear();
}