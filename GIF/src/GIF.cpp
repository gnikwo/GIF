/********************************
 * GIF interface implementation *
 ********************************/

#include "GIF.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
using namespace glm;
using namespace GIF;

Library<Texture>* Gif::m__textureLibrary = new Library<Texture>();
Library<Window>* Gif::m__windowLibrary = new Library<Window>();
Library<Element>* Gif::m__elementLibrary = new Library<Element>();

using GIF::Window;

Gif::Gif()
{


}


Gif::~Gif()
{

    delete(m__textureLibrary);
    delete(m__windowLibrary);
    delete(m__elementLibrary);

}


/**
 * Initialize Glfw and Glew and returns a Window
 * @return returns a window
 **/
Window* Gif::init()
{

	cout << "[GIF] init" << endl;

    /* initialize random seed: */
    srand (time(NULL));

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {

		std::cout << "Failed to initialize GLFW\n";
		return nullptr;

	}

	//=====================

    Window* w = Gif::createWindow("Window_1", "Test");
	w->load();

	//=====================

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //OpenGL 4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	// On initialise GLEW
	GLenum initialisationGLEW(glewInit());

	// Si l'initialisation a �chou� :
	if (initialisationGLEW != GLEW_OK)
	{

		// On affiche l'erreur gr�ce � la fonction : glewGetErrorString(GLenum code)
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;

		glfwTerminate();
		exit(EXIT_FAILURE);

	}

    w->initClickTexture();

	return w;
}


void Gif::unload()
{

    cout << "[Gif] unload" << endl;

	Gif::m__windowLibrary->flush();
	Gif::m__textureLibrary->flush();

	glfwTerminate();

}


Window* Gif::createWindow(string id, string title)
{

    Window* w = new Window(title);

    m__windowLibrary->add(id, w);

    return w;

}


Element* Gif::addElement(std::string id, Element* element)
{

    m__elementLibrary->add(id, element);

    return element;

}


Texture* Gif::createTexture(string id, string name)
{

    Texture* t = new Texture(name);
    t->load();

    m__textureLibrary->add(id, t);

    return t;

}


Texture* Gif::getTexture(string name)
{

    if(m__textureLibrary->has(name))

        return m__textureLibrary->get(name);

    return nullptr;

}


bool Gif::click(Window* w, vec2 pos)
{

    vec3 color = w->getClickColor(pos);

    cout << "Test 1: " << color.x << endl;

    for(auto iter : m__elementLibrary->getMap())
    {

        cout << "Test 2: " << iter.second->getClickColor().x << endl;
        if(color == iter.second->getClickColor())
        {

            iter.second->click();
            return true;

        }

    }

    return false;

}


//==========CALLBACKS========

void Gif::error_callback(int error, const char* description)
{
	cout << "[Gif] error_callback() :" << error << " : " << description << "\n";
}
