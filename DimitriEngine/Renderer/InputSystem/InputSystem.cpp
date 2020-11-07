#include "InputSystem.h"

void Rendering::InputSystem::ProcessInputs()
{
	if (GetKeyDown(GLFW_KEY_ESCAPE))
		window.CloseWindow(true);
}

bool Rendering::InputSystem::GetKeyDown(int KeyCode) {

	if (window.CheckKey(KeyCode) == GLFW_PRESS)
		return true;
	else
		return false;
}

void Rendering::InputSystem::SetWindow(Window windowContext) {
	window = windowContext;
}
