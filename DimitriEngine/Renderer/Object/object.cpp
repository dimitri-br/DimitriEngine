#include "object.h"


DimitriEngine::Object::Object()
{
}

DimitriEngine::Object::Object(OpenGLRenderer _openGLRenderer, Rendering::BackEndType _type)
{
	openGLRenderer = _openGLRenderer;
	type = _type;
}

void DimitriEngine::Object::CreateModel(std::string path, Material modelMaterial)
{
	this->model = Model(path, modelMaterial);
}

void DimitriEngine::Object::Update(Camera* cam, std::vector<Light> lights, Projection* projection)
{
	model.Draw(transform, lights, cam, projection);
}

void DimitriEngine::Object::Exit()
{
	model.Exit();
}

