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

		void SetupShadowBuffer();

		void DrawShadowMap();

		void ApplyShadowMap();

		void Exit() {
			// Cleanup
			glDeleteBuffers(1, &quadVBO);
			glDeleteVertexArrays(1, &quadVAO);
			shader.Exit();
			glDeleteTextures(1, &framebuffer);
			glDeleteTextures(1, &textureColorbuffer);
			glDeleteTextures(1, &colorBuffers[1]);
			glDeleteTextures(1, &colorBuffers[0]);
			glDeleteTextures(1, &rbo);
		}

	private:
		
		void SetupQuad();
		void SetupFramebuffers();


		Shader shader;
		Shader shaderBlur;
		Shader shaderBloom;

		float quadVertices[20] = {
			// positions        // texture Coords
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};
		unsigned int quadVAO, quadVBO;


		unsigned int framebuffer;
		unsigned int textureColorbuffer;

		unsigned int rbo;

		unsigned int colorBuffers[2];

		unsigned int pingpongFBO[2];
		unsigned int pingpongBuffers[2];

		unsigned int depthMapFBO;
		unsigned int depthMap;


		
	};
}

