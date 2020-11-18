#include "OpenGLRenderer.h"
#include "../Timing/Time.h"

using DimitriEngine::Time;


OpenGL::OpenGLRenderer::OpenGLRenderer()
{
}

void OpenGL::OpenGLRenderer::Initialize() {
	CreateWindow();
	CreateShaders();
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

void OpenGL::OpenGLRenderer::CreateShaders() 
{
	shader = Shader();
	shader.LoadShader("./Shaders/shader.vert", "./Shaders/shader.frag");
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

OpenGL::Shader OpenGL::OpenGLRenderer::GetShader() {
	return shader;
}

Rendering::Window OpenGL::OpenGLRenderer::GetWindow() {
	return window;
}



