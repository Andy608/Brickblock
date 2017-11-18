#include <iostream>
#include <string>
#include "Window.h"
#include "../core/BrickblockInfo.h"
using namespace bb;

GLint Window::width = 0;
GLint Window::height = 0;

const GLFWvidmode* Window::initGLFW()
{
	if (glfwInit())
	{
		return glfwGetVideoMode(glfwGetPrimaryMonitor());
	}
	else
	{
		std::string error = "Error initializing GLFW.";
		//logger->log(Logger::LEVEL_ERROR, error);
		throw(error);
	}
}

const std::string Window::initRandomizedTitle()
{
	return BrickblockInfo::TITLE + " V" + BrickblockInfo::VERSION
		+ " | " + "Welcome to the first ever version of brickblock."/* + Random slogan */
		+ " | Created by " + BrickblockInfo::AUTHORS + " :)";
}

Window::Window() :
	mVIDEO_MODE(initGLFW()),
	mTITLE(initRandomizedTitle())
{
	initWindowHints();
	initWindowSize();

	mWindowHandle = glfwCreateWindow(width, height, mTITLE.c_str(), nullptr, nullptr);
	glfwHideWindow(mWindowHandle);

	if (mWindowHandle == nullptr)
	{
		glfwTerminate();
		//logger->log(Logger::LEVEL_ERROR, "Window could not be created.");
	}
	else
	{
		glfwMakeContextCurrent(mWindowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			glfwTerminate();
			//logger->log(Logger::LEVEL_ERROR, "Failed to initialize GLAD.");
		}

		initWindowCallbacks();
		glViewport(0, 0, width, height);
		glfwShowWindow(mWindowHandle);
	}

	//logger->log(Logger::LEVEL_TRACE, "Creating Window...");
}

Window::~Window()
{
	//logger->log(Logger::LEVEL_TRACE, "Deleting Window...");
	glfwTerminate();
}

void Window::initWindowCallbacks() const
{
	glfwSetCursorPosCallback(mWindowHandle, cursorPositionCallback);
	glfwSetErrorCallback(errorCallback);
	glfwSetFramebufferSizeCallback(mWindowHandle, framebufferSizeCallback);
	glfwSetKeyCallback(mWindowHandle, keyCallback);
	glfwSetMouseButtonCallback(mWindowHandle, mouseButtonCallback);
	glfwSetScrollCallback(mWindowHandle, mouseScrollCallback);
	glfwSetWindowFocusCallback(mWindowHandle, windowFocusCallback);
	glfwSetWindowPosCallback(mWindowHandle, windowPositionCallback);
	glfwSetWindowSizeCallback(mWindowHandle, windowSizeCallback);
}

GLFWwindow* Window::getGLFWWindow() const
{
	return mWindowHandle;
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
	width = mVIDEO_MODE->width / 2;
	height = mVIDEO_MODE->height / 2;
}

void Window::updateViewportSize(GLint viewportWidth, GLint viewportHeight)
{
	width = viewportWidth;
	height = viewportHeight;
	glViewport(0, 0, width, height);
}

void Window::cursorPositionCallback(GLFWwindow* windowHandle, GLdouble xPosition, GLdouble yPosition)
{
	//std::cout << "Cursor Position Callback" << std::endl;
}

void Window::errorCallback(GLint error, const GLchar *description)
{
	std::cout << "GLFW Window Error #" + std::to_string(error) + ": " + description << std::endl;
}

void Window::framebufferSizeCallback(GLFWwindow* windowHandle, GLint windowWidth, GLint windowHeight)
{
	//std::cout << "Framebuffer Size Callback" << std::endl;
	updateViewportSize(windowWidth, windowHeight);
}

void Window::keyCallback(GLFWwindow* windowHandle, GLint key, GLint scancode, GLint action, GLint mode)
{
	//std::cout << "Keyboard Callback" << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
	{
		glfwSetWindowShouldClose(windowHandle, GL_TRUE);
	}
}

void Window::mouseButtonCallback(GLFWwindow* windowHandle, GLint button, GLint action, GLint mode)
{
	//std::cout << "Mouse Button Callback" << std::endl;
}

void Window::mouseScrollCallback(GLFWwindow* windowHandle, GLdouble xOffset, GLdouble yOffset)
{
	//std::cout << "Mouse Scroll Callback" << std::endl;
}

void Window::windowFocusCallback(GLFWwindow* windowHandle, GLint isFocused)
{
	//std::cout << "Window Focus Callback" << std::endl;
}

void Window::windowPositionCallback(GLFWwindow* windowHandle, GLint xPosition, GLint yPosition)
{
	//std::cout << "Window Position Callback" << std::endl;
}

void Window::windowSizeCallback(GLFWwindow* windowHandle, GLint windowWidth, GLint windowHeight)
{
	//std::cout << "Window Size Callback" << std::endl;
}