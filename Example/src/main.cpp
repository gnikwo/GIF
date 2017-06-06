#include <iostream>
#include <string>
#include <functional>

#include <GIF.h>
#include <Button.h>
#include <Controller.h>

using namespace std;
using namespace GIF;

int main(int argc, char** argv)
{


    Window* w = Gif::init();

    Gif::createTexture("default", "default.png");
    Gif::createTexture("chef", "503.png");

    Button* b = (Button*) Gif::addElement("Test", new Button());

    b->load();

    b->addTexture("diffuse_1", "default");
    b->addTexture("diffuse_2", "chef");

    w->addElement(b);

    w->bind(GLFW_KEY_ESCAPE, [&w]() {

        w->close();

    });

    b->bind(GLFW_KEY_A, [&b]() {

        b->action();

    });

    float a = 0;
    float x = 0.02;

	while(!w->shouldClose())
	{

        a += x;

        b->setPos(glm::vec2(200, 200));
        //b->setPos(glm::vec2(500 * sin(a), 500 * cos(a)));

        w->check(w);
        w->clickCheck();
        b->check(w);

        w->render();

	}

	Gif::unload();
    return 0;

}
