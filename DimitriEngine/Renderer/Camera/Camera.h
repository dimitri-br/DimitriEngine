#pragma once
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm\ext\matrix_transform.hpp>
#include "../InputSystem/InputSystem.h"
#include "../Timing/Time.h"


namespace DimitriEngine {
	class Camera
	{
	public:
		Camera();

		void SetCamTransform(glm::vec3 position);
		void Update();
		void HandleInput(InputSystem inputSystem);


		glm::mat4 CamView;

	private:
		glm::vec3 CamPosition;
		glm::vec3 CamDirection;

		glm::vec3 CamUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 CamFront = glm::vec3(0.0f, 0.0f, -1.0f);

		float lastX = 400;
		float lastY = 300;
		float xPos;
		float yPos;
		
		float yaw = -90.0f;
		float pitch;

		bool firstMouse = true;

		float sensitivity = 0.1f;
	};
}


