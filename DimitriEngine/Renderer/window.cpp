#include "window.h"

using Rendering::Window;


Rendering::Window::Window()
{

}

void Rendering::Window::LoadOpenGL(){
	glfwInit();
	backEndType = BackEndType::OpenGL;
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
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetWindowUserPointer(window, this); // set a pointer to this class so we can use it in static functions where we pass a window

	// We have to load GLAD before any OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::exception("Error initializing GLAD. Please make sure your video card supports OpenGL 3.3");
	}
}

void Rendering::Window::LoadVulkan() {

}

void Rendering::Window::SwapWindowBuffers() {
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLFWwindow* Rendering::Window::GetWindow() {
	return window;
}

int Rendering::Window::CheckKey(int keycode) {
	return glfwGetKey(window, keycode);
}
void Rendering::Window::Exit() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

glm::vec2 Rendering::Window::GetMousePos()
{
	return MousePos;
}

void Rendering::Window::mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	MousePos = glm::vec2(xpos, ypos);
}

bool Rendering::Window::CheckClose() {
	return glfwWindowShouldClose(window);
}

void Rendering::Window::CloseWindow(bool value) {
	glfwSetWindowShouldClose(window, value);
}

void Rendering::Window::SetClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Rendering::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* app = (Window*)glfwGetWindowUserPointer(window);
	app->mouseCallback(window, xpos, ypos);
}

