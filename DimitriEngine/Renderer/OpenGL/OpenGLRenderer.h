#pragma once
#include "../window.h"
#include "shader.h"
#include "../BackEndType.h"

using Rendering::BackEndType;

namespace OpenGL {
	static void error_callback(int error, const char* description)
	{
		fprintf(stderr, "Error: %s\n", description);
	}

	class OpenGLRenderer {
	public:

		OpenGLRenderer();


		// Initialize the renderer

		void Initialize();

		void SetDefaults();

		// Update the renderer - including windows, shaders etc
		void Update();

		//Safely exit
		void Exit();


		unsigned int GetShaderProgram();
		OpenGL::Shader GetShader();
		Rendering::Window GetWindow();



	private:
		// Create a new window
		void CreateWindow();
		void CreateShaders();




		// Attached window object
		Rendering::Window window;

		// These should not be exposed in any way to the user
		Shader shader;
	};
}