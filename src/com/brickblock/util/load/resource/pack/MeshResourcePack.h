#ifndef BB_MESHRESOURCEPACK_H_
#define BB_MESHRESOURCEPACK_H_

#include "ResourcePack.h"
#include "../mesh/Mesh.h"

namespace bb
{
	struct MeshResourcePack : public ResourcePack
	{
	friend class ResourceManager;

	public:
		static const std::string MESH__TEST;

		static void init();
		static const MeshResourcePack& getInstance() { return *instance; };

		MeshResourcePack(MeshResourcePack const &copy) = delete;
		void operator=(MeshResourcePack const &copy) = delete;

	private:
		static MeshResourcePack *instance;
		
		MeshResourcePack(std::string resourceID);
		void load();
	};
}

#endif