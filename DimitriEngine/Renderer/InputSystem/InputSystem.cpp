#include "InputSystem.h"

DimitriEngine::InputSystem::InputSystem()
{
}

void DimitriEngine::InputSystem::ProcessInputs()
{
	if (GetKeyDown(GLFW_KEY_ESCAPE))
		window.CloseWindow(true);
	
	MouseInput = window.GetMousePos();
}

bool DimitriEngine::InputSystem::GetKeyDown(int KeyCode) {

	if (window.CheckKey(KeyCode) == GLFW_PRESS)
		return true;
	else
		return false;
}

glm::vec2 DimitriEngine::InputSystem::GetMouseInput()
{
	return MouseInput;
}



void DimitriEngine::InputSystem::SetWindow(Window windowContext) {
	window = windowContext;
}
