#ifndef BB_RENDERMANAGER_H_
#define BB_RENDERMANAGER_H_

#include <glad/glad.h>
#include "camera/Camera.h"

namespace bb
{
	class ShaderProgram;
	class ModelRenderer;

	class RenderManager
	{
	public:
		enum class ShaderProgramType
		{
			GUI_SHADER
		};

		static RenderManager& getInstance()
		{
			static RenderManager instance;
			return instance;
		}

		RenderManager(RenderManager const &copy) = delete;
		void operator=(RenderManager const &copy) = delete;

		//static void updateRenderScreenSize(GLuint width, GLuint height);

		void setShaderProgram(const ShaderProgram& shader);

		const ShaderProgram& getActiveShader() const;
		
		ModelRenderer& getModelRenderer() const;
		Camera& getCamera() const;

	private:
		//static GLint renderScreenWidth;
		//static GLint renderScreenHeight;

		Camera *mCamera;

		const ShaderProgram *mACTIVE_SP;
		ModelRenderer *mModelRenderer;

		RenderManager();
		~RenderManager();
	};
}

#endif