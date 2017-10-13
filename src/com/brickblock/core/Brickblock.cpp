#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "../window/Window.h"
using namespace bb;

Brickblock::Brickblock(Window *gameWindow) :
	mBrickblockLogger(BrickblockInfo::TITLE),
	mGameWindow(gameWindow)
{

}

Brickblock::~Brickblock()
{
	delete mGameWindow;
}

void Brickblock::start()
{
	GLFWwindow* windowHandle = mGameWindow->getWindowHandle();
	while (!glfwWindowShouldClose(windowHandle))
	{
		glfwSwapBuffers(windowHandle);
		glfwPollEvents();
	}
}