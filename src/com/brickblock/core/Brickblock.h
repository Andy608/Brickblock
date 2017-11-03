#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include "../util/logger/Logger.h"

namespace bb
{
	class Window;

	class Brickblock
	{
	public:
		static Brickblock *brickblock;
		static Brickblock* init(GLint argc, GLint **argv);
		~Brickblock();

		void start();

	private:
		static Logger logger;
		Window *mGameWindow;

		Brickblock();
	};
}

#endif