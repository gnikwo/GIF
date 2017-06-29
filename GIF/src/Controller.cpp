#include "Controller.h"

#include "GIF.h"
#include "Window.h"


using namespace std;
using namespace glm;
using namespace GIF;

Controller::Controller(): m__keyBindingsPress(), m__keyBindingsPressing(), m__keyBindingsRelease()


{



}


void Controller::bindPress(const int key, function<void()> action)
{

	m__keyBindingsPress.insert(pair<const int, function<void()>>(key, action));

}


void Controller::bindPressing(const int key, function<void()> action)
{

	m__keyBindingsPressing.insert(pair<const int, function<void()>>(key, action));

}


void Controller::bindRelease(const int key, function<void()> action)
{

	m__keyBindingsRelease.insert(pair<const int, function<void()>>(key, action));

}


void Controller::unbind(const int key)
{

	m__keyBindingsPress.erase(key);
	m__keyBindingsPressing.erase(key);
	m__keyBindingsRelease.erase(key);

}


void Controller::unbind()
{

	m__keyBindingsPress.clear();
	m__keyBindingsPressing.clear();
	m__keyBindingsRelease.clear();

}


void Controller::check(Window* w)
{


    for (const auto p : m__keyBindingsPress)
	{

        int state = glfwGetKey(w->getWindow(), p.first);
	    if (m__lastStates[p.first] == GLFW_RELEASE  && state == GLFW_PRESS)
		{

			p.second();

		}

        if (m__lastStates[p.first] == GLFW_PRESS  && state == GLFW_PRESS)
		{

			p.second();

		}

	    if (m__lastStates[p.first] == GLFW_PRESS  && state == GLFW_RELEASE)
		{

			p.second();

		}

        m__lastStates[p.first] = state;

	}

    for (const auto p : m__keyBindingsPressing)
	{

        int state = glfwGetKey(w->getWindow(), p.first);

        if (m__lastStates[p.first] == GLFW_PRESS  && state == GLFW_PRESS)
		{

			p.second();

		}

        m__lastStates[p.first] = state;

	}

    for (const auto p : m__keyBindingsRelease)
	{

        int state = glfwGetKey(w->getWindow(), p.first);
	    if (m__lastStates[p.first] == GLFW_PRESS  && state == GLFW_RELEASE)
		{

			p.second();

		}

        m__lastStates[p.first] = state;

	}


}
