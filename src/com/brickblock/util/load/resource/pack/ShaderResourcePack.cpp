#include "ShaderResourcePack.h"
#include "../shader/Shader.h"
#include "../shader/ShaderProgram.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

ShaderResourcePack *ShaderResourcePack::instance = nullptr;
const std::string ShaderResourcePack::SHADER__TEST_MODEL_VS = "shader__test_model_vs";
const std::string ShaderResourcePack::SHADER__TEST_MODEL_FS = "shader__test_model_fs";
const std::string ShaderResourcePack::SHADER__TEST_MODEL_SP = "shader__test_model_sp";

void ShaderResourcePack::init()
{
	if (!instance)
	{
		instance = new ShaderResourcePack("shader");
	}
}

ShaderResourcePack::ShaderResourcePack(std::string resourceID) :
	ResourcePack(resourceID)
{

}

void ShaderResourcePack::load()
{
	mTestModelVS = new Shader(SHADER__TEST_MODEL_VS, Shader::EnumShaderType::VERTEX, new FileLocation(*DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::VS_EXT));
	mTestModelFS = new Shader(SHADER__TEST_MODEL_FS, Shader::EnumShaderType::FRAGMENT, new FileLocation(*DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::FS_EXT));
	mTestModelProgram = new ShaderProgram(SHADER__TEST_MODEL_SP);

	mTestModelProgram->addShader(mTestModelVS);
	mTestModelProgram->addShader(mTestModelFS);

	registerResource(mTestModelVS);
	registerResource(mTestModelFS);
	registerResource(mTestModelProgram);

	ResourcePack::load();
}