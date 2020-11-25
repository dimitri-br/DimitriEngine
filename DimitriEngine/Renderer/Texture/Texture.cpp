#include "Texture.h"

#include "stb_image.h"

using OpenGL::Shader;

DimitriEngine::Texture::Texture(std::string path, std::string name)
{
	this->path = path;
	this->name = name;
	std::cout << "Loading texture: " << path << "\n\n";

}

DimitriEngine::Texture::Texture() {
	std::cout << "Please make sure to assign a texture path!" << std::endl;
}

void DimitriEngine::Texture::BindTexture(OpenGL::Shader shader, int pos) {
	glUniform1i(glGetUniformLocation(shader.ShaderProgram, (name).c_str()), pos);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void DimitriEngine::Texture::LoadImageFromFile(std::string& path)
{
	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &texture); // Create texture object

	glBindTexture(GL_TEXTURE_2D, texture); // Bind it
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load texture: " << path << " . Please ensure you have supplied a valid path" << std::endl;
	}
	stbi_image_free(data);

	textureIsLoaded = true;
}
