/************************
 * GIF interface header *
 ************************
 *  GIF interface       *
 * interacts with the   *
 * framework            *
 ************************/

#ifndef GIF_H
#define GIF_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Texture.h"
#include "Library.h"

namespace GIF
{

    class Gif
    {

        public:

            static Window* init();
            static void unload();

            static Window* createWindow(std::string id, std::string title);
            static Texture* createTexture(std::string id, std::string name);

            static Window* addWindow(std::string id, GIF::Window* window);
            static Element* addElement(std::string, GIF::Element* element);

            static Texture* getTexture(std::string name);

            static Element* click(Window* w, glm::vec2 pos);

        private:

            Gif();
            virtual ~Gif();

            static void error_callback(int error, const char* description);

			static Library<Texture>* m__textureLibrary;
            static Library<Window>* m__windowLibrary;
            static Library<Element>* m__elementLibrary;
            static std::map<glm::vec3, Element*> m__elementByColor;

    };

}

#endif

