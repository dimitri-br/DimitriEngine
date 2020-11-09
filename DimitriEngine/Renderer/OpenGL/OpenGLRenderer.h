#pragma once
#include "window.h"
#include "shader.h"

namespace OpenGL {
	class OpenGLRenderer {
	public:
		// Initialize the renderer
		void init();

		void SetDefaults();

		// Update the renderer - including windows, shaders etc
		void Update();

		//Safely exit
		void Exit();


		unsigned int GetShaderProgram();
		Window GetWindow();

		// These should not be exposed in any way to the user
		Shader shader;

	private:
		// Create a new window
		void CreateWindow();
		void CreateShaders();




		// Attached window object
		Window window;
	};
}