#include "Light.h"
#include "../OpenGL/shader.h"
#include <string>

DimitriEngine::Light::Light()
{

}

void DimitriEngine::Light::DrawPoint(OpenGL::Shader shader, int lightID)
{
	std::string name = std::string("pointLights[").append(std::to_string(lightID));
	name.append("]");
	std::string pos = name;
	pos.append(".position");
	shader.BindVec3(pos, position);

	std::string amb = name;
	amb.append(".ambient");
	shader.BindVec3(amb, ambient);

	std::string dif = name;
	dif.append(".diffuse");
	shader.BindVec3(dif, diffuse);

	std::string spec = name;
	spec.append(".specular");
	shader.BindVec3(spec, specular);

	std::string cons = name;
	cons.append(".constant");
	shader.BindFloat(cons, constant);

	std::string lin = name;
	lin.append(".linear");
	shader.BindFloat(lin, linear);

	std::string quad = name;
	quad.append(".quadratic");
	shader.BindFloat(quad, quadratic);
}

void DimitriEngine::Light::DrawLight(OpenGL::Shader shader, int lightID)
{
	if (lightType == LIGHT_DIRECTIONAL) {
		DrawDirectional(shader);
	}
	else if (lightType == LIGHT_POINT){
		DrawPoint(shader, lightID);
	}
}

void DimitriEngine::Light::DrawDirectional(OpenGL::Shader shader)
{
	shader.BindVec3("dirLight.direction", direction);
	shader.BindVec3("dirLight.ambient", ambient);
	shader.BindVec3("dirLight.diffuse", diffuse);
	shader.BindVec3("dirLight.specular", specular);
}
