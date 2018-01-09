#include "World.h"
#include "../model/ModelTest.h"
#include "../render/RenderManager.h"
#include "../render/ModelRenderer.h"
#include "../util/load/resource/texture/TextureFactory.h"
#include "../util/load/resource/list/ShaderList.h"
#include "../util/load/resource/list/TextureList.h"
#include "../render/camera/Camera.h"
using namespace bb;

World::World(std::string worldName) :
	mWorldName(worldName),
	mModelList(new std::vector<Model*>())
{
	ModelTest *testModel = new ModelTest();
	TextureFactory::setTexture(*testModel, TextureList::getInstance().testTexture,
		TextureWrapper::WrapStyle::CLAMP_TO_EDGE, TextureWrapper::WrapStyle::CLAMP_TO_EDGE,
		TextureWrapper::MinFilter::LINEAR_MIPMAP_LINEAR, TextureWrapper::MagFilter::LINEAR);

	mModelList->push_back(testModel);
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

void World::update(const GLdouble& deltaTime)
{
	GLuint i;
	for (i = 0; i < mModelList->size(); ++i)
	{
		mModelList->at(i)->update(deltaTime);
	}

	RenderManager::getInstance().getCamera().update(deltaTime);
}

void World::render(const GLdouble& alpha)
{
	RenderManager::getInstance().setShaderProgram(ShaderList::getInstance().meshShaderProgram);
	RenderManager::getInstance().getModelRenderer().render(alpha, *mModelList);
}
