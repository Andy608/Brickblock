#ifndef BB_RESOURCEPACK_H_
#define BB_RESOURCEPACK_H_

#include "../Resource.h"
#include "../../../core/load/ResourceManager.h"
#include <vector>

namespace bb
{
	class ResourcePack : public Resource
	{
		friend class ResourceManager;

	public:
		ResourcePack(ResourceManager::ResourceType packType);
		virtual ~ResourcePack();

	protected:
		void registerResource(Resource *resource);
		virtual void load();	//Loads/Creates the objects in the pack
		virtual void unload();	//Unloads/Deletes the objects in the pack

	private:
		ResourceManager::ResourceType mPackType;
		std::vector<Resource*> *mResources;
	};
}

#endif