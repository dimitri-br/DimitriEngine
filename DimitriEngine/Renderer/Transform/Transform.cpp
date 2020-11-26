#include "Transform.h"


DimitriEngine::Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

glm::mat4 DimitriEngine::Transform::GetTransform()
{
	transform = glm::mat4(1.0f);
	transform = glm::translate(transform, position);
	
	transform = glm::rotate(transform, rotation.x, glm::vec3(1, 0, 0));
	transform = glm::rotate(transform, rotation.y, glm::vec3(0, 1, 0));
	transform = glm::rotate(transform, rotation.z, glm::vec3(0, 0, 1));

	transform = glm::scale(transform, scale);

	return transform;
}

void DimitriEngine::Transform::Translate(glm::vec3 offset)
{
	transform = glm::translate(transform, offset);
	UpdateLocalVars();
}

void DimitriEngine::Transform::Rotate(float angle, glm::vec3 axis)
{
	transform = glm::rotate(transform, angle, axis);
	rotation += glm::vec3(angle * axis);
	UpdateLocalVars();
}

void DimitriEngine::Transform::UpdateLocalVars() {
	glm::quat quatRotation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transform, scale, quatRotation, position, skew, perspective);

	//rotation = glm::eulerAngles(quatRotation) * 3.14159f / 180.f; // get the euler angles
}
