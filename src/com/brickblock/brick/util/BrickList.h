#ifndef BB_BRICKLIST_H_
#define BB_BRICKLIST_H_

#include "../util/BrickType.h"
#include "../BrickStone.h"

namespace bb
{
	class BrickList
	{
		friend class Brickblock;
		friend class ResourceManager;

	public:
		const static BrickStone* STONE;

	private:
		inline BrickList() {};
		BrickList(BrickList const &copy) = delete;
		void operator=(BrickList const &copy) = delete;

		static void createBricks();
		static void registerBricks();
	};
}

#endif