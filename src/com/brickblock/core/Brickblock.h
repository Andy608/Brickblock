#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

#include <glad\glad.h>
#include "../util/logger/BBLogger.h"

namespace bb
{
	class Window;
	class ResourceManager;
	class GameSettings;
	class World;

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

		const GLuint getTickCount() const;

	private:
		static std::string CLASS_NAME;
		GLboolean mIsInitialized;
		GLboolean mIsRunning;

		ResourceManager *mResourceManager;
		GameSettings *mGameSettings;

		const Window &mWINDOW;

		World *mCurrentWorld;

		static const GLint TICKS_PER_SECOND;
		static const GLfloat TIME_SLICE;
		static const GLfloat LAG_CAP;

		GLuint mTickCount;
		GLint mFramesPerSecond;

		Brickblock();

		void init(GLint argc, GLint **argv);

		void update(const GLdouble& DELTA_TIME);
		void render(const GLdouble& DELTA_TIME);

	};
}

#endif