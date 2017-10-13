#ifndef BB_WINDOW_H_
#define BB_WINDOW_H_

#include <string>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace bb
{
	class Window
	{
	public:
		static Window* createWindow();

		const GLFWvidmode *mVIDEO_MODE;
		const std::string mTITLE;
		
		~Window();

		GLFWwindow* getWindowHandle() const;

	private:
		static Window *window;

		static const GLFWvidmode* initGLFW();
		static const std::string initRandomizedTitle();

		static void updateViewportSize(GLint viewportWidth, GLint viewportHeight);

		static void cursorPositionCallback(GLFWwindow* windowHandle, GLdouble xPosition, GLdouble yPosition);
		static void errorCallback(GLint error, const GLchar *description);
		static void framebufferSizeCallback(GLFWwindow* windowHandle, GLint windowWidth, GLint windowHeight);
		static void keyCallback(GLFWwindow* windowHandle, GLint key, GLint scancode, GLint action, GLint mode);
		static void mouseButtonCallback(GLFWwindow* windowHandle, GLint button, GLint action, GLint mode);
		static void mouseScrollCallback(GLFWwindow* windowHandle, GLdouble xOffset, GLdouble yOffset);
		static void windowFocusCallback(GLFWwindow* windowHandle, GLint isFocused);
		static void windowPositionCallback(GLFWwindow* windowHandle, GLint xPosition, GLint yPosition);
		static void windowSizeCallback(GLFWwindow* windowHandle, GLint windowWidth, GLint windowHeight);

		GLint mWidth;
		GLint mHeight;

		GLFWwindow *mWindowHandle;

		Window();

		void initWindowCallbacks() const;
		void initWindowHints() const;
		void initWindowSize();
	};
}

#endif