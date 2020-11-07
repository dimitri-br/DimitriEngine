#pragma once
#include "window.h"

namespace OpenGL {
	class OpenGLRenderer {
	public:
		// Attached window object
		Window window;

		// Initialize the renderer
		void init();

		// Update the renderer - including windows, shaders etc
		void Update();

		//Safely exit
		void Exit();
	private:
		// Create a new window
		void CreateWindow();
	};
}