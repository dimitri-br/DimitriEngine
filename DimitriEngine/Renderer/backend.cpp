#include "backend.h"
using Rendering::BackEnd;
using Rendering::BackEndType;

BackEnd::BackEnd(BackEndType backEndType) {
	switch (backEndType) {
	case BackEndType::OpenGL:
		std::cout << "BACKEND: Using OpenGL" << std::endl;
		break;

	case BackEndType::Vulkan:
		std::cout << "BACKEND: Using Vulkan" << std::endl;
		break;

	case BackEndType::DirectX:
		std::cout << "BACKEND: Using DirectX" << std::endl;
		break;

	default:
		std::cout << "BACKEND: Using OpenGL" << std::endl;
		break;
	};

	SetupGraphics();
	SetupInputSystem();
}

void BackEnd::SetupGraphics()
{
	// Setup windowing and any necessary graphics pipelines for the backends
	switch (backEndType) {

	case BackEndType::Vulkan:
		std::cout << "Setting up Vulkan Window" << std::endl;
		break;

	case BackEndType::DirectX:
		std::cout << "Setting up DirectX Window" << std::endl;
		break;

	default:
		std::cout << "Setting up OpenGL Window" << std::endl;
		openGLRenderer.init();
		break;
	};
}

void BackEnd::SetupInputSystem() {
	// setup the input system 
	std::cout << "Setting up Input System" << std::endl;
	inputSystem.SetWindow(&openGLRenderer.window);
}

void BackEnd::MainLoop() {
	while (!openGLRenderer.window.CheckClose()) {
		openGLRenderer.window.SetClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		inputSystem.ProcessInputs();
		openGLRenderer.Update();
		glfwPollEvents();
	}
}
