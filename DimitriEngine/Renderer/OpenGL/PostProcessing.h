#pragma once
#include "../window.h"
#include "shader.h"


namespace OpenGL {
	class PostProcessing
	{
	public:
		PostProcessing();

		void PreRender();

		void Draw();


		void Exit() {
			// Cleanup
			glDeleteBuffers(1, &quadVBO);
			glDeleteVertexArrays(1, &quadVAO);
			shader.Exit();
			glDeleteTextures(1, &framebuffer);
			glDeleteTextures(1, &textureColorbuffer);
			glDeleteTextures(1, &intermediateFBO);
			glDeleteTextures(1, &screenTexture);
			glDeleteTextures(1, &rbo);
		}

	private:
		
		void SetupQuad();
		void SetupFramebuffers();

		Shader shader;

		float quadVertices[24] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
// positions   // texCoords
-1.0f,  1.0f,  0.0f, 1.0f,
-1.0f, -1.0f,  0.0f, 0.0f,
 1.0f, -1.0f,  1.0f, 0.0f,

-1.0f,  1.0f,  0.0f, 1.0f,
 1.0f, -1.0f,  1.0f, 0.0f,
 1.0f,  1.0f,  1.0f, 1.0f
		};
		unsigned int quadVAO, quadVBO;


		unsigned int framebuffer;
		unsigned int textureColorbuffer;

		unsigned int rbo;

		unsigned int intermediateFBO;
		unsigned int screenTexture;


		
	};
}

