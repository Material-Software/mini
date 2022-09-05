#include <GLFW/glfw3.h>

extern GLFWwindow* window;

struct Events
{
	bool closeButton = false;
	bool mouseLeft = false;
	bool mouseRight = false;
};
Events events;


void vxPollEvent()
{
	events.closeButton = glfwWindowShouldClose(window);
	glfwPollEvents();
}

bool vxShouldClose()
{
	return events.closeButton;
}

bool vxMouseLeftClick()
{
	return events.mouseLeft;
}
bool vxMouseRightClick()
{
	return events.mouseRight;
}
