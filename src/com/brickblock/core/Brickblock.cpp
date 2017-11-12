#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "../window/Window.h"
#include "../util/logger/ConsoleLogger.h"
#include "../util/logger/FileLogger.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
using namespace bb;

Brickblock* Brickblock::instance = nullptr;

Brickblock* Brickblock::init(GLint argc, GLint **argv)
{
	if (instance == nullptr)
	{
		instance = new Brickblock();
	}
	else
	{
		//logger.log(Logger::LEVEL_WARN, "Brickblock is already initialized.");
	}

	return instance;
}

Brickblock::Brickblock()
{
	//logger.log(Logger::LEVEL_TRACE, "Creating Brickblock...");
}

Brickblock::~Brickblock()
{
	//logger.log(Logger::LEVEL_TRACE, "Deleting Brickblock...");
}

void Brickblock::start()
{
	GLFWwindow* windowHandle = Window::getInstance().getWindowHandle();
	while (!glfwWindowShouldClose(windowHandle))
	{
		glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(windowHandle);
		glfwPollEvents();
	}
}