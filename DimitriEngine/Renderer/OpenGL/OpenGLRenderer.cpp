#include "OpenGLRenderer.h"

void OpenGL::OpenGLRenderer::Initialize() {
	CreateWindow();
	CreateShaders();
	SetDefaults();
}

void OpenGL::OpenGLRenderer::SetDefaults() {
	glEnable(GL_DEPTH_TEST);
}

void OpenGL::OpenGLRenderer::CreateWindow()
{
	window = Rendering::Window(BackEndType::OpenGL);
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

Rendering::Window OpenGL::OpenGLRenderer::GetWindow() {
	return window;
}
