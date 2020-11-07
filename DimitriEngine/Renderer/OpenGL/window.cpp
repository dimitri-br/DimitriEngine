#include "window.h"

using OpenGL::Window;


void Window::SetupWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(800, 600, "DimitriEngine - OpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		throw std::exception("Error creating GLFW window. Please make sure your video card supports OpenGL 3.3");
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// We have to load GLAD before any OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::exception("Error initializing GLAD. Please make sure your video card supports OpenGL 3.3");
	}
}

void Window::SwapWindowBuffers() {
	glfwSwapBuffers(window);
}

GLFWwindow* Window::GetWindow() {
	return window;
}

int Window::CheckKey(int keycode) {
	return glfwGetKey(window, keycode);
}
void Window::Exit() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::CheckClose() {
	return glfwWindowShouldClose(window);
}

void Window::CloseWindow(bool value) {
	glfwSetWindowShouldClose(window, value);
}

void Window::SetClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}