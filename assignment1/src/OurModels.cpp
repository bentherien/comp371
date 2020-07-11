#include "Objects/geometry/Cube.h"
#include "Objects/geometry/Model.h"
#include <glm/gtc/matrix_transform.hpp>

/* Static methods to create our Models */
static void createSeansModel(Model * model)
{	
	Cube * cb1 = new Cube(glm::vec3(0.0f, 0.5f, 0.0f));
	Cube * cb2 = new Cube(glm::vec3(2.0f, 0.5f, 0.0f));
	Cube * cb3 = new Cube(glm::vec3(6.0f, 0.5f, 0.0f));
	Cube * cb4 = new Cube(glm::vec3(4.0f, 2.0f, 0.0f));
	Cube * cb5 = new Cube(glm::vec3(1.0f, 2.5f, 0.0f));
	Cube * cb6 = new Cube(glm::vec3(1.0f, 4.5f, 0.0f));
	Cube * cb7 = new Cube(glm::vec3(5.0f, 4.5f, 0.0f));

	// Create 1x4 columns
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 5.0f, 1.0f));

	cb1->transform(scale);
	cb2->transform(scale);
	cb3->transform(scale);

	// Create 1x2 column
	scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 2.0f, 1.0f));

	cb4->transform(scale);

	model->addPolygon(cb1);
	model->addPolygon(cb2);
	model->addPolygon(cb3);
	model->addPolygon(cb4);
	model->addPolygon(cb5);
	model->addPolygon(cb6);
	model->addPolygon(cb7);

	// Set initial position
	glm::mat4 mat(1.0f);
	mat = glm::translate(mat, glm::vec3(-4.5f, 0.0f, -3.0f));
	mat = glm::rotate(mat, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mat = glm::scale(mat, glm::vec3(0.2f, 0.2f, 0.2f));

	model->transform(mat);
}


static void createWaynesModel(Model * model)
{
	Cube * cb1 = new Cube(glm::vec3(0.0f, 3.5f, 0.0f));
	Cube * cb2 = new Cube(glm::vec3(0.0f, 4.5f, 0.0f));
	Cube * cb3 = new Cube(glm::vec3(1.0f, 0.5f, 0.0f));
	Cube * cb4 = new Cube(glm::vec3(1.0f, 1.5f, 0.0f));
	Cube * cb5 = new Cube(glm::vec3(1.0f, 2.5f, 0.0f));
	Cube * cb6 = new Cube(glm::vec3(1.0f, 3.5f, 0.0f));
	Cube * cb7 = new Cube(glm::vec3(2.0f, 3.5f, 0.0f));
	Cube * cb8 = new Cube(glm::vec3(2.0f, 4.5f, 0.0f));

	Cube * cb9 = new Cube(glm::vec3( 4.0f, 3.5f, 0.0f));
	Cube * cb10 = new Cube(glm::vec3(4.0f, 4.5f, 0.0f));
	Cube * cb11 = new Cube(glm::vec3(5.0f, 4.5f, 0.0f));
	Cube * cb12 = new Cube(glm::vec3(6.0f, 0.5f, 0.0f));
	Cube * cb13 = new Cube(glm::vec3(6.0f, 1.5f, 0.0f));
	Cube * cb14 = new Cube(glm::vec3(6.0f, 2.5f, 0.0f));
	Cube * cb15 = new Cube(glm::vec3(6.0f, 3.5f, 0.0f));
	Cube * cb16 = new Cube(glm::vec3(6.0f, 4.5f, 0.0f));

	model->addPolygon(cb1);
	model->addPolygon(cb2);
	model->addPolygon(cb3);
	model->addPolygon(cb4);
	model->addPolygon(cb5);
	model->addPolygon(cb6);
	model->addPolygon(cb7);
	model->addPolygon(cb8);

	model->addPolygon(cb9);
	model->addPolygon(cb10);
	model->addPolygon(cb11);
	model->addPolygon(cb12);
	model->addPolygon(cb13);
	model->addPolygon(cb14);
	model->addPolygon(cb15);
	model->addPolygon(cb16);

	// Set initial position
	glm::mat4 mat(1.0f);
	mat = glm::translate(mat, glm::vec3(3.5f, 0.0f, -4.0f));
	mat = glm::rotate(mat, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mat = glm::scale(mat, glm::vec3(0.2f, 0.2f, 0.2f));

	model->transform(mat);
}


/* Static methods to create our Models */
static void createBensModel(Model* model)
{
	/*
	model->addPolygon(new Cube(glm::vec3(0.0f, 0.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(0.0f, 1.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(0.0f, 2.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(0.0f, 3.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(0.75f, 3.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(1.25f, 2.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(1.75f, 1.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(2.25f, 0.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(3.0f, 0.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(3.0f, 1.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(3.0f, 2.5f, 0.0f)));
	model->addPolygon(new Cube(glm::vec3(3.0f, 3.5f, 0.0f)));
	*/

	Model* three = new Model(true, false, false);

	three->addPolygon(new Cube(glm::vec3(5.0f, 3.5f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(5.5f, 3.5f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(6.0f, 3.5f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(5.0f, 2.0f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(5.5f, 2.0f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(6.0f, 2.0f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(5.0f, 0.5f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(5.5f, 0.5f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(6.0f, 0.5f, 0.0f)));

	three->addPolygon(new Cube(glm::vec3(6.5f, 1.0f, 0.0f)));
	three->addPolygon(new Cube(glm::vec3(6.5f, 3.0f, 0.0f)));
	three->transform(glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, 0.0f)));

	

	Cube *cb = new Cube(glm::vec3(8.125f, 0.5f, 0.0f));
	Cube *cb1 = new Cube(glm::vec3(5.825f, 0.5f, 0.0f));
	Cube *cb2 = new Cube(glm::vec3(0.0f, 0.0f, 0.0f));
	
	glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(7.0f, 2.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 4.0f, 1.0f));
	glm::mat4 sr = glm::rotate(glm::mat4(1.0f), glm::radians(35.0f), glm::vec3(0.0f, 0.0f, 1.0));
	sr = translate * sr * scale;

	cb->transform(scale);
	cb1->transform(scale);
	cb2->transform(sr);
	model->addPolygon(cb);
	model->addPolygon(cb1);
	model->addPolygon(cb2);
	model->addPolygon(three);



	// Set initial position
	glm::mat4 mat(1.0f);
	mat = glm::translate(mat, glm::vec3(-1.5f, 0.0f, -2.0f));
	mat = glm::scale(mat, glm::vec3(0.2f, 0.2f, 0.2f));

	model->transform(mat);
}


static void createIsabellesModel(Model * model)
{
	//A0
	float originX = 0.0f;
	float originY = 0.5f;
	float originZ = 0.0f;
	float cubeOffset = 1.0f;
	float letterOffset = cubeOffset * 5;
	//drawing A
	//left 
	Cube * cube1 = new Cube(glm::vec3(originX, originY, originZ));
	Cube * cube2 = new Cube(glm::vec3(originX, originY + cubeOffset, originZ));
	Cube * cube3 = new Cube(glm::vec3(originX, originY + cubeOffset * 2, originZ));
	Cube * cube4 = new Cube(glm::vec3(originX, originY + cubeOffset * 3, originZ));
	Cube * cube5 = new Cube(glm::vec3(originX, originY + cubeOffset * 4, originZ));
	Cube * cube6 = new Cube(glm::vec3(originX, originY + cubeOffset * 5, originZ));
	//right
	Cube * cube7 = new Cube(glm::vec3(originX + cubeOffset * 3, originY, originZ));
	Cube * cube8 = new Cube(glm::vec3(originX + cubeOffset * 3, originY + cubeOffset, originZ));
	Cube * cube9 = new Cube(glm::vec3(originX + cubeOffset * 3, originY + cubeOffset * 2, originZ));
	Cube * cube10 = new Cube(glm::vec3(originX + cubeOffset * 3, originY + cubeOffset * 3, originZ));
	Cube * cube11 = new Cube(glm::vec3(originX + cubeOffset * 3, originY + cubeOffset * 4, originZ));
	Cube * cube12 = new Cube(glm::vec3(originX + cubeOffset * 3, originY + cubeOffset * 5, originZ));
	//middle top
	Cube * cube13 = new Cube(glm::vec3(originX + cubeOffset, originY + cubeOffset * 5, originZ));
	Cube * cube14 = new Cube(glm::vec3(originX + cubeOffset * 2, originY + cubeOffset * 5, originZ));
	//middle bottom
	Cube * cube15 = new Cube(glm::vec3(originX + cubeOffset, originY + cubeOffset * 3, originZ));
	Cube * cube16 = new Cube(glm::vec3(originX + cubeOffset * 2, originY + cubeOffset * 3, originZ));

	//drawing 0
	//left
	Cube * cube17 = new Cube(glm::vec3(originX + letterOffset, originY, originZ));
	Cube * cube18 = new Cube(glm::vec3(originX + letterOffset, originY + cubeOffset, originZ));
	Cube * cube19 = new Cube(glm::vec3(originX + letterOffset, originY + cubeOffset * 2, originZ));
	Cube * cube20 = new Cube(glm::vec3(originX + letterOffset, originY + cubeOffset * 3, originZ));
	Cube * cube21 = new Cube(glm::vec3(originX + letterOffset, originY + cubeOffset * 4, originZ));
	Cube * cube22 = new Cube(glm::vec3(originX + letterOffset, originY + cubeOffset * 5, originZ));
	//right
	Cube * cube23 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY, originZ));
	Cube * cube24 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY + cubeOffset, originZ));
	Cube * cube25 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY + cubeOffset * 2, originZ));
	Cube * cube26 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY + cubeOffset * 3, originZ));
	Cube * cube27 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY + cubeOffset * 4, originZ));
	Cube * cube28 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 3, originY + cubeOffset * 5, originZ));
	//top
	Cube * cube29 = new Cube(glm::vec3(originX + letterOffset + cubeOffset, originY + cubeOffset * 5, originZ));
	Cube * cube30 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 2, originY + cubeOffset * 5, originZ));
	//bottom
	Cube * cube31 = new Cube(glm::vec3(originX + letterOffset + cubeOffset, originY, originZ));
	Cube * cube32 = new Cube(glm::vec3(originX + letterOffset + cubeOffset * 2, originY, originZ));

	Model * isabellesModel = new Model(true, false, false);
	model->addPolygon(cube1);
	model->addPolygon(cube2);
	model->addPolygon(cube3);
	model->addPolygon(cube4);
	model->addPolygon(cube5);
	model->addPolygon(cube6);
	model->addPolygon(cube7);
	model->addPolygon(cube8);
	model->addPolygon(cube9);
	model->addPolygon(cube10);
	model->addPolygon(cube11);
	model->addPolygon(cube12);
	model->addPolygon(cube13);
	model->addPolygon(cube14);
	model->addPolygon(cube15);
	model->addPolygon(cube16);
	model->addPolygon(cube17);
	model->addPolygon(cube18);
	model->addPolygon(cube19);
	model->addPolygon(cube20);
	model->addPolygon(cube21);
	model->addPolygon(cube22);
	model->addPolygon(cube23);
	model->addPolygon(cube24);
	model->addPolygon(cube25);
	model->addPolygon(cube26);
	model->addPolygon(cube27);
	model->addPolygon(cube28);
	model->addPolygon(cube29);
	model->addPolygon(cube30);
	model->addPolygon(cube31);
	model->addPolygon(cube32);

	// Set initial position
	glm::mat4 mat(1.0f);
	mat = glm::translate(mat, glm::vec3(4.0f, 0.0f, 3.5f));
	mat = glm::rotate(mat, glm::radians(-135.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mat = glm::scale(mat, glm::vec3(0.2f, 0.2f, 0.2f));

	model->transform(mat);
}

static void createZimingsModel(Model * model)
{
	Cube * cb1 = new Cube(glm::vec3(0.0f, 0.5f, 0.0f));
	Cube * cb2 = new Cube(glm::vec3(0.0f, 1.5f, 0.0f));
	Cube * cb3 = new Cube(glm::vec3(0.0f, 2.5f, 0.0f));
	Cube * cb4 = new Cube(glm::vec3(0.0f, 3.5f, 0.0f));
	Cube * cb5 = new Cube(glm::vec3(1.0f, 3.5f, 0.0f));
	Cube * cb6 = new Cube(glm::vec3(2.0f, 0.5f, 0.0f));
	Cube * cb7 = new Cube(glm::vec3(2.0f, 1.5f, 0.0f));
	Cube * cb8 = new Cube(glm::vec3(2.0f, 2.5f, 0.0f));
	Cube * cb9 = new Cube(glm::vec3(2.0f, 3.5f, 0.0f));
	Cube * cb10 = new Cube(glm::vec3(3.0f, 3.5f, 0.0f));
	Cube * cb11 = new Cube(glm::vec3(4.0f, 0.5f, 0.0f));
	Cube * cb12 = new Cube(glm::vec3(4.0f, 1.5f, 0.0f));
	Cube * cb13 = new Cube(glm::vec3(4.0f, 2.5f, 0.0f));
	Cube * cb14 = new Cube(glm::vec3(4.0f, 3.5f, 0.0f));
	Cube * cb15 = new Cube(glm::vec3(6.0f, 1.5f, 0.0f));
	Cube * cb16 = new Cube(glm::vec3(6.0f, 2.5f, 0.0f));
	Cube * cb17 = new Cube(glm::vec3(6.0f, 3.5f, 0.0f));
	Cube * cb18 = new Cube(glm::vec3(7.0f, 1.5f, 0.0f));
	Cube * cb19 = new Cube(glm::vec3(8.0f, 0.5f, 0.0f));
	Cube * cb20 = new Cube(glm::vec3(8.0f, 1.5f, 0.0f));
	Cube * cb21 = new Cube(glm::vec3(8.0f, 2.5f, 0.0f));
	Cube * cb22 = new Cube(glm::vec3(8.0f, 3.5f, 0.0f));
	Cube * cb23 = new Cube(glm::vec3(9.0f, 1.5f, 0.0f));

	Model * ZimingsModel = new Model(true, false, false);
	model->addPolygon(cb1);
	model->addPolygon(cb2);
	model->addPolygon(cb3);
	model->addPolygon(cb4);
	model->addPolygon(cb5);
	model->addPolygon(cb6);
	model->addPolygon(cb7);
	model->addPolygon(cb8);
	model->addPolygon(cb9);
	model->addPolygon(cb10);
	model->addPolygon(cb11);
	model->addPolygon(cb12);
	model->addPolygon(cb13);
	model->addPolygon(cb14);
	model->addPolygon(cb15);
	model->addPolygon(cb16);
	model->addPolygon(cb17);
	model->addPolygon(cb18);
	model->addPolygon(cb19);
	model->addPolygon(cb20);
	model->addPolygon(cb21);
	model->addPolygon(cb22);
	model->addPolygon(cb23);

	// Set initial position
	glm::mat4 mat(1.0f);
	mat = glm::translate(mat, glm::vec3(-3.5f, 0.0f, 4.5f));
	mat = glm::rotate(mat, glm::radians(135.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mat = glm::scale(mat, glm::vec3(0.2f, 0.2f, 0.2f));

	model->transform(mat);
}