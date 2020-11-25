#include "backend.h"
using Rendering::BackEnd;
using Rendering::BackEndType;
using DimitriEngine::Time;

// Initialize the time singleton (Stores the deltatime information and more timing info (will also store physics info)
Time::Time() {}

void BackEnd::Initialize(BackEndType _backEndType){

	backEndType = _backEndType;

	camera = DimitriEngine::Camera();
	camera.SetCamTransform(glm::vec3(0, 0, 20));

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
	OpenGL::Projection projection = openGLRenderer.GetProjection();
	std::vector<DimitriEngine::Light> lights;
	std::vector<DimitriEngine::Object> objs;

	
	DimitriEngine::Light light = DimitriEngine::Light();
	light.direction = glm::vec3(-0.0f, -1.0f, -0.3f);
	light.ambient = glm::vec3(0.1f);
	light.diffuse = glm::vec3(0.8f);
	light.specular = glm::vec3(1.0f);
	light.lightType = LIGHT_DIRECTIONAL;
	lights.push_back(light);


	glm::vec3 pointLightPositions[] = {
		glm::vec3(0.7f,  -0.5f,  5.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  -2.0f, -12.0f),
		glm::vec3(0.0f,  -6.0f, -3.0f)
	};

	std::vector<glm::vec3> objPositions = {
	glm::vec3(1.0f,  0.5f,  5.0f),
	glm::vec3(2.3f, 2.0f, -4.0f),
	glm::vec3(-4.0f,  2.0f, -5.0f),
	glm::vec3(0.25f,  0.0f, -3.0f)
	};

	for (glm::vec3 pos : pointLightPositions) {
		DimitriEngine::Light p_light;
		p_light.position = pos;
		
		p_light.ambient = glm::vec3(0.1f);
		p_light.diffuse = glm::vec3(1.0f);
		p_light.specular = glm::vec3(1.0f);

		p_light.constant = 1.0f;
		p_light.linear = 0.09f;
		p_light.quadratic = 0.032f;

		light.lightType = LIGHT_POINT;

		lights.push_back(p_light);
	}

	/*for (glm::vec3 pos : objPositions) {
		DimitriEngine::Object obj;
		obj.transform.position = pos;
		obj.transform.rotation = glm::vec3(1, 0, 0);
		obj.transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);

		Material mat;
		//mat.color = glm::vec3(1.0, 1.0, 1.0);
		//mat.smoothness = 32.0f;
		obj.CreateModel("./Models/backpack/backpack.obj", mat);

		objs.push_back(obj);
	}*/
	DimitriEngine::Object obj;
	obj.transform.position = glm::vec3(0);
	obj.transform.rotation = glm::vec3(1, 0, 0);
	obj.transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);

	Material mat;
	//mat.color = glm::vec3(1.0, 1.0, 1.0);
	//mat.smoothness = 32.0f;
	obj.CreateModel("./Models/backpack/backpack.obj", mat);


	openGLRenderer.GetWindow().SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);


	OpenGL::PostProcessing pps;
	

	while (!openGLRenderer.GetWindow().CheckClose()) {


		// Now draw the scene

		float nowTime = glfwGetTime();

		pps.PreRender();

		openGLRenderer.Update();
		openGLRenderer.GetWindow().SetClearColor(0.1, 0.1, 0.1, 1);
		inputSystem.SetWindow(openGLRenderer.GetWindow());
		inputSystem.ProcessInputs();
		camera.HandleInput(inputSystem);
		camera.Update();
		projection.SetRawView(camera.CamView);
		
		//for (DimitriEngine::Object obj : objs) {

		//	obj.Update(&camera, lights, &projection);
		//}
		obj.Update(&camera, lights, &projection);

		glfwPollEvents();

		// Calculate deltatime - time taken per frame
		
		float endTime = glfwGetTime();

		DeltaTime = endTime - nowTime;

		Time::GetInstance()->deltaTime = DeltaTime;

		

		pps.Draw();

		openGLRenderer.SwapBuffers();
	}

	for (DimitriEngine::Object obj : objs) {

		obj.Exit();
	}
}
