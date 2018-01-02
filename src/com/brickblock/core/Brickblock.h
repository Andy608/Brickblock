#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include <glad\glad.h>
#include "../util/logger/BBLogger.h"

namespace bb
{
	class Window;
	class ResourceManager;

	class Brickblock
	{
	public:
		static Brickblock& getInstance()
		{
			static Brickblock instance;
			return instance;
		}

		Brickblock(Brickblock const &copy) = delete;
		void operator=(Brickblock const &copy) = delete;
		~Brickblock();

		void start(GLint argc, GLint **argv);

	private:
		static std::string CLASS_NAME;
		GLboolean mIsInitialized;
		GLboolean mIsRunning;

		ResourceManager *mResourceManager;

		Brickblock();

		void init(GLint argc, GLint **argv);
	};
}

#endif