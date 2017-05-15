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

        private:

            Gif();
            virtual ~Gif();

            static void error_callback(int error, const char* description);
			static Library<Texture>* m__textureLibrary;
            static Library<Window>* m__windowLibrary;

    };

}

#endif

