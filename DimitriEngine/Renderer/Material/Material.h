#pragma once
#include "../OpenGL/shader.h"
#include "../Texture/Texture.h"
#include <vector>


using OpenGL::Shader;

namespace DimitriEngine {
	class Material
	{
	public:
		Material();

		Material(std::vector<Texture> _textures, glm::vec3 _color);


		std::vector<Texture> textures;

		glm::vec3 color;

			
	private:
		Shader shader; // Attached shader to this material

		unsigned int LoadImage(std::string& path, unsigned int texture); // Load an image, allocate it and return it.



	};
}


