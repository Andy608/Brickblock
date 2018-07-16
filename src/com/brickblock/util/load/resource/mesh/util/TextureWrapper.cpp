#include "TextureWrapper.h"
using namespace bb;

TextureWrapper::TextureWrapper(Texture &texture) :
	mTexture(texture)
{
	createID();
}

TextureWrapper::~TextureWrapper()
{
	glDeleteTextures(SIZE, &mID);
}

void TextureWrapper::bind() const
{
	glBindTexture(GL_TEXTURE_2D, mID);
}

void TextureWrapper::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureWrapper::setTexture(Texture &texture)
{
	mTexture = texture;
}

void TextureWrapper::setWrapStyleS(const WrapStyle& wrapStyleS)
{
	mWrapStyleS = wrapStyleS;
}

void TextureWrapper::setWrapStyleT(const WrapStyle& wrapStyleT)
{
	mWrapStyleT = wrapStyleT;
}

void TextureWrapper::setMinifyFilter(const MinFilter& minifyFilter)
{
	mMinifyFiler = minifyFilter;
}

void TextureWrapper::setMagnifyFilter(const MagFilter& magnifyFilter)
{
	mMagnifyFilter = magnifyFilter;
}

void TextureWrapper::generateGLTexture()
{
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLint>(mWrapStyleS));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLint>(mWrapStyleT));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(mMinifyFiler));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(mMagnifyFilter));

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mTexture.getWidth(), mTexture.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, mTexture.getPixelData());
	glGenerateMipmap(GL_TEXTURE_2D);
	unbind();
}

const Texture& TextureWrapper::getCurrentTexture() const
{
	return mTexture;
}

const TextureWrapper::WrapStyle& TextureWrapper::getWrapStyleS() const
{
	return mWrapStyleS;
}

const TextureWrapper::WrapStyle& TextureWrapper::getWrapStyleT() const
{
	return mWrapStyleT;
}

const TextureWrapper::MinFilter& TextureWrapper::getMinFilter() const
{
	return mMinifyFiler;
}

const TextureWrapper::MagFilter& TextureWrapper::getMagFilter() const
{
	return mMagnifyFilter;
}

void TextureWrapper::createID()
{
	glGenTextures(SIZE, &mID);
}