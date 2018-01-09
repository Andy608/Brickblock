#include "ResourceManager.h"
#include "resource/pack/ResourcePack.h"
#include "resource/pack/MeshResourcePack.h"
#include "resource/pack/ShaderResourcePack.h"
#include "resource/pack/TextureResourcePack.h"
#include "resource/pack/FileLocResourcePack.h"
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

		GLuint i = 0;
		for (i = 0; i < mResourcePacks->size(); ++i)
		{
			delete mResourcePacks->at(i);
		}

		mResourcePacks->clear();
		delete mResourcePacks;
	}
}

void ResourceManager::createResourcePacks()
{
	FileLocResourcePack::init();
	MeshResourcePack::init();
	ShaderResourcePack::init();
	TextureResourcePack::init();
}

void ResourceManager::registerResourcePacks()
{
	registerResourcePack(FileLocResourcePack::instance);
	registerResourcePack(MeshResourcePack::instance);
	registerResourcePack(ShaderResourcePack::instance);
	registerResourcePack(TextureResourcePack::instance);
}

void ResourceManager::registerResourcePack(ResourcePack *resourcePack)
{
	if (resourcePack->isRegistered())
	{
		BBLogger::logWarn(CLASS_NAME, "Resource pack: " + resourcePack->getID() + " is already registed.");
		return;
	}

	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		if (resourcePack->mID == mResourcePacks->at(i)->mID)
		{
			BBLogger::logWarn(CLASS_NAME, "Resource pack: " + resourcePack->getID() + " is already registed.");
			return;
		}
	}

	mResourcePacks->push_back(resourcePack);
	resourcePack->mIsRegistered = GL_TRUE;
	BBLogger::logTrace(CLASS_NAME, "Successfully registered resource pack: " + resourcePack->getID());
}

void ResourceManager::loadResourcePacks()
{
	GLuint i;
	for (i = 0; i < mResourcePacks->size(); ++i)
	{
		mResourcePacks->at(i)->load();
		BBLogger::logTrace(CLASS_NAME, "Loaded resource pack: " + mResourcePacks->at(i)->mID);
	}
}

void ResourceManager::unloadResourcePacks()
{
	GLint i;
	for (i = mResourcePacks->size() - 1; i >= 0; --i)
	{
		mResourcePacks->at(i)->unload();
		BBLogger::logTrace(CLASS_NAME, "Unloaded resource pack: " + mResourcePacks->at(i)->mID);
	}
}