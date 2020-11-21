#pragma once
#include "../Mesh/Mesh.h"
#include "../OpenGL/projection.h"
#include "../Transform/Transform.h"

using OpenGL::Projection;

namespace DimitriEngine {
	class Model
	{
	public:
		Model() {
		};

		Model(std::string path, Material material) {
			this->path = path;
			this->material = material;
			loadModel();
		}
		void Draw(Transform transform, std::vector<Light> lights, Camera* cam, Projection* projection);

		void Exit();


		Material material; // global material to apply

	private:
		vector<Mesh> meshes;
		std::string path;
		std::string directory;
		vector<Texture> textures_loaded;

		void loadModel();
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
			string typeName);
	};
}


