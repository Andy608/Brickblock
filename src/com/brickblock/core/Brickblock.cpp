#include <iostream>
#include "Brickblock.h"
#include "BrickblockInfo.h"
#include "../window/Window.h"
#include "../util/logger/BBLogger.h"
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "../util/load/ResourceManager.h"
#include "../input/setting/GameSettings.h"
#include "../util/filesystem/directory/DirectoryList.h"
#include "../world/World.h"

using namespace bb;

std::string Brickblock::CLASS_NAME = "Brickblock.cpp";
const GLint Brickblock::TICKS_PER_SECOND = 60;
const GLfloat Brickblock::TIME_SLICE = 1.0f / static_cast<GLfloat>(TICKS_PER_SECOND);
const GLfloat Brickblock::LAG_CAP = 0.15f;

Brickblock::Brickblock() :
	mIsInitialized(GL_FALSE),
	mIsRunning(GL_FALSE),
	mResourceManager(nullptr),
	mGameSettings(nullptr),
	mWINDOW(Window::getInstance()),
	mCurrentWorld(nullptr)
{

}

Brickblock::~Brickblock()
{
	delete mGameSettings;
	delete mResourceManager;
}

void Brickblock::init(GLint argc, GLint **argv)
{
	if (!mIsInitialized)
	{
		mGameSettings = GameSettings::init();

		//Log creating resource manager
		BBLogger::logTrace(CLASS_NAME, "Creating Resource Manager.");
		mResourceManager = new ResourceManager();

		BBLogger::logTrace(CLASS_NAME, "...Creating Resource Packs");
		mResourceManager->createResourcePacks();
		
		BBLogger::logTrace(CLASS_NAME, "...Registering Resource Packs");
		mResourceManager->registerResourcePacks();
		
		BBLogger::logTrace(CLASS_NAME, "...Registering Resources in Packs");
		mResourceManager->loadResourcePacks();

		mCurrentWorld = new World("Hello, World!");

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
		
		init(argc, argv);

		GLFWwindow* windowHandle = mWINDOW.getGLFWWindow();

		GLdouble lastTime = glfwGetTime();
		GLdouble currentTime = 0.0f;
		GLdouble deltaTime = 0.0f;
		GLdouble accumulatedTime = 0.0f;


		while (!glfwWindowShouldClose(windowHandle))
		{
			currentTime = glfwGetTime();
			deltaTime = (currentTime - lastTime);
			accumulatedTime += deltaTime;
			lastTime = currentTime;

			/*if (accumulatedTime >= LAG_CAP)
			{
				accumulatedTime = LAG_CAP;
			}*/
			

			if (accumulatedTime > TIME_SLICE)
			{
				accumulatedTime -= TIME_SLICE;
				update(TIME_SLICE);
				glfwPollEvents();
			}

			render(accumulatedTime / TIME_SLICE);
			//BBLogger::logDebug(CLASS_NAME, "Alpha: " + std::to_string(accumulatedTime / TIME_SLICE));
		}

		glfwDestroyWindow(windowHandle);
	}
	else
	{
		BBLogger::logWarn(CLASS_NAME, BrickblockInfo::TITLE + " is already running.");
	}

	mIsRunning = GL_FALSE;
}

void Brickblock::update(const GLdouble& DELTA_TIME)
{
	++mTickCount;

	if (mTickCount % TICKS_PER_SECOND == 0)
	{
		//BBLogger::logTrace(CLASS_NAME, "Ticks: " + std::to_string(mTickCount) + " | Frames: " + std::to_string(mFramesPerSecond));

		mTickCount = 0;
		mFramesPerSecond = 0;
	}

	mCurrentWorld->update(DELTA_TIME);

	//mWindow->update(DELTA_TIME);
	//mSceneManager->update(DELTA_TIME);
	//mInputTracker->update(DELTA_TIME);
}


void Brickblock::render(const GLdouble& alpha)
{
	++mFramesPerSecond;

	glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mCurrentWorld->render(alpha);

	//mSceneManager->render(DELTA_TIME);
	//mWindow->render(DELTA_TIME);
	glfwSwapBuffers(mWINDOW.getGLFWWindow());
}

const GLuint Brickblock::getTickCount() const
{
	return mTickCount;
}