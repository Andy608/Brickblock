#include "../window/Window.h"
#include "Brickblock.h"
using namespace bb;

int main()
{
	Window *brickblockWindow = Window::createWindow();
	Brickblock *brickblock = new Brickblock(brickblockWindow);
	
	brickblock->start();

	delete brickblock;
	return 0;
}