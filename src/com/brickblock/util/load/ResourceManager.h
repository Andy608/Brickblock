#ifndef BB_RESOURCEMANAGER_H_
#define BB_RESOURCEMANAGER_H_

#include <glad/glad.h>
#include <vector>
#include <string>

namespace bb
{
	class ResourcePack;
	class ResourceManager
	{
	friend class Brickblock;

	public:
		ResourceManager(ResourceManager const &copy) = delete;
		void operator=(ResourceManager const &copy) = delete;

		//Maybe
		//In the future it will take the screen type
		//and it will load the required resources needed for that
		//screen type. Example: world screen, it will load all meshes
		//title screen, it will load all fonts/music, etc
		void createResourcePacks();
		void registerResourcePacks();

		void loadResourcePacks();
		void unloadResourcePacks();

	private:
		static std::string CLASS_NAME;
		//Hold list of resourcepacks that need to be loaded
		std::vector<ResourcePack*> *mResourcePacks;

		ResourceManager();
		~ResourceManager();

		void registerResourcePack(ResourcePack *resourcePack);
	};
}

#endif