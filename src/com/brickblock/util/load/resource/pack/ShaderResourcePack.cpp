#include "ShaderResourcePack.h"
#include "../shader/Shader.h"
#include "../shader/ShaderProgram.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
#include "../list/FileLocationList.h"
#include "../list/ShaderList.h"
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
	Shader *testModelVS = new Shader(SHADER__TEST_MODEL_VS, Shader::EnumShaderType::VERTEX, FileLocationList::getInstance().testModelVS);
	Shader *testModelFS = new Shader(SHADER__TEST_MODEL_FS, Shader::EnumShaderType::FRAGMENT, FileLocationList::getInstance().testModelFS);
	ShaderProgram *testModelProgram = new ShaderProgram(SHADER__TEST_MODEL_SP);

	testModelProgram->addShader(testModelVS);
	testModelProgram->addShader(testModelFS);

	registerResource(testModelVS);
	registerResource(testModelFS);
	registerResource(testModelProgram);

	ResourcePack::load();

	ShaderList::init();
}