#include "../window/Window.h"
#include "Brickblock.h"
using namespace bb;

int main()
{
	Window* brickblockWindow = new Window();
	Brickblock* brickblock = new Brickblock(brickblockWindow);
	
	brickblock->start();

	delete brickblock;
	return 0;
}