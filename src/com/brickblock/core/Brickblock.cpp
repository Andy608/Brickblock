#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "../window/Window.h"
#include "../util/logger/ConsoleLogger.h"
#include "../util/logger/FileLogger.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"

#include "../util/filesystem/directory/DirectoryList.h"
#include "../graphics/resource/shader/Shader.h"
using namespace bb;

Brickblock* Brickblock::instance = nullptr;
std::string Brickblock::CLASS_NAME = "Brickblock.cpp";

Brickblock* Brickblock::init(GLint argc, GLint **argv)
{
	if (instance == nullptr)
	{
		instance = new Brickblock();
	}
	else
	{
		BBLogger::getLogger().logWarn(CLASS_NAME, "Brickblock is already initialized.", Logger::EnumLogLocation::CONSOLE_AND_FILE);
	}

	return instance;
}

Brickblock::Brickblock()
{

}

Brickblock::~Brickblock()
{
}

void Brickblock::start()
{
	GLFWwindow* windowHandle = Window::getInstance().getGLFWWindow();

	Shader *vertexShaderTest = new Shader(Shader::EnumShaderType::VERTEX, new FileLocation(*DirectoryList::getInstance().mRootDirectory, "vertex_shader_test", FileLocation::VS_EXT));
	vertexShaderTest->load();
	vertexShaderTest->unload();
	vertexShaderTest->load();

	delete vertexShaderTest;

	while (!glfwWindowShouldClose(windowHandle))
	{
		glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(windowHandle);
		glfwPollEvents();
	}
}