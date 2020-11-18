#include "object.h"


DimitriEngine::Object::Object()
{
}

DimitriEngine::Object::Object(OpenGLRenderer _openGLRenderer, Rendering::BackEndType _type)
{
	openGLRenderer = _openGLRenderer;
	type = _type;
}


void DimitriEngine::Object::BuildObject()
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------

	// Create buffers and vertex arrays
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	// 1. bind Vertex Array Object
	glBindVertexArray(VAO);

	// 2. copy our vertices array in a vertex buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices), &vertices.front(), GL_STATIC_DRAW);

	// 3. copy our index array in a element buffer for OpenGL to use
	if (UseIndexBuffer) {
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices), &indices.front(), GL_STATIC_DRAW);
	}


	// 4. then set the vertex attributes pointers

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	material = Material("./textures/container.jpg", "./textures/container.jpg", glm::vec3(0.25f));
}


void DimitriEngine::Object::BindVerticies(std::vector<float> verticesVec)
{
	vertices = verticesVec;
}


void DimitriEngine::Object::BindIndicies(std::vector<unsigned int> indicesVec, bool useIndexBuffer)
{
	UseIndexBuffer = useIndexBuffer;
	indices = indicesVec;
}


void DimitriEngine::Object::Draw()
{
	

	switch (type) {
	case Rendering::BackEndType::OpenGL:
	{
		// Send transform buffer as a uniform to the shader
		openGLRenderer.GetShader().UseShader();

		openGLRenderer.GetShader().BindMat4("transform", transform.GetTransform());

		openGLRenderer.GetShader().BindVec3("color", material.color);

		//glBindTexture(GL_TEXTURE_2D, AlbedoTexture);
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		
		if (UseIndexBuffer) {
			glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0); // Draw the vertex using the EBO - element buffer
		}
		else {
			glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		}

		glBindVertexArray(0); // no need to unbind it every time - but good to avoid overwriting
		break;
	}
	default:
		std::cout << "NO RENDER BACKEND SELECTED!";
		break;
	}

}

void DimitriEngine::Object::Exit()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

