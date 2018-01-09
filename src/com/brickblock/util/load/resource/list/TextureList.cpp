#include "TextureList.h"
#include "../texture/Texture.h"
#include "../pack/TextureResourcePack.h"
using namespace bb;

TextureList *TextureList::instance = nullptr;

void TextureList::init()
{
	if (!instance)
	{
		instance = new TextureList();
	}
}


const TextureList& TextureList::getInstance()
{
	return *instance;
}

TextureList::TextureList() :
	testTexture(dynamic_cast<Texture&>(TextureResourcePack::getInstance().getResource(TextureResourcePack::TEXTURE__TEST)))
{
	
}