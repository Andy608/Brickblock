#ifndef BB_RESOURCEMANAGER_H_
#define BB_RESOURCEMANAGER_H_

#include <glad/glad.h>
#include <vector>

namespace bb
{
	class ResourcePack;
	class ResourceManager
	{
	friend class Brickblock;

	public:
		enum class ResourceType : GLuint
		{
			UNKNOWN = 0,
			MESH = 1,
			SHADER = 2
		};

		ResourceManager(ResourceManager const &copy) = delete;
		void operator=(ResourceManager const &copy) = delete;

		//In the future it will take the screen type
		//and it will load the required resources needed for that
		//screen type. Example: world screen, it will load all meshes
		//title screen, it will load all fonts/music, etc
		void registerResourcePacks();
		void loadResourcePacks();
		void unloadResourcePacks();

	private:
		static std::string CLASS_NAME;
		//Hold list of resourcepacks that need to be loaded
		std::vector<ResourcePack*> *mResourcePacks;

		ResourceManager();
		~ResourceManager();

		//RESOURCES ARE NOT MEANT TO BE USED AS REFEFENCES IN GAME
		//THEY ARE FOR MEMORY MANAGEMENT
		void registerResourcePack(ResourcePack *resourcePack);

		void loadResourcePack(ResourceType type);
		void unloadResourcePack(ResourceType type);
	};
}

#endif