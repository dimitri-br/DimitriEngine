#include "Light.h"
#include "../OpenGL/shader.h"
#include "../OpenGL/projection.h"
#include <string>

DimitriEngine::Light::Light()
{
    SetupLightRenderer();

}

void DimitriEngine::Light::DrawPoint(OpenGL::Shader shader)
{
	shader.BindVec3(("pointLights[" + std::to_string(lightID) + "].position"), position);

	shader.BindVec3(("pointLights[" + std::to_string(lightID) + "].ambient"), ambient);

	shader.BindVec3(("pointLights[" + std::to_string(lightID) + "].diffuse"), diffuse);

	shader.BindVec3(("pointLights[" + std::to_string(lightID) + "].specular"), specular);

	shader.BindFloat(("pointLights[" + std::to_string(lightID) + "].constant"), constant);

	shader.BindFloat(("pointLights[" + std::to_string(lightID) + "].linear"), linear);

    shader.BindFloat(("pointLights[" + std::to_string(lightID) + "].quadratic"), quadratic);

    shader.BindVec3(("pointLights[" + std::to_string(lightID) + "].color"), lightColor);
}

void DimitriEngine::Light::DrawLight(OpenGL::Shader shader, OpenGL::Projection* proj)
{
    shader.UseShader();
	//std::cout << "light type: " << lightType << std::endl;
	if (lightType == LIGHT_DIRECTIONAL) {
		DrawDirectional(shader);
	}
	else if (lightType == LIGHT_POINT){
		DrawPoint(shader);
	}

}

void DimitriEngine::Light::DrawDirectional(OpenGL::Shader shader)
{
	shader.BindVec3("dirLight.direction", direction);
	shader.BindVec3("dirLight.ambient", ambient);
	shader.BindVec3("dirLight.diffuse", diffuse);
    shader.BindVec3("dirLight.specular", specular);
    shader.BindVec3("dirLight.color", lightColor);
}

void DimitriEngine::Light::SetupLightRenderer() {
    lightShader.LoadShader("./shaders/light.vert", "./shaders/light.frag");


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &lightVBO);

    // we only need to bind to the VBO, the container's VBO's data already contains the data.
    glBindBuffer(GL_ARRAY_BUFFER, lightVBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(lightVAO);
    


    // set the vertex attribute 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);



}

void DimitriEngine::Light::DrawRenderer(OpenGL::Projection* proj) {
    lightShader.UseShader();
    lightShader.BindMat4("model", transform.GetTransform());
    lightShader.BindMat4("projection", proj->projection);
    lightShader.BindMat4("view", proj->view);

    lightShader.BindVec3("lightColor", lightColor);
    lightShader.BindVec3("objectColor", lightObjectColor);

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
}
