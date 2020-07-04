#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "glm/glm.hpp"

class Grid
{
public:
	/* Attributes */
	std::vector<glm::vec3> meshVertices;

	float floorVertices[12] = {
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
	};

	unsigned int floorIndices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	/* Constructor */
	Grid() 
	{
		// Add all the vertical lines
		for (int i = -100; i <= 100; i += 2)
		{
			meshVertices.push_back(glm::vec3(float(i) / 100, 1.0f, 0.0f));
			meshVertices.push_back(glm::vec3(float(i) / 100, -1.0f, 0.0f));
		}

		// Add all the horizontal lines
		for (int i = 100; i >= -100; i -= 2)
		{
			meshVertices.push_back(glm::vec3(-1.0f, float(i) / 100, 0.0f));
			meshVertices.push_back(glm::vec3(1.0f, float(i) / 100, 0.0f));
		}
	}
};

#endif 