#include "projection.h"

void OpenGL::Projection::Initialize(OpenGLRenderer _openGLRenderer)
{
	openGLRenderer = _openGLRenderer;


	model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	int modelLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	int viewLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	int projectionLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void OpenGL::Projection::UpdateView(glm::vec3 newPos)
{
	view = glm::mat4(1.0f);
	view = glm::translate(view, newPos);

	int viewLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void OpenGL::Projection::UpdateModel(float angle, glm::vec3 rotPos)
{
	model = glm::mat4(1.0f);
	model = glm::rotate(model, angle, rotPos);


	int modelLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void OpenGL::Projection::UpdateProjection(float FOV, float centerPoint, float cullMin, float cullMax)
{
	projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(FOV), centerPoint, cullMin, cullMax);

	int projectionLoc = glGetUniformLocation(openGLRenderer.GetShaderProgram(), "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}