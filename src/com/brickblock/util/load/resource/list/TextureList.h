#ifndef BB_TEXTURELIST_H_
#define BB_TEXTURELIST_H_

namespace bb
{
	class Texture;
	struct TextureList
	{
	public:
		friend struct TextureResourcePack;

		static void init();
		static const TextureList& getInstance();

		Texture &testTexture;

	private:
		static TextureList *instance;
		TextureList();
	};
}

#endif