#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/glm.hpp>
#include <vector>
#include "../Texture/Texture.h"
#include "../Material/Material.h"
#include "../OpenGL/projection.h"
#include "../Transform/Transform.h"
#include "../Camera/Camera.h"
#include "../Light/Light.h"

using OpenGL::Projection;
using DimitriEngine::Transform;
using namespace std;

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
		Mesh();
		Mesh(vector<Vertex> vertices, vector<unsigned int> indices, Material material);
		void Draw(Transform transform, Camera* cam, std::vector<Light> lights, Projection* proj);
		void Exit();

	private:
		//  render data
		unsigned int VAO, VBO, EBO;

		void setupMesh();
	};
}


