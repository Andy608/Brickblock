#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "../window/Window.h"
using namespace bb;

Brickblock* Brickblock::brickblock = nullptr;
Logger Brickblock::bbLogger = Logger("[%x %r] % l(Logger:%n) %v");

Brickblock* Brickblock::init(GLint argc, GLint **argv)
{
	if (brickblock == nullptr)
	{
		brickblock = new Brickblock();
		brickblock->mGameWindow = Window::createWindow();
	}
	else
	{
		//logger.log(Logger::LEVEL_WARN, "Brickblock is already initialized.");
	}

	return brickblock;
}

Brickblock::Brickblock()
{
	//logger.log(Logger::LEVEL_TRACE, "Creating Brickblock...");
}

Brickblock::~Brickblock()
{
	//logger.log(Logger::LEVEL_TRACE, "Deleting Brickblock...");
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