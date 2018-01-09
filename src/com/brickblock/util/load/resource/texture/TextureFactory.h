#ifndef BB_TEXTUREFACTORY_H_
#define BB_TEXTUREFACTORY_H_

#include <glad/glad.h>
#include "../mesh/util/TextureWrapper.h"

namespace bb
{
	class Model;
	class Texture;
	struct TextureFactory
	{
		//Eventually skybox setup will be here too maybe
		//Maybe height map stuff too in the future.
		//Normal map stuff? hmmm
		//Texture detail enum to decide how textures should be rendered maybe
		/*enum class TextureDetail : GLuint
		{
			LOW = 0,	//nearest mipmap nearest
			MEDIUM = 1,	//linear  mipmap nearest
			HIGH = 2,	//linear  mipmap linear
		};*/

		//Uses graphics settings to decide how image should display
		//static void setTexture(Model &model, Texture &texture);

		static void setTexture(Model &model, Texture &texture,
			const TextureWrapper::WrapStyle& wrapStyleS, const TextureWrapper::WrapStyle& wrapStyleT,
			const TextureWrapper::MinFilter& minifyFiler, const TextureWrapper::MagFilter& magnifyFilter);

	};
}

#endif