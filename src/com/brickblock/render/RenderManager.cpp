#include "RenderManager.h"
#include <glm/vec3.hpp>
#include "../render/camera/Camera.h"
#include "ModelRenderer.h"
#include "../util/load/resource/shader/ShaderProgram.h"
using namespace bb;

RenderManager::RenderManager() :
	mCamera(new Camera(glm::vec3(0.0f, 1.0f, 10.0f))),
	mModelRenderer(new ModelRenderer()),
	mACTIVE_SP(nullptr)
{

}

RenderManager::~RenderManager()
{
	delete mCamera;
	delete mModelRenderer;
}

void RenderManager::setShaderProgram(const ShaderProgram& shader)
{
	mACTIVE_SP = &shader;
}

const ShaderProgram& RenderManager::getActiveShader() const
{
	return *mACTIVE_SP;
}

ModelRenderer& RenderManager::getModelRenderer() const
{
	return *mModelRenderer;
}

Camera& RenderManager::getCamera() const
{
	return *mCamera;
}