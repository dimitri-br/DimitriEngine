#pragma once

#include "../OpenGL/OpenGLRenderer.h";
#include "../backend.h"
#include "../Mesh/Mesh.h"
#include "../Model/Model.h"
#include "../Transform/Transform.h"
#include "../Material/Material.h"
#include "../Texture/Texture.h"
#include "../Camera/Camera.h"
#include <vector>

// OpenGL math library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



using Rendering::BackEndType;
using DimitriEngine::Transform;
using DimitriEngine::Material;
using OpenGL::OpenGLRenderer;

namespace DimitriEngine {
	// Object class. This class controls all things to do with objects, including the model, transformation, textures and more!
	class Object
	{

	public:

		Transform transform;
		Model model;

		Object();
		Object(OpenGLRenderer _openGLRenderer, Rendering::BackEndType _type);

		// Function to build the object by allocating the buffers and arrays
		void CreateModel(std::string path, Material modelMaterial);

		void Update(Camera* cam, std::vector<Light> lights, Projection* projection);

		void Exit();

	private:
		BackEndType type; // Type of renderer
		OpenGLRenderer openGLRenderer; // Link to OpenGL renderer		
	};
}


