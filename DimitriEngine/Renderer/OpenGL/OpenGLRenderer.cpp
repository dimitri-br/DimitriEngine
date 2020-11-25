#include "OpenGLRenderer.h"
#include "../Timing/Time.h"

#define USE_MSAA true

using DimitriEngine::Time;


OpenGL::OpenGLRenderer::OpenGLRenderer()
{
}

void OpenGL::OpenGLRenderer::Initialize() {
	CreateWindow();
	SetDefaults();
	glfwSetErrorCallback(error_callback);
}

void OpenGL::OpenGLRenderer::SetDefaults() {
	glEnable(GL_DEPTH_TEST);
}

void OpenGL::OpenGLRenderer::CreateWindow()
{
	window.LoadOpenGL();
}


void OpenGL::OpenGLRenderer::Update() {
#if USE_MSAA
	glEnable(GL_MULTISAMPLE);
#endif // USE_MSAA

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void OpenGL::OpenGLRenderer::SwapBuffers() {
	window.SwapWindowBuffers();
}

void OpenGL::OpenGLRenderer::Exit() {
	window.Exit();
}


Rendering::Window OpenGL::OpenGLRenderer::GetWindow() {
	return window;
}

OpenGL::Projection OpenGL::OpenGLRenderer::GetProjection()
{
	return projection;
}

DimitriEngine::Camera OpenGL::OpenGLRenderer::GetCamera()
{
	return camera;
}



