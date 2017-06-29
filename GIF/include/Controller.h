#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <map>
#include <algorithm>
#include <functional>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GIF
{

    class Window;

    class Controller
    {

        public:

            Controller();

            void bindPress(const int key, std::function<void()> action);
            void bindPressing(const int key, std::function<void()> action);
            void bindRelease(const int key, std::function<void()> action);
            void unbind(const int key);
            void unbind();

            void check(Window* w);


        private:

            std::map<const int, std::function<void()>> m__keyBindingsPress;
            std::map<const int, std::function<void()>> m__keyBindingsPressing;
            std::map<const int, std::function<void()>> m__keyBindingsRelease;
            std::map<const int, int> m__lastStates;

    };

}

#endif
