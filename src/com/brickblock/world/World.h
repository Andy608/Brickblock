#ifndef BB_WORLD_H_
#define BB_WORLD_H_

#include <glad/glad.h>
#include <vector>
#include <string>

namespace bb
{
	class Zone;
	class EntityModel;
	class World
	{
	public:
		World(std::string worldName);
		~World();

		void update(const GLdouble& deltaTime);
		void render(const GLdouble& alpha);

	private:
		std::string mWorldName;

		//Temporarily have model list. Should be entity list
		std::vector<EntityModel*> *mModelList;
	
		//Temporarily have 1 zone to test out brick model generation.
		Zone *mZone;
	};
}

#endif