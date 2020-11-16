#pragma once

#include "BackEndType.h"
#include "OpenGL/OpenGLRenderer.h"
#include "InputSystem/InputSystem.h"
#include "OpenGL/object.h"
#include "OpenGL/projection.h"
#include "Camera/Camera.h"
#include "Timing/Time.h"

#include <chrono>


using OpenGL::OpenGLRenderer;

// namespace Rendering holds all render processes that are global to every renderer
namespace Rendering {

	// BackEnd holds vital information to not only share information between the engine and renderer, but also
	// controls the render process
	class BackEnd
	{
	public:

		BackEnd();

		float DeltaTime;

		BackEndType backEndType;

		OpenGLRenderer openGLRenderer;

		DimitriEngine::InputSystem inputSystem;
		DimitriEngine::Camera camera;

		// Create a new instance of a backend, using the type specified in the constructor

		// Loop until exit
		void MainLoop();

		void Initialize(BackEndType _backEndType);

	private:
		// Setup the backend renderer and windowing
		void SetupGraphics();

		// Setup the input system
		void SetupInputSystem();
	};
}

