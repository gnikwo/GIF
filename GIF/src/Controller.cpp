#include "Controller.h"

#include "GIF.h"
#include "Window.h"


using namespace std;
using namespace glm;
using namespace GIF;

Controller::Controller(): m__keyBindings()
{



}


void Controller::bind(const int key, function<void()> action)
{

	m__keyBindings.insert(pair<const int, function<void()>>(key, action));

}


void Controller::unbind(const int key)
{

	m__keyBindings.erase(key);

}


void Controller::unbind()
{

	m__keyBindings.clear();

}


void Controller::check(Window* w)
{


    for (const auto p : m__keyBindings)
	{

        int state = glfwGetKey(w->getWindow(), p.first);
	    if (m__lastStates[p.first] == GLFW_RELEASE  && state == GLFW_PRESS)
		{

			p.second();

		}

        m__lastStates[p.first] = state;

	}


}
