#pragma once
#include "../window.h"

namespace OpenGL {
	class Shader
	{

	public:
		unsigned int ShaderProgram;


		void LoadShader(std::string VertPath, std::string FragPath);

		void GenerateShader();

		void UseShader();

		void BindVec1(std::string loc, glm::vec1 vec);
		void BindVec2(std::string loc, glm::vec2 vec);
		void BindVec3(std::string loc, glm::vec3 vec);
		void BindVec4(std::string loc, glm::vec4 vec);

		void BindMat2(std::string loc, glm::mat2 mat);
		void BindMat3(std::string loc, glm::mat3 mat);
		void BindMat4(std::string loc, glm::mat4 mat);

		void BindFloat(std::string loc, float value);
		void BindInt(std::string loc, int value);
		void BindBool(std::string loc, bool value);

		void Exit();

	private:
		std::string VertShaderSource;
		std::string FragShaderSource;

		unsigned int VertShader;
		unsigned int FragShader;

		
	};
}