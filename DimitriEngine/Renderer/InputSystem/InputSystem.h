#pragma once
#include "../window.h"
#include <glm/glm.hpp>

using Rendering::Window;

namespace DimitriEngine {
	class InputSystem
	{
	public:
		// Pointer to window so we can read input events
		Window window;

		InputSystem();

		// This function just checks whether or not we should exit
		void ProcessInputs();
		
		// Sets the window pointer
		void SetWindow(Window windowContext);

		// Function to globally read a keys value
		bool GetKeyDown(int KeyCode);

		glm::vec2 GetMouseInput();

		glm::vec2 MouseInput;
	};
}


