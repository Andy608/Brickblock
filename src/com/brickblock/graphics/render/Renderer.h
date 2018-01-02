#ifndef BB_RENDERER_H_
#define BB_RENDERER_H_

#include "../resource/shader/ShaderProgram.h"

namespace bb
{
	class Renderer
	{
	public:
		Renderer(ShaderProgram& shaderProgram);
		virtual ~Renderer();

		virtual void render() = 0;

	protected:
		ShaderProgram &mShaderProgram;
	};
}

#endif