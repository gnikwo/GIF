#include "Controller.h"

#include "GIF.h"
#include "Window.h"


using namespace std;
using namespace glm;
using namespace GIF;

Controller::Controller(): m__keyBindings(), m__visibleCursor(true), m__captureCursor(false)
{



}


Controller::~Controller()
{



}


void Controller::bind(const int key, function<void(double dx, double dy)> action)
{

	m__keyBindings.insert(pair<const int, function<void(double dx, double dy)>>(key, action));

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

	double x, y;
	glfwGetCursorPos(w->getWindow(), &x, &y);
	double dx = x - double(w->getWidth())/2, dy = y - double(w->getHeight())/2;


    for (const auto p : m__keyBindings)
	{

        int state = glfwGetKey(w->getWindow(), p.first);
	    if (m__lastStates[p.first] == GLFW_RELEASE  && state == GLFW_PRESS)
		{

			p.second(x, y);

		}

        m__lastStates[p.first] = state;

	}

    int state = glfwGetMouseButton(w->getWindow(), GLFW_MOUSE_BUTTON_LEFT);
    if (m__lastClickStates[GLFW_MOUSE_BUTTON_LEFT] == GLFW_RELEASE && state == GLFW_PRESS)
    {
        cout << "Click" << endl;
        Gif::click(w, vec2(x,y));
    }

    m__lastClickStates[GLFW_MOUSE_BUTTON_LEFT] = state;

	glfwSetInputMode(w->getWindow(), GLFW_CURSOR, (m__visibleCursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN));

	if(m__captureCursor)
		glfwSetCursorPos(w->getWindow(), double(w->getWidth())/2, double(w->getHeight())/2);

}
