#ifndef BB_MESHRESOURCEPACK_H_
#define BB_MESHRESOURCEPACK_H_

#include "ResourcePack.h"

namespace bb
{
	struct MeshResourcePack : public ResourcePack
	{
	friend class ResourceManager;

	public:
		MeshResourcePack(MeshResourcePack const &copy) = delete;
		void operator=(MeshResourcePack const &copy) = delete;

	private:
		MeshResourcePack();
		void load();
	};
}

#endif