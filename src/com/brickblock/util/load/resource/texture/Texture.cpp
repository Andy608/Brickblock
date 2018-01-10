#include "Texture.h"
#include "../../../../util/logger/BBLogger.h"
#include <soil/SOIL.h>
using namespace bb;

Texture::Texture(std::string resourceID, FileLocation *imageFileLocation) :
	Resource(resourceID, Resource::ResourceType::TEXTURE),
	mImageFileLocation(imageFileLocation)
{

}

Texture::~Texture()
{
	if (mIsLoaded)
	{
		unload();
	}

	delete mImageFileLocation;
}

const Texture& Texture::operator=(const Texture& another)
{
	return another;
}

void Texture::load()
{
	mPixelData = SOIL_load_image(mImageFileLocation->getPath().c_str(), &mWidth, &mHeight, &mColorChannels, SOIL_LOAD_RGBA);

	if (mPixelData != nullptr)
	{
		BBLogger::logTrace("Texture.cpp", "Successfully loaded texture: " + mImageFileLocation->getPath());
		mIsLoaded = GL_TRUE;
	}
	else
	{
		BBLogger::logError("Texture.cpp", "Failed to load texture: " + mImageFileLocation->getPath());
		mIsLoaded = GL_FALSE;
	}
}

void Texture::unload()
{
	if (mIsLoaded)
	{
		BBLogger::logTrace("Texture.cpp", "Unloading texture: " + mImageFileLocation->getPath());
		SOIL_free_image_data(mPixelData);
		mIsLoaded = GL_FALSE;
	}
}

const GLuint Texture::getWidth() const
{
	return mWidth;
}

const GLuint Texture::getHeight() const
{
	return mHeight;
}

const GLubyte* Texture::getPixelData() const
{
	return mPixelData;
}