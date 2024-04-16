#include "pch.h"
#include "Window.h"

float Window::width = 1920.f;
float Window::height = 1080.f;

GLFWwindow* Window::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;

	window = glfwCreateWindow(width, height, "GLEngine", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to initialize window\n";
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to load GLAD" << "\n";
	}
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	
	//glfwSetFramebufferSizeCallback(window, input::framebuffer)

	return window;


}
