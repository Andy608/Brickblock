#include "World.h"
#include "../graphics/model/ModelTest.h"
#include "../graphics/render/RenderManager.h"
#include "../graphics/render/ModelRenderer.h"
#include "../graphics/resource/pack/ShaderResourcePack.h"
#include "../graphics/Camera.h"
using namespace bb;

World::World(std::string worldName) :
	mWorldName(worldName),
	mModelList(new std::vector<Model*>())
{
	mModelList->push_back(new ModelTest());
}

World::~World()
{
	GLuint i;
	for (i = 0; i < mModelList->size(); ++i)
	{
		delete mModelList->at(i);
	}

	delete mModelList;
}

void World::update(const GLdouble& DELTA_TIME)
{
	GLuint i;
	for (i = 0; i < mModelList->size(); ++i)
	{
		mModelList->at(i)->update(DELTA_TIME);
	}

	RenderManager::getInstance().getCamera().update(DELTA_TIME);
}

void World::render(const GLdouble& DELTA_TIME)
{
	RenderManager::getInstance().setShaderProgram(ShaderResourcePack::getTestModelProgram());
	RenderManager::getInstance().getModelRenderer().render(DELTA_TIME, *mModelList);
}
