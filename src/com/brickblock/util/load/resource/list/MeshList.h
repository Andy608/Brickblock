#ifndef BB_MESHLIST_H_
#define BB_MESHLIST_H_

namespace bb
{
	class Mesh;
	struct MeshList
	{
	public:
		friend struct MeshResourcePack;

		static void init();
		static const MeshList& getInstance();

		Mesh &testMesh;

	private:
		static MeshList *instance;
		MeshList();
	};
}

#endif