#include "Camera.h"

DimitriEngine::Camera::Camera() {

}

void DimitriEngine::Camera::SetCamTransform(glm::vec3 position)
{
	CamPosition = position;

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	CamUp = glm::vec3(0.0f, 1.0f, 0.0f);

	CamView = glm::lookAt(CamPosition, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
}

void DimitriEngine::Camera::Update()
{
	CamView = glm::lookAt(CamPosition, CamPosition + CamFront, CamUp);
}

//Basic camera controller
void DimitriEngine::Camera::HandleInput(InputSystem inputSystem)
{
	const float cameraSpeed = 0.05f; // adjust accordingly
	if (inputSystem.GetKeyDown(GLFW_KEY_W)) {
		CamPosition += cameraSpeed * CamFront;
	}

	if (inputSystem.GetKeyDown(GLFW_KEY_S)) {
		CamPosition -= cameraSpeed * CamFront;
	}

	if (inputSystem.GetKeyDown(GLFW_KEY_A)) {
		CamPosition -= glm::normalize(glm::cross(CamFront, CamUp)) * cameraSpeed;
	}

	if (inputSystem.GetKeyDown(GLFW_KEY_D)) {
		CamPosition += glm::normalize(glm::cross(CamFront, CamUp)) * cameraSpeed;
	}

	// Mouse
    float xpos = inputSystem.GetMouseInput().x;
    float ypos = inputSystem.GetMouseInput().y;
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    CamFront = glm::normalize(direction);

}
