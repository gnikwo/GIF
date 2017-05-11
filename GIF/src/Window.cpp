#include "Window.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
//using namespace glm;
using namespace GIF;

GIF::Window::Window(std::string title, int width, int height): m__window(),
                                                                m__title(title),
                                                                m__width(width),
                                                                m__height(height)//,
                                                                //m__backgroundColor(vec3(0.2, 0.2, 0.2))
{


}


GIF::Window::~Window()
{



}

void GIF::Window::load()
{

    m__window = glfwCreateWindow(m__width, m__height, m__title.c_str(), NULL, NULL);
	if(!m__window)
	{

		std::cout << "Erreur lors de la creation de la fenetre" << std::endl;

		glfwTerminate();
		exit(EXIT_FAILURE);

	}

	//glfwSetKeyCallback(m__window, LORE::Window::key_callback);

	glfwMakeContextCurrent(m__window);

	glfwSetInputMode(m__window, GLFW_STICKY_KEYS, 1);

	glfwSetWindowUserPointer(m__window, this);
	glfwSetWindowSizeCallback(m__window, window_size_callback);
	glfwSetWindowFocusCallback(m__window, window_focus_callback);
	glfwSetWindowCloseCallback(m__window, window_close_callback);
    glfwSetCursorPosCallback(m__window, mouse_move_callback);


}

void GIF::Window::render()
{

    glfwMakeContextCurrent(m__window);

    int startTime = int(glfwGetTime() * 1000);

        glViewport(0, 0, m__width, m__height);

        //glClearColor(m__backgroundColor.x, m__backgroundColor.y, m__backgroundColor.z, 1.0f);
        glClearColor(0.2, 0.2, 0.2, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glfwSwapBuffers(m__window);

	glfwPollEvents();

	int endTime = int(glfwGetTime() * 1000);
	int elapsedTime = endTime - startTime;

	//cout << elapsedTime << endl;

    int framerate = 60/1000;
	if(elapsedTime < framerate)
        this_thread::sleep_for(std::chrono::milliseconds(framerate - elapsedTime));

}

//==============CALLBACKS==========

void GIF::Window::error_callback(int error, const char* description)
{
	cout << "[Window] error_callback() :" << description << "\n";
}


void GIF::Window::window_size_callback(GLFWwindow* window, int width, int height)
{

	cout << "[Window] window_size_callback" << endl;

}


void GIF::Window::window_focus_callback(GLFWwindow* window, int state)
{

	cout << "[Window] window_focus_callback: " << state << endl;

	//static_cast<Window*>(glfwGetWindowUserPointer(window))->m__paused = !state;

}

void GIF::Window::window_close_callback(GLFWwindow* window)
{

	cout << "[Window] window_close_callback" << endl;

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

//	w->close();

}

void GIF::Window::mouse_move_callback(GLFWwindow* window, double x, double y)
{

	//cout << "[Window] mouse_move_callback" << endl;

}


void GIF::Window::close()
{

	glfwSetWindowShouldClose(m__window, GL_TRUE);

}

int GIF::Window::shouldClose()
{
	return glfwWindowShouldClose(m__window);
}
