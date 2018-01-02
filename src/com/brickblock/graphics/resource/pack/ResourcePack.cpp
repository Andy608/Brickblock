#include "ResourcePack.h"
#include "../../../util/logger/BBLogger.h"
using namespace bb;

ResourcePack::ResourcePack(ResourceManager::ResourceType packType) :
	Resource(packType),
	mResources(new std::vector<Resource*>())
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
		//Log resource is already registered in another pack.
	}
	else
	{
		//Add resource to pack.
		mResources->push_back(resource);
		
		//Set resource type to pack type.
		resource->mResourceType = mResourceType;
		
		//Set the resource to be registered.
		resource->mIsRegistered = GL_TRUE;
	}
}

void ResourcePack::load()
{
	//This is the super class method.
	//Items get added to list in subclass,
	//and then this method is called.
	GLuint i;
	for (i = 0; i < mResources->size(); ++i)
	{
		BBLogger::logTrace("ResourcePack.cpp", "SIZE: " + mResources->size());
		mResources->at(i)->load();
	}
}

void ResourcePack::unload()
{
	GLuint i;
	for (i = 0; i < mResources->size(); ++i)
	{
		Resource *resource = mResources->at(i);
		resource->unload();
		delete resource;
	}

	mResources->clear();
}