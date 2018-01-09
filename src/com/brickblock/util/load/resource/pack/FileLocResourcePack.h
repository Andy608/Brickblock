#ifndef BB_FILELOCRESOURCEPACK_H_
#define BB_FILELOCRESOURCEPACK_H_

#include "ResourcePack.h"

namespace bb
{
	class FileLocation;
	struct FileLocResourcePack : public ResourcePack
	{
		friend class ResourceManager;

	public:
		static const std::string LOC__TEST_MODEL_VS;
		static const std::string LOC__TEST_MODEL_FS;
		static const std::string LOC__TEST_MESH;
		static const std::string LOC__TEST_TEXTURE;

		static void init();
		static const FileLocResourcePack& getInstance() { return *instance; };

		FileLocResourcePack(FileLocResourcePack const &copy) = delete;
		void operator=(FileLocResourcePack const &copy) = delete;

	private:
		static FileLocResourcePack *instance;

		FileLocResourcePack(std::string resourceID);
		void load();
	};
}

#endif