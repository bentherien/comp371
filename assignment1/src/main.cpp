/*
	COMP 371 - Section CC
	Practical Assignment #1
	Written By:
		Benjamin Therien (40034572)
		Sean Heinrichs (40075789)
		Wayne St Amand (40074423)
		Isabelle Gourchette (Add your SN# when you make a commit)
		Ziming Wang (Add your SN# when you make a commit)
	Due:  July 9th, 2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"	// For texture mapping (can remove once blocks don't have textures)
#include "Objects/geometry/Polygon.h"
#include "Objects/Grid.hpp"
#include "OurModels.cpp"

#include <GL/glew.h>    
#include <GLFW/glfw3.h> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLFW_REFRESH_RATE 60
#define	GLFW_DOUBLEBUFFER GLFW_TRUE

/* USED FOR DEBUGGING - Every OpenGL function call we use should be wrapped in a GLCall() 

The following 20 lines of code were taken from this video: 
https://www.youtube.com/watch?v=FBbPWSOQ0-w&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=10

*/
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))


static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[openGL error] (" << error << ") " << function <<
			" " << file << ":" << std::endl;
		return false;
	}
	return true;
}

/* Function Declarations */
void processInput(GLFWwindow *window);

/* Global Constants */
const unsigned int WINDOW_WIDTH = 1024;
const unsigned int WINDOW_HEIGHT = 768;

/* Camera Setup */
glm::vec3 cameraPos = glm::vec3(0.0f, 0.2f, 2.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -2.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float deltaTime = 0.0f;
float lastFrame = 0.0f;


#include <vector>
int main(void)
{
	/* Initialize GLFW */
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// TODO: Add double buffering support for the window
	// TODO: Use perspective view
	GLFWwindow* window;

	// Create a window and its OpenGL context 
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "COMP 371 - Assignment 1", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW 
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Enable depth test for 3D rendering 
	GLCall(glEnable(GL_DEPTH_TEST));

	// Build and Compile Shader Program 
	Shader shaderProgram("comp371/assignment1/src/Shaders/vertex.shader", "comp371/assignment1/src/Shaders/fragment.shader");

	/*
	std::cout << "getVAFloatCount: " << m1->getVAFloatCount() << std::endl;
	std::cout << "getVAVertexCount: " << m1->getVAVertexCount() << std::endl;
	std::cout << "getVAByteSize: " << m1->getVAByteSize() << std::endl;
	std::cout << "getVertexByteSize: " << m1->getVertexByteSize() << std::endl;
	std::cout << "getVertexByteSize: " << 3*sizeof(float) << std::endl;

	*/

	Model * ben = new Model(true, false, false);
	createBensModel(ben);
	ben->bindArrayBuffer(true, ben);


	Model* sean = createSeansModel();
	sean->bindArrayBuffer(true, sean);


	Model* wayne = createWaynesModel();
	wayne->bindArrayBuffer(true, wayne);


	Model* isa = createIsabellesModel();
	isa->bindArrayBuffer(true, isa);

	
	// [Grid]

	Grid mainGrid = Grid();

	unsigned int grid_VAOs[2], grid_VBOs[2], grid_EBO;
	glGenVertexArrays(2, grid_VAOs);
	glGenBuffers(2, grid_VBOs);
	glGenBuffers(1, &grid_EBO);

	// Grid Mesh 
	glBindVertexArray(grid_VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, grid_VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, mainGrid.meshVertices.size() * sizeof(glm::vec3), &mainGrid.meshVertices.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Grid Floor 
	glBindVertexArray(grid_VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, grid_VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mainGrid.floorVertices), mainGrid.floorVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, grid_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mainGrid.floorIndices), mainGrid.floorIndices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbinding (safe)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);




	shaderProgram.use();
	shaderProgram.setInt("texture", 0);


	// Uniform Declarations
	unsigned int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
	unsigned int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
	unsigned int projectionLoc = glGetUniformLocation(shaderProgram.ID, "projection");
	
	

	// Setup Camera Projection 
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	shaderProgram.setMat4("projection", projection);

	shaderProgram.setInt("fill", 0);

	// Main Loop 
	while (!glfwWindowShouldClose(window))
	{
		// Set frame for Camera (taken from LearnOpenGL)
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Event Handling
		processInput(window);


		// Render
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		// Tectures
		// TEMPORARY CODE: Either to be removed or moved to grid class (depending on whether we are using textures)
		//GLCall(glActiveTexture(GL_TEXTURE0));
		//GLCall(glBindTexture(GL_TEXTURE_2D, texture));

		// Handles camera views and transformations
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		shaderProgram.setMat4("view", view);

		// Define model
		glm::mat4 model;

		ben->bind();
		shaderProgram.setInt("fill", 2);                                    // Set Color or Textures with Uniform in Shader
		model = glm::mat4(1.0f);                                            // Use Identity Matrix to get rid of previous transformations
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));             // Make the model smaller with a scale function	
		model = glm::translate(model, glm::vec3(-22.0f, 0.0f, -22.0f));		// Move it to a corner
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));	// ??? All I know is that I need to call this or nothing works... Still trying to figure this out
		GLCall(glDrawArrays(GL_TRIANGLES, 0, ben->getVAVertexCount()));
		
		
		sean->bind();
		shaderProgram.setInt("fill", 2);                                    // Set Color or Textures with Uniform in Shader
		model = glm::mat4(1.0f);                                            // Use Identity Matrix to get rid of previous transformations
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));             // Make the model smaller with a scale function	
		model = glm::translate(model, glm::vec3(-22.0f, 0.0f, -22.0f));		// Move it to a corner
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));	// ??? All I know is that I need to call this or nothing works... Still trying to figure this out
		GLCall(glDrawArrays(GL_TRIANGLES, 0, sean->getVAVertexCount()));

		wayne->bind();
		shaderProgram.setInt("fill", 2);                                    // Set Color or Textures with Uniform in Shader
		model = glm::mat4(1.0f);                                            // Use Identity Matrix to get rid of previous transformations
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));             // Make the model smaller with a scale function	
		model = glm::translate(model, glm::vec3(-22.0f, 0.0f, -22.0f));		// Move it to a corner
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));	// ??? All I know is that I need to call this or nothing works... Still trying to figure this out
		GLCall(glDrawArrays(GL_TRIANGLES, 0, wayne->getVAVertexCount()));

		isa->bind();
		shaderProgram.setInt("fill", 2);                                    // Set Color or Textures with Uniform in Shader
		model = glm::mat4(1.0f);                                            // Use Identity Matrix to get rid of previous transformations
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));             // Make the model smaller with a scale function	
		model = glm::translate(model, glm::vec3(-22.0f, 0.0f, -22.0f));		// Move it to a corner
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));	// ??? All I know is that I need to call this or nothing works... Still trying to figure this out
		GLCall(glDrawArrays(GL_TRIANGLES, 0, isa->getVAVertexCount()));
		
		// Draw the Grid Mesh
		GLCall(glBindVertexArray(grid_VAOs[0]));
		shaderProgram.setInt("fill", 0);
		model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_LINES, 0, mainGrid.meshVertices.size());

		// Draw the Grid Floor
		GLCall(glBindVertexArray(grid_VAOs[1]));
		shaderProgram.setInt("fill", 1);
		model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0005f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap Buffers and Poll for Events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// De-allocate resources 
	ben->deallocate();
	sean->deallocate();
	wayne->deallocate();
	isa->deallocate();

	// Terminate Program 
	glfwTerminate();
	return 0;
}

// Import all event handling functions here 
void processInput(GLFWwindow *window)
{
	// Example call
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	// TODO: Change Camera to be dependent on Mouse Movements (as specified in the assignment)
	float cameraSpeed = 1.0 * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}


