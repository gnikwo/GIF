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

            int m__pressed;

        public:

            Button(std::function<void()> action);
            virtual ~Button();

            void click() { action(); };

            void action();

    };

}

#endif
