#include "TextureFactory.h"
#include "Texture.h"
#include "../../../../model/Model.h"
#include "../../../../util/logger/BBLogger.h"
using namespace bb;

void TextureFactory::setTexture(Model &model, Texture &texture,
	const TextureWrapper::WrapStyle& wrapStyleS, const TextureWrapper::WrapStyle& wrapStyleT,
	const TextureWrapper::MinFilter& minifyFiler, const TextureWrapper::MagFilter& magnifyFilter)
{
	if (!texture.isLoaded())
	{
		BBLogger::logWarn("TextureFactory.cpp", "The texture: " + texture.getID() + "is not loaded! Either you forgot to load it or there was an error while loading the texture.");
		return;
	}

	if (model.mTextureWrapper == nullptr)
	{
		model.mTextureWrapper = new TextureWrapper(texture);
	}
	else
	{
		model.mTextureWrapper->setTexture(texture);
	}

	model.mTextureWrapper->setWrapStyleS(wrapStyleS);
	model.mTextureWrapper->setWrapStyleT(wrapStyleT);
	model.mTextureWrapper->setMinifyFilter(minifyFiler);
	model.mTextureWrapper->setMagnifyFilter(magnifyFilter);
	model.mTextureWrapper->generateGLTexture();
}