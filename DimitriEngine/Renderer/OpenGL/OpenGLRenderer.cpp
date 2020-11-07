#include "OpenGLRenderer.h"

void OpenGL::OpenGLRenderer::init()
{
	CreateWindow();
}

void OpenGL::OpenGLRenderer::CreateWindow()
{
	window = Window();

	window.SetupWindow();
}

void OpenGL::OpenGLRenderer::Update() {
	window.SwapWindowBuffers();
}

void OpenGL::OpenGLRenderer::Exit() {
	window.Exit();
}
