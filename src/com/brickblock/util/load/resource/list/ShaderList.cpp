#include "ShaderList.h"
#include "../shader/ShaderProgram.h"
#include "../pack/ShaderResourcePack.h"
using namespace bb;

ShaderList *ShaderList::instance = nullptr;

void ShaderList::init()
{
	if (!instance)
	{
		instance = new ShaderList();
	}
}


const ShaderList& ShaderList::getInstance()
{
	return *instance;
}

ShaderList::ShaderList() :
	meshShaderProgram(dynamic_cast<ShaderProgram&>(ShaderResourcePack::getInstance().getResource(ShaderResourcePack::SHADER__TEST_MODEL_SP)))
{
	
}