#include "shader.h"

#include <fstream>

void OpenGL::Shader::LoadShader(std::string VertPath, std::string FragPath)
{
    std::ifstream t(VertPath);
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    std::string buffer(size, ' ');
    t.seekg(0);
    t.read(&buffer[0], size);

    VertShaderSource = buffer;

    t = std::ifstream(FragPath);
    t.seekg(0, std::ios::end);
    size = t.tellg();
    buffer = std::string(size, ' ');
    t.seekg(0);
    t.read(&buffer[0], size);

    FragShaderSource = buffer;

    printf("Successfully loaded shaders!\n");

    GenerateShader();
}

void OpenGL::Shader::GenerateShader()
{
    // Load and compile vertex shader
    VertShader = glCreateShader(GL_VERTEX_SHADER);
    const char* VertChar = VertShaderSource.c_str();
    glShaderSource(VertShader, 1, &VertChar, NULL);
    glCompileShader(VertShader);


    int  success;
    char infoLog[512];
    glGetShaderiv(VertShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(VertShader, 512, NULL, infoLog);
        std::exception("Error when creating Vertex Shader");
    }

    // Load and compile fragment shader
    FragShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* FragChar = FragShaderSource.c_str();
    glShaderSource(FragShader, 1, &FragChar, NULL);
    glCompileShader(FragShader);


    glGetShaderiv(FragShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(FragShader, 512, NULL, infoLog);
        std::exception("Error when creating Fragment Shader");
    }

    // Link the shaders into a program
    ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram, VertShader);
    glAttachShader(ShaderProgram, FragShader);
    glLinkProgram(ShaderProgram);


    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ShaderProgram, 512, NULL, infoLog);
        std::exception("Error when creating Shader Program");
    }

    glUseProgram(ShaderProgram);

    glDeleteShader(VertShader);
    glDeleteShader(FragShader);

    std::cout << "Successfully generated shader!" << std::endl;
}
