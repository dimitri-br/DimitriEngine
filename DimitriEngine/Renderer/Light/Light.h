#pragma once
#include "../transform/transform.h"
#include "../OpenGL/shader.h"
#define LIGHT_DIRECTIONAL 1
#define LIGHT_POINT 2
#define LIGHT_SPOTLIGHT 3


namespace DimitriEngine {
	class Light
	{
	public:
		Transform transform;


		Light(); // Constructor with default values
		Light(Transform _transform); // Constructor with user-defined transform

		glm::vec3 direction;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;

		// only for point lights
		glm::vec3 position;
		float constant;
		float linear;
		float quadratic;

		int lightType;
		void DrawLight(OpenGL::Shader shader, int lightID);
		void DrawDirectional(OpenGL::Shader shader);
		void DrawPoint(OpenGL::Shader shader, int lightID);
	private:

	};
}


