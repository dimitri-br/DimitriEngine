#include "Material.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

DimitriEngine::Material::Material()
{
	//std::cout << "Please make sure to assign textures and color!" << std::endl;
}

DimitriEngine::Material::Material(std::vector<Texture> _textures)
{
	for (Texture tex : textures) {
		if (!tex.textureIsLoaded) {
			std::cout << "Loading texture: " << tex.path << std::endl;
			LoadImage(tex.path, tex.texture);
			tex.textureIsLoaded = true;
		}
		else {
			std::cout << "Texture is loaded\nPath: " << tex.path << "\nName: " << tex.name << std::endl;
		}
	}
	this->textures = textures;
	shader.LoadShader("./Shaders/shader.vert", "./Shaders/shader.frag");

}

DimitriEngine::Material::Material(std::vector<Texture> textures, glm::vec3 _color)
{
	for (Texture tex : textures) {
		if (!tex.textureIsLoaded) {
			std::cout << "Loading texture: " << tex.path << std::endl;
			LoadImage(tex.path, tex.texture);
			tex.textureIsLoaded = true;
		}
		else {
			std::cout << "Texture is loaded\nPath: " << tex.path << "\nName: " << tex.name << std::endl;
		}
	}
	this->textures = textures;
	this->color = color;
	shader.LoadShader("./Shaders/shader.vert", "./Shaders/shader.frag");
}

DimitriEngine::Material::Material(std::vector<Texture> _textures, float smoothness, float metallic)
{
	for (Texture tex : textures) {
		if (!tex.textureIsLoaded) {
			std::cout << "Loading texture: " << tex.path << std::endl;
			LoadImage(tex.path, tex.texture);
			tex.textureIsLoaded = true;
		}
		else {
			std::cout << "Texture is loaded\nPath: " << tex.path << "\nName: " << tex.name << std::endl;
		}
	}
	this->textures = textures;
	this->smoothness = smoothness;
	this->metallic = metallic;
	shader.LoadShader("./Shaders/shader.vert", "./Shaders/shader.frag");
}

DimitriEngine::Material::Material(std::vector<Texture> _textures, glm::vec3 _color, float smoothness, float metallic)
{
	for (Texture tex : textures) {
		if (!tex.textureIsLoaded) {
			std::cout << "Loading texture: " << tex.path << std::endl;
			LoadImage(tex.path, tex.texture);
			tex.textureIsLoaded = true;
		}
		else {
			std::cout << "Texture is loaded\nPath: " << tex.path << "\nName: " << tex.name << std::endl;
		}
	}
	this->textures = textures;
	this->color = color;
	this->smoothness = smoothness;
	this->metallic = metallic;
	shader.LoadShader("./Shaders/shader.vert", "./Shaders/shader.frag");
}

unsigned int DimitriEngine::Material::LoadImage(std::string& path, unsigned int texture)
{
	glGenTextures(1, &texture); // Create texture object

	glBindTexture(GL_TEXTURE_2D, texture); // Bind it
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture: " << path << " . Please ensure you have supplied a valid path" << std::endl;

	}
	stbi_image_free(data);

	return texture;
}

