#ifndef BB_TEXTURE_H_
#define BB_TEXTURE_H_

#include "../Resource.h"
#include "../../../../util/filesystem/file/FileLocation.h"

namespace bb
{
	class FileLocation;
	class Texture : public Resource
	{
	public:
		Texture(std::string resourceID, const FileLocation &imageFileLocation);
		virtual ~Texture();

		const Texture& operator=(const Texture& another);

		virtual void load();
		virtual void unload();

		const GLuint getWidth() const;
		const GLuint getHeight() const;
		const GLubyte* getPixelData() const;

	private:
		const FileLocation &mImageFileLocation;
		GLint mWidth;
		GLint mHeight;
		GLint mColorChannels;
		GLubyte *mPixelData;
	};
}

#endif