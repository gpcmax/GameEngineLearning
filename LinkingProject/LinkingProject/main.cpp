#include "libs.h"

void frameBuffer_resize_callback(GLFWwindow* window, int fbw, int fbh)
{
	glViewport(0, 0, fbw, fbh);
}

int main()
{
	//Init GLFW
	glfwInit();

	//Create Window
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	int framebufferWIdth = 0;
	int frameBufferHeight = 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); For mac os

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, frameBuffer_resize_callback);
	//glfwGetFramebufferSize(window, &framebufferWIdth, &frameBufferHeight);
	//glViewport(0, 0, framebufferWIdth, frameBufferHeight);

	glfwMakeContextCurrent(window); //Important!!

	//Init GLEW (Needs window and OpenGL Context)
	glewExperimental = GL_TRUE;

	//ERROR
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
		glfwTerminate();
	}

	//Main Loop
	while (!glfwWindowShouldClose(window))
	{
		//update input
		glfwPollEvents();
		//update

		//draw
		//clear
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		//draw


		//end draw
		glfwSwapBuffers(window);
		glFlush();
	}

	//End of Program
	glfwTerminate();

	return 0;
}