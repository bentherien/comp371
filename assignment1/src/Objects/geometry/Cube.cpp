//to be cube

#include<iostream>
#include "Cube.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Cube::Cube(glm::vec3 origin_a)
{
	origin = origin_a;
	std::cout << "here" << std::endl;
}

void Cube::transform(glm::mat4 transmat)
{
	for (int x = 0; x < sizeof(vertices) / sizeof(vertices[0]); x++)
	{
		glm::vec4 tempVec(
			Cube::vertices[x].position,
			1.0f
		);

		tempVec = transmat * tempVec;
		Cube::vertices[x].position.x = tempVec.x;
		Cube::vertices[x].position.y = tempVec.y;
		Cube::vertices[x].position.z = tempVec.z;
	}
}

void Cube::translate_tst()
{
	glm::mat4 translation(1.0f);
	translation = glm::translate(translation, glm::vec3(0.0 + origin.x, 0.0 + origin.y, 0.0 + origin.z));
	glm::vec4 m(1.0f, 1.0f, 1.0f, 1.0f);
	m = translation * m;
	std::cout<< "x: " << m.x << std::endl;
	std::cout << "y: " << m.y << std::endl;
	std::cout << "z: " << m.z << std::endl;
}



void Cube::translate_fromOrigin()
{
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0 + origin.x, 0.0 + origin.y, 0.0 + origin.z));
	transform(translation);
}

int Cube::getVAComponentCount()
{
	vaComponentCount = (sizeof(vertices) / sizeof(vertices[0])) * vertices[0].getComponentCount();
	return vaComponentCount;
}

int Cube::getVAByteSize()
{
	vaByteSize = getVAComponentCount() * vertices[0].getByteSize();
	return vaByteSize;
}


float* Cube::getVertexArray(){
	int components = vertices[0].getComponentCount();
	float* verts = new float[(sizeof(vertices) / sizeof(vertices[0])) * components];

	for(int x=0;x < sizeof(vertices)/sizeof(vertices[0]); x++)
	{
		float* arr1 = vertices[x].getVertex();
		std::copy(arr1, arr1 + components, verts + x * components);
	}
	return verts;
}