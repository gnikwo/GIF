#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <map>
#include <algorithm>
#include <functional>

// Includes GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GIF
{

    class Window;

    class Controller
    {

        public:

            Controller();
            virtual ~Controller();

            void bind(const int key, std::function<void(double x, double y)> action);
            void unbind(const int key);
            void unbind();

            void check(Window* w);


            void toggleVisibleCursor() { m__visibleCursor = !m__visibleCursor; };
            void toggleCaptureCursor() { m__captureCursor = !m__captureCursor; };

        private:

            std::map<const int, std::function<void(double x, double y)>> m__keyBindings;
            std::map<const int, int> m__lastStates;
            std::map<const int, int> m__lastClickStates;

            bool m__visibleCursor;
            bool m__captureCursor;

    };

}

#endif
