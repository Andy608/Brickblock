#ifndef BB_MESHRESOURCEPACK_H_
#define BB_MESHRESOURCEPACK_H_

#include "ResourcePack.h"
#include "../mesh/Mesh.h"

namespace bb
{
	struct MeshResourcePack : public ResourcePack
	{
	friend class ResourceManager;

	private:
		static MeshResourcePack *instance;

		//Meshes in this pack
		Mesh *mTestMesh;
		Mesh *mStandardBrickTop;
		Mesh *mStandardBrickBottom;
		Mesh *mStandardBrickSide;
		Mesh *mStandardBrickTest;

		MeshResourcePack(std::string resourceID);
		void load();

	public:
		static void init();
		static const MeshResourcePack& getInstance() { return *instance; };

		MeshResourcePack(MeshResourcePack const &copy) = delete;
		void operator=(MeshResourcePack const &copy) = delete;

		static const Mesh& testMesh() { return *instance->mTestMesh; }
		static const Mesh& standardBrickTop() { return *instance->mStandardBrickTop; }
		static const Mesh& standardBrickBottom() { return *instance->mStandardBrickBottom; }
		static const Mesh& standardBrickSide() { return *instance->mStandardBrickSide; }
		static const Mesh& standardBrickTest() { return *instance->mStandardBrickTest; }
	};
}

#endif