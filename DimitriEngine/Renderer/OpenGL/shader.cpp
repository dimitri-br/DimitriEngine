#include "shader.h"

void OpenGL::Shader::LoadShader(std::string VertPath, std::string FragPath)
{
    VertShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    FragShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";
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
}

void OpenGL::Shader::Exit()
{
    glDeleteProgram(ShaderProgram);
}
