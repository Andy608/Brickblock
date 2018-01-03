#include "ResourceManager.h"
#include "../../graphics/resource/pack/ResourcePack.h"
#include "../../graphics/resource/pack/MeshResourcePack.h"
#include "../../graphics/resource/pack/ShaderResourcePack.h"
#include "../../util/logger/BBLogger.h"
using namespace bb;

std::string ResourceManager::CLASS_NAME = "ResourceManager.cpp";

ResourceManager::ResourceManager() :
	mResourcePacks(new std::vector<ResourcePack*>())
{

}

ResourceManager::~ResourceManager()
{
	if (mResourcePacks != nullptr)
	{
		unloadResourcePacks();

		GLuint i;
		for (i = 0; i < mResourcePacks->size(); ++i)
		{
			delete mResourcePacks->at(i);
		}

		mResourcePacks->clear();
		delete mResourcePacks;
	}
}

void ResourceManager::registerResourcePacks()
{
	registerResourcePack(new MeshResourcePack());
	registerResourcePack(new ShaderResourcePack());
}

void ResourceManager::registerResourcePack(ResourcePack *resourcePack)
{
	if (resourcePack->isRegistered())
	{
		BBLogger::logWarn(CLASS_NAME, "Resource pack: (ID GOES HERE) is already registed.");
		return;
	}

	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		if (resourcePack->mPackType == mResourcePacks->at(i)->mPackType)
		{
			BBLogger::logWarn(CLASS_NAME, "Resource pack: (ID GOES HERE) is already registed.");
			return;
		}
	}

	mResourcePacks->push_back(resourcePack);
	resourcePack->mIsRegistered = GL_TRUE;
	BBLogger::logTrace(CLASS_NAME, "Successfully registered resource pack: (ID GOES HERE).");
}

void ResourceManager::loadResourcePack(ResourceType type)
{
	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		ResourcePack *pack = mResourcePacks->at(i);
		if (pack->mPackType == type && !pack->mIsLoaded)
		{
			pack->load();
			BBLogger::logTrace(CLASS_NAME, "Loaded resource pack: (ID GOES HERE).");
			return;
		}
	}
}

void ResourceManager::unloadResourcePack(ResourceType type)
{
	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		ResourcePack *pack = mResourcePacks->at(i);
		if (pack->mPackType == type && pack->mIsLoaded)
		{
			pack->unload();
			BBLogger::logTrace(CLASS_NAME, "Unloaded resource pack: (ID GOES HERE).");
			return;
		}
	}
}

void ResourceManager::loadResourcePacks()
{
	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		mResourcePacks->at(i)->load();
	}
}

void ResourceManager::unloadResourcePacks()
{
	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		mResourcePacks->at(i)->unload();
	}
}