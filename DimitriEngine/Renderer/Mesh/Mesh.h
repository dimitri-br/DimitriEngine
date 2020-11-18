#pragma once
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <vector>

#include "../Texture/Texture.h"

namespace DimitriEngine {
	// Defines a vertex - stores pos, norm and tex.
	struct Vertex {
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	// mesh class - stores vertex and materials, used by objects
	class Mesh
	{
	public:
		// mesh data
		std::vector<Vertex>       vertices;
		std::vector<unsigned int> indices;
		Material				  material;

	private:
		//  render data
		unsigned int VAO, VBO, EBO;

		void setupMesh();
	};
}


