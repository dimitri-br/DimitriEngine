#pragma once
#include "../window.h"
#include "../OpenGL/shader.h"


namespace DimitriEngine {
	struct Texture {
		Texture(std::string path, std::string name);

		Texture();

		void BindTexture(OpenGL::Shader shader, int pos);

		unsigned int texture;
		std::string path;
		std::string name;

		bool textureIsLoaded = false;

		void LoadImageFromFile(std::string& path); // Load an image, allocate it and return it.

	};
}