#include "backend.h"
using Rendering::BackEnd;
using Rendering::BackEndType;
using DimitriEngine::Time;

// Initialize the time singleton (Stores the deltatime information and more timing info (will also store physics info)
Time::Time() {}

void BackEnd::Initialize(BackEndType _backEndType){

	backEndType = _backEndType;

	camera = DimitriEngine::Camera();
	camera.SetCamTransform(glm::vec3(0, 0, 10));

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
		openGLRenderer.Initialize();
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

Rendering::BackEnd::BackEnd()
{
}

void BackEnd::MainLoop() {
	OpenGL::Projection projection;
	projection.Initialize(openGLRenderer);

	DimitriEngine::Object obj(openGLRenderer, backEndType);
	DimitriEngine::Light(Transform(glm::vec3(10, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1.0f)));

	

	std::vector<float> vertices = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	std::vector<unsigned int> indices = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};



	obj.BindVerticies(vertices);
	obj.BindIndicies(indices, false);
	obj.BindTexture("./Textures/container.jpg");
	obj.BuildObject();

	obj.transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	obj.transform.rotation = glm::vec3(0, 0, 0);
	obj.transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);

	openGLRenderer.GetWindow().SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!openGLRenderer.GetWindow().CheckClose()) {
		float nowTime = glfwGetTime();



		openGLRenderer.Update();
		inputSystem.SetWindow(openGLRenderer.GetWindow());
		inputSystem.ProcessInputs();
		camera.HandleInput(inputSystem);
		camera.Update();
		projection.SetRawView(camera.CamView);

		obj.Draw();

		glfwPollEvents();

		// Calculate deltatime - time taken per frame
		
		float endTime = glfwGetTime();

		DeltaTime = endTime - nowTime;

		Time::GetInstance()->deltaTime = DeltaTime;
	}

	obj.Exit();
}
