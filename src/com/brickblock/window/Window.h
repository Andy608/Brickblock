#ifndef BB_WINDOW_H_
#define BB_WINDOW_H_

#include <string>
#include <GLFW\glfw3.h>

namespace bb
{
	class Window
	{
	public:
		const GLFWvidmode* mVIDEO_MODE;
		const std::string mTITLE;
		
		Window();
		~Window();

		GLFWwindow* getWindowHandle() const;

	private:
		static const GLFWvidmode* init();
		static const std::string initRandomizedTitle();

		int mWidth;
		int mHeight;

		GLFWwindow* mWindowHandle;

		void initWindowHints() const;
		void initWindowSize();
	};
}

#endif