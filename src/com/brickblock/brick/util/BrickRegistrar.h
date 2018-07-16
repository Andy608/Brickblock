#ifndef BB_BRICKREGISTRAR_H_
#define BB_BRICKREGISTRAR_H_

#include <vector>
#include "../util/BrickType.h"

namespace bb
{
	class BrickRegistrar
	{
		friend class Brickblock;

	public:
		static void BrickRegistrar::registerBrick(const Brick *brick);

	private:
		static BrickRegistrar *mpsInstance;
		std::vector<const Brick*> mBrickRegistry;

		static void initInstance();
		static void cleanupInstance();

		inline BrickRegistrar() {};
		BrickRegistrar(const BrickRegistrar &copy) = delete;
		void operator=(const BrickRegistrar &copy) = delete;
		~BrickRegistrar();
	};
}

#endif