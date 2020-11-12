#pragma once
#include "../window.h"

namespace OpenGL {
	class Shader
	{

	public:
		unsigned int ShaderProgram;


		void LoadShader(std::string VertPath, std::string FragPath);

		void GenerateShader();

		void Exit();

	private:
		std::string VertShaderSource;
		std::string FragShaderSource;

		unsigned int VertShader;
		unsigned int FragShader;

		
	};
}