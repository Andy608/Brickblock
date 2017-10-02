#ifndef BB_BRICKBLOCK_H_
#define BB_BRICKBLOCK_H_

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
		Window *mGameWindow;
	};
}

#endif