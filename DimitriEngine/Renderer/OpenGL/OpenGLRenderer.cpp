#include "OpenGLRenderer.h"


void OpenGL::OpenGLRenderer::init()
{
	CreateWindow();
	CreateShaders();
}

void OpenGL::OpenGLRenderer::CreateWindow()
{
	window = Window();

	window.SetupWindow();
}

void OpenGL::OpenGLRenderer::CreateShaders() 
{
	shader = Shader();
	shader.LoadShader("Placeholder Vert", "Placeholder Frag");
	shader.GenerateShader();
}

void OpenGL::OpenGLRenderer::Update() {
	window.SwapWindowBuffers();
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader.ShaderProgram);

}

void OpenGL::OpenGLRenderer::Exit() {
	window.Exit();
	shader.Exit();
}

unsigned int OpenGL::OpenGLRenderer::GetShaderProgram(){
	return shader.ShaderProgram;
}

OpenGL::Window OpenGL::OpenGLRenderer::GetWindow() {
	return window;
}
