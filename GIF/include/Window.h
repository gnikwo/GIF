/***********************
 * Window class header *
 ***********************
 *  Represent an OS    *
 *  window.            *
 *                     *
 ***********************/

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "Element.h"
#include "Controller.h"

namespace GIF
{

    class Window: public GIF::Controller
    {

        private:

            /**
             * GLFW window object
             */
            GLFWwindow* m__window;

            /**
             * Window title
             */
            std::string m__title;

            /**
             * window's width
             */
            int m__width;

            /**
             * window's height
             */
            int m__height;

            /**
             * Window's background color
             */
            glm::vec3 m__backgroundColor;

            /**
             * Window's graphical elements
             */
            std::vector<Element*> m__elements;

            /**
             *
             */
            GLuint m__framebuffer;

            /**
             *
             */
            GLuint m__clickTexture;

            std::map<const int, int> m__lastClickStates;

            bool m__visibleCursor;
            bool m__captureCursor;

            Element* m__focusedElement;

        public:

            /**
             * Constructor
             * @param title title of the window. default = "First window"
             * @param width window's width. default = 512
             * @param heigth window's height. default = 512
             */
            Window(std::string title = "First window", int width = 512, int height = 512);

            /**
             * Destructor
             */
            virtual ~Window();

            /**
             * Loads the window
             */
            void load();


            /**
             *
             */
            void initClickTexture();


            /**
             * Closes the window
             */
            void close();

            /**
             * @return true if the window should close the next render tick
             */
            int shouldClose();

            /**
             * Render the window's content
             */
            void render();

            /**
             *
             */
            void clickRender(glm::mat4 projection = glm::mat4(1.0));


            /**
             *
             */
            void clickCheck();


            /**
             *
             */
            glm::vec3 getClickColor(glm::vec2);

            //=============GETTERS and SETTERS=================

			//Window tout simplement
			GLFWwindow* getWindow(){return m__window;};

			//Height
            void setHeight(int height){ m__height = height; }
			int getHeight(){return m__height;}

			//Width
            void setWidth(int width){ m__width = width; }
			int getWidth(){return m__width;}

            //Background color
            void setbackgroundColor(glm::vec3 color){ m__backgroundColor = color; };
            glm::vec3 getBackgroundColor(){ return m__backgroundColor; };

            //Elements
            void addElement(Element* element){ m__elements.push_back(element); };
            void removeElement(int i){ m__elements.erase(m__elements.begin()+i); };


            void toggleVisibleCursor() { m__visibleCursor = !m__visibleCursor; };
            void toggleCaptureCursor() { m__captureCursor = !m__captureCursor; };





        private:

            /**
             * Window "resize" event callback
             * @param window pointer the concerned GLFWwindow
             * @param width new window's width
             * @param height new window's height
             */
            static void window_size_callback(GLFWwindow* window, int width, int height);

            /**
             * Window "focus change" event callback
             * @param window pointer the concerned GLFWwindow
             * @param state new state of the window, 0 if not in focus, 1 if in focus
             */
            static void window_focus_callback(GLFWwindow* window, int state);

            /**
             * Window "close" event callback
             * @param window pointer the concerned GLFWwindow
             */
            static void window_close_callback(GLFWwindow* window);

            /**
             * Window "mouse moved" event callback
             * @param window pointer the concerned GLFWwindow
             * @param x position of the mouse pointer
             * @param y position of the mouse pointer
             */
            static void mouse_move_callback(GLFWwindow* window, double x, double y);

    };
}

#endif
