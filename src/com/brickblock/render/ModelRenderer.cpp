#include "ModelRenderer.h"
#include "../util/load/resource/shader/ShaderProgram.h"
#include "../util/load/resource/mesh/util/TextureWrapper.h"
#include "../model/entity/EntityModel.h"
#include "RenderManager.h"
#include "camera/Camera.h"
#include "../util/logger/BBLogger.h"
#include <glm/gtc/type_ptr.hpp>
using namespace bb;

void ModelRenderer::render(const GLdouble& alpha, const std::vector<EntityModel*>& MODEL_LIST)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);

	for (GLuint i = 0; i < MODEL_LIST.size(); ++i)
	{
			glActiveTexture(GL_TEXTURE0);
			MODEL_LIST.at(i)->getTextureWrapper()->bind();
			//BBLogger::logDebug("ModelRenderer.cpp", "RENDERERING MODEL: " + std::to_string(i));
			MODEL_LIST.at(i)->render(alpha);
			MODEL_LIST.at(i)->getTextureWrapper()->unbind();
	}

	glDisable(GL_DEPTH_TEST);
}
