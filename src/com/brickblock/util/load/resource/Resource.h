#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <glad/glad.h>
#include <string>
#include "../ResourceManager.h"

namespace bb
{
	class Resource
	{
		friend class ResourcePack;

	public:
		enum class ResourceType : GLuint
		{
			UNKNOWN = 0,
			PACK = 1,
			FILE_LOCATION = 2,
			MESH = 3,
			SHADER = 4,
			TEXTURE = 5,
			BRICK = 6
		};

		Resource(std::string resourceID, const ResourceType &resourceType);
		virtual ~Resource();

		virtual void load() = 0;
		virtual void unload() = 0;

		const std::string& getID() const;
		GLboolean isLoaded() const;
		GLboolean isRegistered() const;
		const ResourceType& getType() const;

	protected:
		std::string mID;
		GLboolean mIsLoaded;
		GLboolean mIsRegistered;
		const ResourceType &mResourceType;
	};
}

#endif