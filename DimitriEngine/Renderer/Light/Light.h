#pragma once
#include "../transform/transform.h"
#include "../OpenGL/shader.h"
#include "../OpenGL/projection.h"
#define LIGHT_DIRECTIONAL 0
#define LIGHT_POINT 1
#define LIGHT_SPOTLIGHT 2


namespace DimitriEngine {
	class Light
	{
	public:
		Transform transform;


		Light(); // Constructor with default values
		Light(int lightType, Transform transform, glm::vec3 lightColor, glm::vec3 lightObjectColor){
			this->lightType = lightType;
			this->transform = transform;
			this->lightColor = lightColor;
			this->lightObjectColor = lightObjectColor;
			SetupLightRenderer();
		}; // Constructor with user-defined transform

		glm::vec3 direction;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;

		glm::vec3 lightColor;
		glm::vec3 lightObjectColor;

		// only for point lights
		glm::vec3 position;
		float constant;
		float linear;
		float quadratic;

		int lightType = 0;
		int lightID = 0;
		void DrawLight(OpenGL::Shader shader, OpenGL::Projection* proj);

		void DrawRenderer(OpenGL::Projection* proj);

	private:
		void DrawPoint(OpenGL::Shader shader);

		void DrawDirectional(OpenGL::Shader shader);

		void SetupLightRenderer();


		OpenGL::Shader lightShader;

		unsigned int lightVAO, lightVBO;

	};
}


