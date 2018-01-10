#ifndef BB_MODELRENDERER_H_
#define BB_MODELRENDERER_H_

#include "Renderer.h"
#include <vector>

namespace bb
{
	class EntityModel;
	class ShaderProgram;
	class ModelRenderer : public Renderer
	{
	public:
		void render(const GLdouble& DELTA_TIME, const std::vector<EntityModel*>& MODEL_LIST);
	};
}

#endif