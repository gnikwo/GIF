/************************
 * Texture class header *
 ************************
 *                      *
 *                      *
 *                      *
 ************************/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <GL/glew.h>
#include <SOIL.h>

namespace GIF{

    class Texture
    {

        private:

            /**
             *
             */
            GLuint m__id;

            /**
             *
             */
            std::string m__name;

        public:

            /**
             *
             */
            Texture(std::string name = "default.png");

            /**
             *
             */
            virtual ~Texture();

            /**
             *
             */
            void load();

            /**
             *
             */
            GLuint getID() { return m__id; };

    };

}

#endif
