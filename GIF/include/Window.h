#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace GIF
{

    class Window{

        private:

            GLFWwindow* m__window;

            std::string m__title;

            int m__width;
            int m__height;

            //glm::vec3 m__backgroundColor;

        public:

            Window(std::string title = "First window", int width = 512, int height = 512);
            virtual ~Window();

            void load();

            void close();

            int shouldClose();

            void render();

        private:

            static void error_callback(int error, const char* description);

            static void window_size_callback(GLFWwindow* window, int width, int height);
            static void window_focus_callback(GLFWwindow* window, int state);
            static void window_close_callback(GLFWwindow* window);
            static void mouse_move_callback(GLFWwindow* window, double x, double y);

    };

}

#endif
