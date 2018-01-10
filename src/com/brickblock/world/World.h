#ifndef BB_WORLD_H_
#define BB_WORLD_H_

#include <glad/glad.h>
#include <vector>
#include <string>

namespace bb
{
	class EntityModel;
	class World
	{
	public:
		World(std::string worldName);
		~World();

		void update(const GLdouble& DELTA_TIME);
		void render(const GLdouble& DELTA_TIME);

	private:
		//Temporarily have model list. Should be entity list
		std::string mWorldName;
		std::vector<EntityModel*> *mModelList;
	};
}

#endif