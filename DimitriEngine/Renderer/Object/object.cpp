#include "object.h"


DimitriEngine::Object::Object()
{
}


void DimitriEngine::Object::CreateModel(std::string path, Material modelMaterial)
{
	this->model = Model(path, modelMaterial);
}

void DimitriEngine::Object::Update(Camera* cam, std::vector<Light> lights, Projection* projection, std::vector<glm::vec3> pos)
{
	model.DrawMultiple(transform, cam, lights, projection, pos);
}

void DimitriEngine::Object::Update(Camera* cam, std::vector<Light> lights, Projection* projection)
{
	model.Draw(transform, lights, cam, projection);
}

void DimitriEngine::Object::Exit()
{
	model.Exit();
}

