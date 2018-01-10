#include "ModelRenderer.h"
#include "../util/load/resource/shader/ShaderProgram.h"
#include "../util/load/resource/mesh/util/TextureWrapper.h"
#include "../model/entity/EntityModel.h"
#include "RenderManager.h"
#include "camera/Camera.h"
#include "../util/logger/BBLogger.h"
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
using namespace bb;

void ModelRenderer::render(const GLdouble& alpha, const std::vector<EntityModel*>& MODEL_LIST)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);
	const ShaderProgram &shaderProgram = RenderManager::getInstance().getActiveShader();
	shaderProgram.use();

	const Camera &camera = RenderManager::getInstance().getCamera();
	shaderProgram.loadMat4("viewMatrix", GL_FALSE, camera.getViewMatrixPtr());
	shaderProgram.loadMat4("projectionMatrix", GL_FALSE, camera.getProjectionMatrixPtr());
	//shaderProgram.loadMat4("transformMatrix", GL_FALSE, glm::value_ptr(glm::mat4x4()));
	shaderProgram.loadFloat("time", static_cast<GLfloat>(glfwGetTime()));

	for (GLuint i = 0; i < MODEL_LIST.size(); ++i)
	{
		if (MODEL_LIST.at(i)->getTextureWrapper() != nullptr)
		{
			glActiveTexture(GL_TEXTURE0);
			MODEL_LIST.at(i)->getTextureWrapper()->bind();
			//BBLogger::logDebug("ModelRenderer.cpp", "RENDERERING MODEL: " + std::to_string(i));
			MODEL_LIST.at(i)->render(alpha, shaderProgram);
			MODEL_LIST.at(i)->getTextureWrapper()->unbind();
		}
		else
		{
			MODEL_LIST.at(i)->render(alpha, shaderProgram);
		}
	}

	glDisable(GL_DEPTH_TEST);
}
