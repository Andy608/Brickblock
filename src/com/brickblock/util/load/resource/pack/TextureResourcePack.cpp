#include "TextureResourcePack.h"
#include "../../../../util/filesystem/file/FileLocation.h"
#include "../../../../util/filesystem/directory/DirectoryList.h"
#include "../list/FileLocationList.h"
#include "../list/TextureList.h"
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
	Texture *testTex = new Texture(TEXTURE__TEST, FileLocationList::getInstance().testFileLocation);

	registerResource(testTex);

	ResourcePack::load();

	TextureList::init();
}