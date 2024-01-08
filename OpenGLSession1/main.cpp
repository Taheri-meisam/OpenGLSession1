#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow* window; 

	// Initialize GLFW library
	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello Window ", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to get process address " << std::endl;
			glfwTerminate();
			return -1;
		}
		else {
			std::cout << " process is okay ";
		}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			std::cout << "Exit the window ..." << std::endl;
			glfwSetWindowShouldClose(window, true);
		}
		//glClearColor(1.0f, 0.4f, 0.4f, 1.0f); //changing color of window background 
		// clear the screen with the color // or default 
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
