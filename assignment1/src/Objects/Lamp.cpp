#include "Lamp.h"

#include <string>
#include <iostream>

Lamp::Lamp(Model * lampModel, glm::vec3 startingPos)
{
	model = lampModel;
	
	color = glm::vec3(1.0, 1.0, 1.0);
	position = startingPos;

	ambient = glm::vec3(0.8f, 0.8f, 0.8f);
	diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
	specular = glm::vec3(1.0f, 1.0f, 1.0f);

	constant = 1.0f;
	linear = 0.35f;
	quadratic = 0.44f;
}

Lamp::Lamp(Model * lampModel, glm::vec3 startingPos, glm::vec3 col, glm::vec3 amb, glm::vec3 dif, glm::vec3 spec, float line, float quad)
{
	model = lampModel;

	position = startingPos;
	color = col;

	ambient = amb;
	diffuse = dif;
	specular = spec;

	constant = 1.0f;
	linear = line;
	quadratic = quad;
}

Lamp::~Lamp() {};

void Lamp::setShaderValues(Shader * shader, int lampIndex)
{
	std::string shaderIndex = "pointLights[" + std::to_string(lampIndex) + "]";

	shader->setVec3(shaderIndex + ".position", position);
	shader->setVec3(shaderIndex + ".ambient", ambient.x, ambient.y, ambient.z);
	shader->setVec3(shaderIndex + ".diffuse", diffuse.x, diffuse.y, diffuse.z);
	shader->setVec3(shaderIndex + ".specular", specular.x, specular.y, specular.z);
	shader->setFloat(shaderIndex + ".constant", constant);
	shader->setFloat(shaderIndex + ".linear", linear);
	shader->setFloat(shaderIndex + ".quadratic", quadratic);
}

