#include "ShaderResourcePack.h"
#include "../shader/Shader.h"
#include "../shader/ShaderProgram.h"
#include "../../../util/filesystem/file/FileLocation.h"
#include "../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

Shader* ShaderResourcePack::testModelVS = nullptr;
Shader* ShaderResourcePack::testModelFS = nullptr;
ShaderProgram* ShaderResourcePack::testModelProgram = nullptr;

ShaderResourcePack::ShaderResourcePack() :
	ResourcePack(ResourceManager::ResourceType::SHADER)
{

}

void ShaderResourcePack::load()
{
	testModelVS = new Shader(Shader::EnumShaderType::VERTEX, new FileLocation(*DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::VS_EXT));
	testModelFS = new Shader(Shader::EnumShaderType::FRAGMENT, new FileLocation(*DirectoryList::getInstance().mShaderDirectory, "test_model", FileLocation::FS_EXT));
	testModelProgram = new ShaderProgram();

	testModelProgram->addShader(testModelVS);
	testModelProgram->addShader(testModelFS);

	registerResource(testModelVS);
	registerResource(testModelFS);
	registerResource(testModelProgram);

	ResourcePack::load();
}