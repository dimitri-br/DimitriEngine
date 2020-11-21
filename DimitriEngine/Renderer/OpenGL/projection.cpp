#include "projection.h"

OpenGL::Projection::Projection() {
	model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));

	projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void OpenGL::Projection::UpdateView(glm::vec3 newPos)
{
	view = glm::mat4(1.0f);
	view = glm::translate(view, newPos);
}

void OpenGL::Projection::UpdateModel(float angle, glm::vec3 rotPos)
{
	model = glm::mat4(1.0f);
	model = glm::rotate(model, angle, rotPos);
}

void OpenGL::Projection::UpdateProjection(float FOV, float centerPoint, float cullMin, float cullMax)
{
	projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(FOV), centerPoint, cullMin, cullMax);
}

void OpenGL::Projection::SetRawView(glm::mat4 newView) {
	view = newView;
}