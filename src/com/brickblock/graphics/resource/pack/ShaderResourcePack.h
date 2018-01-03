#ifndef BB_SHADERRESOURCEPACK_H_
#define BB_SHADERRESOURCEPACK_H_
#include "ResourcePack.h"

namespace bb
{
	class Shader;
	class ShaderProgram;
	class ShaderResourcePack : public ResourcePack
	{
	friend class ResourceManager;

	public:
		ShaderResourcePack(ShaderResourcePack const &copy) = delete;
		void operator=(ShaderResourcePack const &copy) = delete;

		static const ShaderProgram& getTestModelProgram() { return *testModelProgram; }

	private:
		static Shader *testModelVS;
		static Shader *testModelFS;
		static ShaderProgram *testModelProgram;

		ShaderResourcePack();
		void load();
	};
}

#endif