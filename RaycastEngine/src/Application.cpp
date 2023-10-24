
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

float px, py; //Player X and Y

void drawPlayer() //Draw a player on the screen
{
	glColor3f(1, 1, 0); 
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(px, py);
	glEnd();
}

void buttons(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A && action == GLFW_PRESS) px -= 5;
	if (key == GLFW_KEY_D && action == GLFW_PRESS) px += 5;
	if (key == GLFW_KEY_S && action == GLFW_PRESS) py -= 5;
	if (key == GLFW_KEY_W && action == GLFW_PRESS) py += 5;
}

int main(void)
{
	//------Setting GLFW/GLEW------//
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(1024, 512, "Raycast Engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewInit();

	//------------------------------------Write after this line only------------------------------------//




	//------Render Loop------//
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.3, 0.3, 0.3, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		drawPlayer();

		glfwSetKeyCallback(window, buttons);

		glfwSwapBuffers(window);

	

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}