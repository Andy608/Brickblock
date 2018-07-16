#ifndef BB_TEXTURERESOURCEPACK_H_
#define BB_TEXTURERESOURCEPACK_H_

#include "ResourcePack.h"
#include "../texture/Texture.h"

namespace bb
{
	struct TextureResourcePack : public ResourcePack
	{
		friend class ResourceManager;

	private:
		static TextureResourcePack *instance;

		Texture *mTestTex;

		TextureResourcePack(std::string resourceID);
		void load();

	public:
		static const std::string TEXTURE__TEST;

		static void init();
		static const TextureResourcePack& getInstance() { return *instance; };

		TextureResourcePack(TextureResourcePack const &copy) = delete;
		void operator=(TextureResourcePack const &copy) = delete;

		static Texture& testTex() { return *instance->mTestTex;  }
	};
}

#endif