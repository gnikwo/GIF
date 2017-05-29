/*******************************
 * Window class implementation *
 *******************************/

#include "Window.h"

#include <iostream>
#include <chrono>
#include <cstdlib>

#include "GIF.h"
#include "Thread.h"

using namespace std;
using namespace glm;
using namespace GIF;

GIF::Window::Window(std::string title, int width, int height): Controller(),
                                                                m__window(),
                                                                m__title(title),
                                                                m__width(width),
                                                                m__height(height),
                                                                m__backgroundColor(vec3(0.9, 0.9, 0.9)),
                                                                m__elements(),
                                                                m__framebuffer(),
                                                                m__clickTexture()
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


void GIF::Window::initClickTexture()
{

    glGenFramebuffers(1, &m__framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m__framebuffer);

        // The texture we're going to render to
        glGenTextures(1, &m__clickTexture);

        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, m__clickTexture);

            // Give an empty image to OpenGL ( the last "0" )
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1080, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);

            // Poor filtering. Needed !
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

            // Set "renderedTexture" as our colour attachement #0
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m__clickTexture, 0);

            // Set the list of draw buffers.
            GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
            glDrawBuffers(1, DrawBuffers);

        glBindTexture(GL_TEXTURE_2D, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

void GIF::Window::render()
{

    glfwMakeContextCurrent(m__window);

    int startTime = int(glfwGetTime() * 1000);

        mat4 perspective = glm::ortho(0.0f, (float)m__width, 0.0f, (float)m__height, 0.0f, 100.0f);//glm::perspective(90.0, (double)m__width / m__height, 0.1, 500.0); //

        mat4 view = glm::lookAt( glm::vec3( 0, 0, 1 ), glm::vec3( 0.f, 0.f, 0.f ), glm::vec3( 0.0f, 1.0f, 0.0f ));

        clickRender(perspective * view);

        glViewport(0, 0, m__width, m__height);

        glClearColor(m__backgroundColor.x, m__backgroundColor.y, m__backgroundColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        for(auto &element : m__elements)
        {

            element->render(perspective * view);

        }

    glfwSwapBuffers(m__window);

	glfwPollEvents();

	int endTime = int(glfwGetTime() * 1000);
	int elapsedTime = endTime - startTime;

	//cout << (1.0 / (elapsedTime / 1000.0)) << " fps "<< endl;

    int framerate = 60/1000;
	if(elapsedTime < framerate)
        Thread::sleep(framerate - elapsedTime);

}


void GIF::Window::clickRender(glm::mat4 projection)
{

    glBindFramebuffer(GL_FRAMEBUFFER, m__framebuffer);

        glViewport(0, 0, m__width, m__height);

        glClearColor(0.0, 0.0, 0.0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        for(auto &element : m__elements)
        {

            element->clickRender(projection);

        }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}


void GIF::Window::clickCheck()
{

	double x, y;
	glfwGetCursorPos(getWindow(), &x, &y);
	double dx = x - double(getWidth())/2, dy = y - double(getHeight())/2;

    int state = glfwGetMouseButton(getWindow(), GLFW_MOUSE_BUTTON_LEFT);
    if (m__lastClickStates[GLFW_MOUSE_BUTTON_LEFT] == GLFW_RELEASE && state == GLFW_PRESS)
    {
        cout << "Click: " << x << "/" << m__width << "x " << y << "/" <<m__height <<  "y" << endl;
        Gif::click(this, vec2(x, m__height - y));
    }

    m__lastClickStates[GLFW_MOUSE_BUTTON_LEFT] = state;

	glfwSetInputMode(getWindow(), GLFW_CURSOR, (m__visibleCursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN));

	if(m__captureCursor)
		glfwSetCursorPos(getWindow(), double(getWidth())/2, double(getHeight())/2);

}


vec3 GIF::Window::getClickColor(vec2 pos)
{

    glBindFramebuffer(GL_FRAMEBUFFER, m__framebuffer);
    glBindTexture(GL_TEXTURE_2D, m__clickTexture);

    GLubyte data[3];

    glReadPixels(pos.x, pos.y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, data);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return vec3(data[0], data[1], data[2]);

}


//==============CALLBACKS==========

void GIF::Window::window_size_callback(GLFWwindow* window, int width, int height)
{

	cout << "[Window] window_size_callback(): " << window << ": New size:" << width << "x" << height << endl;

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    w->setWidth(width);
    w->setHeight(height);

}


void GIF::Window::window_focus_callback(GLFWwindow* window, int state)
{

	cout << "[Window] window_focus_callback(): " << window << ": " << state << endl;

}

void GIF::Window::window_close_callback(GLFWwindow* window)
{

	cout << "[Window] window_close_callback(): " << window << endl;

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

	w->close();

}

void GIF::Window::mouse_move_callback(GLFWwindow* window, double x, double y)
{

	cout << "[Window] mouse_move_callback(): " << window << ": New pos:" << x << "x " << y << "y" << endl;

    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    vec3 res = w->getClickColor(vec2(x, y));

	cout << "[Window] Click: " << res.x  << endl;

}


void GIF::Window::close()
{

	glfwSetWindowShouldClose(m__window, GL_TRUE);

}

int GIF::Window::shouldClose()
{
	return glfwWindowShouldClose(m__window);
}
