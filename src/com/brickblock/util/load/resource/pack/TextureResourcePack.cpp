#include "TextureResourcePack.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
using namespace bb;

TextureResourcePack *TextureResourcePack::instance = nullptr;
const std::string TextureResourcePack::TEXTURE__TEST = "texture__test";

void TextureResourcePack::init()
{
	if (!instance)
	{
		instance = new TextureResourcePack("texture");
	}
}

TextureResourcePack::TextureResourcePack(std::string resourceID) :
	ResourcePack(resourceID)
{

}

void TextureResourcePack::load()
{
	mTestTex = new Texture(TEXTURE__TEST, new FileLocation(*DirectoryList::getInstance().mTextureDirectory, "test_img", FileLocation::PNG_EXT));

	registerResource(mTestTex);

	ResourcePack::load();

	//TextureList::init();
}