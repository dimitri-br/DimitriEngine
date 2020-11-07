#include "backend.h"
using Rendering::BackEnd;
using Rendering::BackEndType;


BackEnd::BackEnd(BackEndType backEndType) {
	switch (backEndType) {
	case BackEndType::OpenGL:
		std::cout << "BACKEND: Using OpenGL" << std::endl;
		break;

	case BackEndType::Vulkan:
		std::cout << "BACKEND: Using Vulkan. Vulkan is not supported - the engine will default to OpenGL" << std::endl;
		backEndType = BackEndType::OpenGL;
		break;

	case BackEndType::DirectX:
		std::cout << "BACKEND: Using DirectX. DirectX is not supported - the engine will default to OpenGL" << std::endl;
		backEndType = BackEndType::OpenGL;
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
	std::cout << "Set up Window correctly" << std::endl;

}

void BackEnd::SetupInputSystem() {
	// setup the input system 
	std::cout << "Setting up Input System" << std::endl;
	switch (backEndType) {

	case BackEndType::Vulkan:
		break;

	case BackEndType::DirectX:
		break;

	default:

		inputSystem.SetWindow(openGLRenderer.GetWindow());
		break;
	};
	std::cout << "Set up Input System sucessfully" << std::endl;


}

void BackEnd::MainLoop() {
	OpenGL::Object obj = OpenGL::Object(openGLRenderer, backEndType);
	std::vector<float> verticies = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<int> indices = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	obj.BindVerticies(verticies);
	obj.BindIndicies(indices);
	obj.BuildObject();
	openGLRenderer.GetWindow().SetClearColor(0.1f, 0.5f, 0.5f, 1.0f);

	while (!openGLRenderer.GetWindow().CheckClose()) {
		
		openGLRenderer.Update();

		obj.Draw();

		inputSystem.ProcessInputs();

		glfwPollEvents();
	}

	obj.Exit();
}
