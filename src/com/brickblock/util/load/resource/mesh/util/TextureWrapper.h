#ifndef BB_TEXTUREWRAPPER_H_
#define BB_TEXTUREWRAPPER_H_

#include "GLObjectWrapper.h"
#include "../../texture/Texture.h"
#include <gl/GL.h>

namespace bb
{
	struct TextureWrapper : public GLObjectWrapper
	{
	public:
		enum class WrapStyle : GLint
		{
			REPEAT = GL_REPEAT,
			MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
			CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
			CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER
		};

		enum class MinFilter : GLint
		{
			NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
			LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
			NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
			LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR
		};

		enum class MagFilter : GLint
		{
			NEAREST = GL_NEAREST,
			LINEAR = GL_LINEAR
		};

		TextureWrapper(Texture &texture);
		~TextureWrapper();

		virtual void bind() const;
		virtual void unbind() const;

		void setTexture(Texture &texture);

		void setWrapStyleS(const WrapStyle& wrapStyleS);
		void setWrapStyleT(const WrapStyle& wrapStyleT);

		void setMinifyFilter(const MinFilter& minifyFilter);
		void setMagnifyFilter(const MagFilter& magnifyFilter);

		void generateGLTexture();

		const Texture& getCurrentTexture() const;
		
		const WrapStyle& getWrapStyleS() const;
		const WrapStyle& getWrapStyleT() const;

		const MinFilter& getMinFilter() const;
		const MagFilter& getMagFilter() const;

	private:
		Texture &mTexture;

		WrapStyle mWrapStyleS;
		WrapStyle mWrapStyleT;

		MinFilter mMinifyFiler;
		MagFilter mMagnifyFilter;

		virtual void createID();
	};
}

#endif