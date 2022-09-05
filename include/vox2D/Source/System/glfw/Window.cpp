#include "vox2D/Window.h"
#include <GLFW/glfw3.h>

GLFWwindow* window = nullptr;

void vxInit(int width, int height, const char* title)
{
	glfwInit();
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(window);
}

void vxTerminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void vxSetWindowTitle(const char* title)
{
	glfwSetWindowTitle(window, title);
}

void vxSwapBuffer()
{
	glfwSwapBuffers(window);
}

void vxGetWindowWidth(int& width, int& height)
{
	glfwGetWindowSize(window, &width, &height);
}
