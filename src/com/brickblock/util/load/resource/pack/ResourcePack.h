#ifndef BB_RESOURCEPACK_H_
#define BB_RESOURCEPACK_H_

#include "../Resource.h"
#include "../../ResourceManager.h"
#include <unordered_map>
#include <string>

namespace bb
{
	class ResourcePack : public Resource
	{
		friend class ResourceManager;

	public:
		virtual ~ResourcePack();

		virtual Resource& getResource(std::string resourceID) const;

	protected:
		ResourcePack(std::string resourceID);
		virtual void registerResource(Resource *resource);
		virtual void load();	//Loads/Creates the objects in the pack
		virtual void unload();	//Unloads/Deletes the objects in the pack

		std::vector<Resource*> *mResources;
	};
}

#endif