#include "Window.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace GIF;

GIF::Window::Window(std::string title, int width, int height): m__window(), m__title(title), m__width(width), m__height(height)
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


Window::~Window()
{



}

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
