#include <gl_core_4_4.h>
#include <GLFW\glfw3.h>

int main()
{

	if (glfwInit() == false)
		return -1;


	GLFWwindow* window = glfwCreateWindow(800, 600, "Open GL Test App", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}
	
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	glfwMakeContextCurrent(window);


	//Code


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}