#include "RenderManager.h"
#include <glm/vec3.hpp>
#include "../../graphics/Camera.h"
#include "ModelRenderer.h"
#include "../resource/shader/ShaderProgram.h"
using namespace bb;

//GLint RenderManager::renderScreenWidth;
//GLint RenderManager::renderScreenHeight;

/*void RenderManager::updateRenderScreenSize(GLint width, GLint height)
{
	renderScreenWidth = width;
	renderScreenHeight = height;
	Camera::updateProjectionMatrix(renderScreenWidth, renderScreenHeight);
}*/


RenderManager::RenderManager() :
	mCamera(new Camera(glm::vec3(0.0f, 0.0f, 3.0f))),
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