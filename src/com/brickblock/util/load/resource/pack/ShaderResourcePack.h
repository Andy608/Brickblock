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

	private:
		static const std::string SHADER__TEST_MODEL_VS;
		static const std::string SHADER__TEST_MODEL_FS;

		static ShaderResourcePack *instance;

		Shader *mTestModelVS;
		Shader *mTestModelFS;
		ShaderProgram *mTestModelProgram;

		ShaderResourcePack(std::string resourceID);
		void load();

	public:
		static const std::string SHADER__TEST_MODEL_SP;

		static void init();
		static const ShaderResourcePack& getInstance() { return *instance; };

		ShaderResourcePack(ShaderResourcePack const &copy) = delete;
		void operator=(ShaderResourcePack const &copy) = delete;

		static const ShaderProgram& testModelProgram() { return *instance->mTestModelProgram; }
	};
}

#endif