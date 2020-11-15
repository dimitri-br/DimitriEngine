#include "InputSystem.h"

DimitriEngine::InputSystem::InputSystem()
{
}

void DimitriEngine::InputSystem::ProcessInputs()
{
	if (GetKeyDown(GLFW_KEY_ESCAPE))
		window.CloseWindow(true);
	
	MouseInput = window.GetMousePos();
	std::cout << "Got mouse input (inputsystem)! X: " << MouseInput.x << " Y: " << MouseInput.y << std::endl;
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
