#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include <glad\glad.h>
#include "../util/logger/Logger.h"

namespace bb
{
	class Window;

	class Brickblock
	{
	public:
		static Logger bbLogger;
		static Brickblock *brickblock;
		static Brickblock* init(GLint argc, GLint **argv);
		~Brickblock();

		void start();

	private:
		Window *mGameWindow;

		Brickblock();
	};
}

#endif