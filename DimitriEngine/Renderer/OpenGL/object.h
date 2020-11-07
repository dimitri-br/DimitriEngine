#pragma once
#include "OpenGLRenderer.h";
#include "../backend.h"
#include <vector>
using Rendering::BackEndType;

namespace OpenGL {
	class Object
	{

	public:
		// Constructor method
		Object(OpenGLRenderer openGLRenderer, BackEndType type);

		// Function to build the object by allocating the buffers and arrays
		void BuildObject();

		// Function to bind a vertex buffer to the object
		void BindVerticies(std::vector<float> verticesVec);

		// Function to bind an index vector to the object
		void BindIndicies(std::vector<int> indiciesVec);

		// Function to draw this object to the display
		void Draw();

		void Exit();

	private:
		unsigned int VBO; // Vertex buffer object
		unsigned int VAO; // Vertex array object - just a pointer really to VBO
		unsigned int EBO; // Index buffer object

		BackEndType type; // Type of renderer
		OpenGLRenderer openGLRenderer; // Link to OpenGL renderer

		std::vector<float> vertices; // vertex vector
		std::vector<int> indices; // index vector
	};
}


