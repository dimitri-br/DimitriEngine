#pragma once
#include "../Texture/Texture.h"
#include "../OpenGL/shader.h"
#include <vector>


using OpenGL::Shader;

namespace DimitriEngine {
	class Material
	{
	public:
		Material();
		Material(std::vector<Texture> _textures);
		Material(std::vector<Texture> _textures, glm::vec3 _color);
		Material(std::vector<Texture> _textures, float smoothness, float metallic);
		Material(std::vector<Texture> _textures, glm::vec3 _color, float smoothness, float metallic);


		std::vector<Texture> textures;

		glm::vec3 color = glm::vec3(1.0f);

		float smoothness = 0.5f;
		float metallic = 0.5f;

		Shader shader; // Attached shader to this material
	private:
		

		unsigned int LoadImage(std::string& path, unsigned int texture); // Load an image, allocate it and return it.



	};
}


