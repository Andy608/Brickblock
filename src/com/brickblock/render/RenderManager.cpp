#include "RenderManager.h"
#include <glm/vec3.hpp>
#include "../render/camera/Camera.h"
#include "ModelRenderer.h"
#include "../util/load/resource/shader/ShaderProgram.h"
using namespace bb;

RenderManager::RenderManager() :
	mCamera(new Camera(glm::vec3(0.0f, 1.5f, 3.0f))),
	mModelRenderer(new ModelRenderer()),
	mACTIVE_SP(nullptr)
{
	//mCamera->getTransform()->addPosition(0.0f, 0.0f, 10.0f);
	//mCamera->getTransform()->setRotation(-0.2, 0.0, 0.0);
}

RenderManager::~RenderManager()
{
	delete mCamera;
	delete mModelRenderer;
}

ModelRenderer& RenderManager::getModelRenderer() const
{
	return *mModelRenderer;
}

Camera& RenderManager::getCamera() const
{
	return *mCamera;
}