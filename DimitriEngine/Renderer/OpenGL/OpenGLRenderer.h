#pragma once
#include "../window.h"
#include "shader.h"
#include "../BackEndType.h"
#include "../Camera/Camera.h"
#include "projection.h"


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

		void SwapBuffers();

		//Safely exit
		void Exit();

		Rendering::Window GetWindow();
		OpenGL::Projection GetProjection();
		DimitriEngine::Camera GetCamera();

	private:
		// Create a new window
		void CreateWindow();




		// Attached window object
		Rendering::Window window;


		Projection projection;

		DimitriEngine::Camera camera;
	};
}