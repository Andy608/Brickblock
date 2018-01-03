#include "ModelRenderer.h"
#include "../resource/shader/ShaderProgram.h"
#include "../model/Model.h"
#include "RenderManager.h"
#include "../../graphics/Camera.h"
#include <glm/gtc/type_ptr.hpp>
#include "../../util/logger/BBLogger.h"
#include <GLFW/glfw3.h>
using namespace bb;

void ModelRenderer::render(const GLdouble& DELTA_TIME, const std::vector<Model*>& MODEL_LIST)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);
	const ShaderProgram &shaderProgram = RenderManager::getInstance().getActiveShader();
	shaderProgram.use();

	const Camera &camera = RenderManager::getInstance().getCamera();
	shaderProgram.loadMat4("viewMatrix", GL_FALSE, camera.getViewMatrixPtr());
	shaderProgram.loadMat4("projectionMatrix", GL_FALSE, camera.getProjectionMatrixPtr());
	shaderProgram.loadMat4("transformMatrix", GL_FALSE, glm::value_ptr(glm::mat4x4()));
	shaderProgram.loadFloat("time", glfwGetTime());

	for (GLuint i = 0; i < MODEL_LIST.size(); ++i)
	{
		//BBLogger::logDebug("ModelRenderer.cpp", "RENDERERING MODEL: " + std::to_string(i));
		MODEL_LIST.at(i)->render(DELTA_TIME);
	}

	glDisable(GL_DEPTH_TEST);
}
