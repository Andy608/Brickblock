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
		MeshResourcePack(MeshResourcePack const &copy) = delete;
		void operator=(MeshResourcePack const &copy) = delete;

		static const Mesh& getTestMesh() { return *testMesh; }

	private:
		static Mesh *testMesh;

		MeshResourcePack();
		void load();
	};
}

#endif