#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

namespace DimitriEngine {
	// Controls the transform of every object and camera
	class Transform
	{
	private:
		void UpdateLocalVars();
		glm::mat4 transform;

	public:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		// Constructor for Transform
		Transform(glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));
		
		glm::mat4 GetTransform();

		void Translate(glm::vec3 offset);

		void Rotate(float angle, glm::vec3 axis);
	};

}

