/**
 * Button class header
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <functional>

#include "Element.h"

namespace GIF{

    class Button: public Element
    {

        private:

            std::function<void()> m__action;

        public:

            Button(std::function<void()> action, std::string textureName = "default");
            virtual ~Button();

            void action();

    };

}

#endif
