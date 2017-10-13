#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include "../util/logger/Logger.h"

namespace bb
{
	class Window;

	class Brickblock
	{
	public:
		Brickblock(Window *gameWindow);
		~Brickblock();

		void start();

	private:
		Logger mBrickblockLogger;
		Window *mGameWindow;
	};
}

#endif