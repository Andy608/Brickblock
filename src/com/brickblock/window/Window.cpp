#include <string>
#include <glad\glad.h>
#include "Window.h"
#include "../core/BrickblockInfo.h"
using namespace bb;

const GLFWvidmode* Window::init()
{
	if (glfwInit())
	{
		return glfwGetVideoMode(glfwGetPrimaryMonitor());
	}
	else
	{
		//Use logger in the future.
		throw(std::string("Error initializing GLFW."));
	}
}

const std::string Window::initRandomizedTitle()
{
	return BrickblockInfo::TITLE + " V" + BrickblockInfo::VERSION
		+ " | " + "Welcome to the first ever version of brickblock."/* + Random slogan */
		+ " | Created by " + BrickblockInfo::AUTHORS + " :)";
}

Window::Window() :
	mVIDEO_MODE(init()),
	mTITLE(initRandomizedTitle())
{
	initWindowHints();
	initWindowSize();

	mWindowHandle = glfwCreateWindow(mWidth, mHeight, mTITLE.c_str(), nullptr, nullptr);
	glfwHideWindow(mWindowHandle);

	if (mWindowHandle == nullptr)
	{
		glfwTerminate();
		//Use logger in the future!
		throw(std::string("Window could not be created."));
	}
	else
	{
		glfwMakeContextCurrent(mWindowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			glfwTerminate();
			//Use logger in the future!
			throw(std::string("Failed to initialize GLAD."));
		}

		glViewport(0, 0, mWidth, mHeight);
		glfwShowWindow(mWindowHandle);
	}
}

Window::~Window()
{
	glfwTerminate();
}

void Window::initWindowHints() const
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
}

void Window::initWindowSize()
{
	//Get settings from file in the future.
	mWidth = mVIDEO_MODE->width / 2;
	mHeight = mVIDEO_MODE->height / 2;
}

GLFWwindow* Window::getWindowHandle() const
{
	return mWindowHandle;
}
