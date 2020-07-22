#pragma once

#include "../Shaders/Shader.h"
#include "geometry/Model.h"

class Lamp
{
public:
	// Constructors & Destructors
	Lamp(Model * lampModel, glm::vec3 startingPos);
	Lamp(Model * lampModel, glm::vec3 startingPos, glm::vec3 col, glm::vec3 amb, glm::vec3 dif, glm::vec3 spec, float line, float quad);
	~Lamp();

	// Functions
	void setShaderValues(Shader * shader, int lampIndex);

	// Accessors
	Model* getModel() const { return model; };
	glm::vec3 getPosition() const { return position; };
	glm::vec3 getColor() const { return color; };
	glm::vec3 getAmbient() const { return ambient; };
	glm::vec3 getDiffuse() const { return diffuse; };
	glm::vec3 getSpecular() const { return specular; };
	float getConstant() const { return constant; };
	float getLinear() const { return linear; };
	float getQuadratic() const { return quadratic; };

private:
	Model * model;

	glm::vec3 color;
	glm::vec3 position;
	
	// Light Modifiers
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	// Distance Modifiers
	float constant;
	float linear;
	float quadratic;
};