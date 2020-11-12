#pragma once
#include "../window.h"
#include "shader.h"
#include "../BackEndType.h"

using Rendering::BackEndType;

namespace OpenGL {
	class OpenGLRenderer {
	public:
		// Initialize the renderer

		void Initialize();

		void SetDefaults();

		// Update the renderer - including windows, shaders etc
		void Update();

		//Safely exit
		void Exit();


		unsigned int GetShaderProgram();
		Rendering::Window GetWindow();

		// These should not be exposed in any way to the user
		Shader shader;

	private:
		// Create a new window
		void CreateWindow();
		void CreateShaders();




		// Attached window object
		Rendering::Window window;
	};
}