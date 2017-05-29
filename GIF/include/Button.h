/**
 * Button class header
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
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

            Button();
            virtual ~Button();

            void click() { action(); };

            void action();

            bool getPressed() { return m__pressed; };

            void setAction(std::function<void()> action) { m__action = action; };

    };

}

#endif
