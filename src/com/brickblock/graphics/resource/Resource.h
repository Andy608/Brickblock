#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <glad\glad.h>
#include "../../core/load/ResourceManager.h"

namespace bb
{
	class Resource
	{
		friend class ResourcePack;

	public:
		Resource(ResourceManager::ResourceType packType = ResourceManager::ResourceType::UNKNOWN);
		virtual ~Resource();

		virtual void load() = 0;
		virtual void unload() = 0;

		GLboolean isLoaded() const;
		GLboolean isRegistered() const;

	protected:
		GLboolean mIsLoaded;
		GLboolean mIsRegistered;
		ResourceManager::ResourceType mResourceType;
	};
}

#endif