#ifndef BB_SHADERLIST_H_
#define BB_SHADERLIST_H_

namespace bb
{
	class ShaderProgram;
	struct ShaderList
	{
	public:
		friend class ShaderResourcePack;

		static void init();
		static const ShaderList& getInstance();

		ShaderProgram &meshShaderProgram;

	private:
		static ShaderList *instance;
		ShaderList();
	};
}

#endif