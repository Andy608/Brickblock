#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "window/Window.h"
#include "../util/logger/BBLogger.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "load/ResourceManager.h"

#include "../util/filesystem/directory/DirectoryList.h"
#include "../graphics/resource/shader/Shader.h"
using namespace bb;

std::string Brickblock::CLASS_NAME = "Brickblock.cpp";

Brickblock::Brickblock() :
	mIsInitialized(GL_FALSE),
	mIsRunning(GL_FALSE),
	mResourceManager(nullptr)
{

}

Brickblock::~Brickblock()
{
	delete mResourceManager;
}

void Brickblock::init(GLint argc, GLint **argv)
{
	if (!mIsInitialized)
	{
		//Log creating resource manager
		BBLogger::logTrace(CLASS_NAME, "Creating Resource Manager.");
		mResourceManager = new ResourceManager();
		BBLogger::logTrace(CLASS_NAME, "...Registering Resource Packs");
		mResourceManager->registerResourcePacks();
		BBLogger::logTrace(CLASS_NAME, "...Loading Resource Packs");
		mResourceManager->loadResourcePacks();

		mIsInitialized = GL_TRUE;
	}
	else
	{
		BBLogger::logTrace(CLASS_NAME, BrickblockInfo::TITLE + " is already initialized.");
	}
}

void Brickblock::start(GLint argc, GLint **argv)
{
	if (!mIsRunning)
	{
		mIsRunning = GL_TRUE;
		GLFWwindow* windowHandle = Window::getInstance().getGLFWWindow();

		init(argc, argv);

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

		glfwDestroyWindow(windowHandle);
	}
	else
	{
		BBLogger::logWarn(CLASS_NAME, BrickblockInfo::TITLE + " is already running.");
	}

	mIsRunning = GL_FALSE;
}