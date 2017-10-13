#include <iostream>
#include "Brickblock.h"
#include "../window/Window.h"
using namespace bb;

Brickblock::Brickblock(Window *gameWindow) :
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
		glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(windowHandle);
		glfwPollEvents();
	}
}