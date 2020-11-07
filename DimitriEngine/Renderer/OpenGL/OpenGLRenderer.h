#pragma once
#include "window.h"
#include "shader.h"

namespace OpenGL {
	class OpenGLRenderer {
	public:
		// Initialize the renderer
		void init();

		// Update the renderer - including windows, shaders etc
		void Update();

		//Safely exit
		void Exit();


		unsigned int GetShaderProgram();
		Window GetWindow();



	private:
		// Create a new window
		void CreateWindow();
		void CreateShaders();



		// These should not be exposed in any way to the user
		Shader shader;
		// Attached window object
		Window window;
	};
}