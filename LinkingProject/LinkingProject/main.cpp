#include "libs.h"

int main()
{
	glfwInit();

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Why wont this work";
	}
	
	system("PAUSE");

	return 0;
}