#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include <glad\glad.h>
#include "../util/logger/BBLogger.h"

namespace bb
{
	class Window;

	class Brickblock
	{
	public:
		static Brickblock* init(GLint argc, GLint **argv);

		~Brickblock();

		void start();

	private:
		static std::string CLASS_NAME;
		static Brickblock* instance;
		Brickblock();
	};
}

#endif