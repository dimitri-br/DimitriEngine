#include "OpenGLRenderer.h"


void OpenGL::OpenGLRenderer::init()
{
	CreateWindow();
	CreateShaders();

	SetDefaults();
}

void OpenGL::OpenGLRenderer::SetDefaults() {
	glEnable(GL_DEPTH_TEST);
}

void OpenGL::OpenGLRenderer::CreateWindow()
{
	window = Window();

	window.SetupWindow();
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

OpenGL::Window OpenGL::OpenGLRenderer::GetWindow() {
	return window;
}
