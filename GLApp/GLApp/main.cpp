#include <gl_core_4_4.h>
#include <GLFW\glfw3.h>
#include <Gizmos.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>

using glm::vec3;
using glm::vec4;
using glm::mat4;

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

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	Gizmos::create();

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//clear buffer and set buffer color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.f, 0.5f, 0.5f, 1.f);
		glEnable(GL_DEPTH_TEST);

		Gizmos::clear();

		Gizmos::addTransform(mat4(1));

		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		for (int i = 0; i < 50; ++i)
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10), vec3(-10 + i, 0, -10), i == 10 ? white : black);

			Gizmos::addLine(vec3(10, 0, -10 + i), vec3(-10, 0, -10 + i), i == 10 ? white : black);
		}

		Gizmos::draw(projection * view);

		//game logic

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	Gizmos::destroy();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}