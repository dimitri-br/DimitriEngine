#pragma once
#include "../window.h"

using Rendering::Window;

namespace Rendering {
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
	};
}


