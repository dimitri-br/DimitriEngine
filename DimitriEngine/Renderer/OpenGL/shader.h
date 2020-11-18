#pragma once
#include "../window.h"
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL {
	class Shader
	{

	public:
		unsigned int ShaderProgram;


		void LoadShader(std::string VertPath, std::string FragPath);

		void GenerateShader();

		void UseShader() {
			glUseProgram(ShaderProgram);
		}

		void BindVec1(const std::string &loc, const  glm::vec1 vec) const
		{
			glUniform1fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, glm::value_ptr(vec));
		}

		void BindVec2(const std::string &loc, const  glm::vec2 vec) const
		{
			glUniform2fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, glm::value_ptr(vec));
		}

		void BindVec3(const std::string &loc, const  glm::vec3 vec) const
		{
			glUniform3fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, glm::value_ptr(vec));
		}

		void BindVec4(const std::string &loc, const  glm::vec4 vec) const
		{
			glUniform4fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, glm::value_ptr(vec));
		}

		void BindMat2(const std::string &loc, const  glm::mat2 mat) const
		{
			glUniformMatrix2fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
		}

		void BindMat3(const std::string &loc, const  glm::mat3 mat) const
		{
			glUniformMatrix3fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
		}

		void BindMat4(const std::string &loc, const  glm::mat4 mat) const
		{
			glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, loc.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
		}

		void BindFloat(const std::string &loc, const float value) const
		{
			glUniform1f(glGetUniformLocation(ShaderProgram, loc.c_str()), value);
		}

		void BindInt(const std::string &loc, const int value) const
		{
			glUniform1i(glGetUniformLocation(ShaderProgram, loc.c_str()), value);
		}

		void BindBool(const std::string &loc, const bool value) const
		{
			glUniform1i(glGetUniformLocation(ShaderProgram, loc.c_str()), value);
		}

		void Exit()
		{
			glDeleteProgram(ShaderProgram);
		}

	private:
		std::string VertShaderSource;
		std::string FragShaderSource;

		unsigned int VertShader;
		unsigned int FragShader;

		
	};
}