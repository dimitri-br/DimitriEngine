#pragma once

#include "OpenGLRenderer.h";
#include "../backend.h"
#include "../Transform/Transform.h"
#include <vector>

// OpenGL math library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using Rendering::BackEndType;
using DimitriEngine::Transform;

namespace OpenGL {
	// Object class. This class controls all things to do with objects, including the model, transformation, textures and more!
	class Object
	{

	public:

		Transform transform;

		Object();

		void Initialize(OpenGLRenderer _openGLRenderer, Rendering::BackEndType _type);

		// Function to build the object by allocating the buffers and arrays
		void BuildObject();

		// Function to bind a vertex buffer to the object
		void BindVerticies(std::vector<float> verticesVec);

		// Function to bind an index vector to the object
		void BindIndicies(std::vector<unsigned int> indicesVec, bool useIndexBuffer);

		// Texture loader and binder
		void BindTexture(std::string TexturePath);

		// Function to draw this object to the display
		void Draw();

		void Exit();

	private:
		unsigned int VBO; // Vertex buffer object
		unsigned int VAO; // Vertex array object - just a pointer really to VBO
		unsigned int EBO; // Index buffer object

		unsigned int AlbedoTexture; // Albedo texture

		bool UseIndexBuffer;

		BackEndType type; // Type of renderer
		OpenGLRenderer openGLRenderer; // Link to OpenGL renderer

		std::vector<float> vertices; // vertex vector
		std::vector<unsigned int> indices; // index vector
		
	};
}


