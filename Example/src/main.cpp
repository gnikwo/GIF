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

    Button* b = (Button*) Gif::addElement("Test", new Button([](){
            cout << "plop" << endl;
    }));

    b->load();

    b->addTexture("diffuse_1", "default");
    b->addTexture("diffuse_2", "chef");

    b->setPos(glm::vec2(1.0, 1.0));

    w->addElement(b);

	Controller* controller = new Controller(); // a Controller to bind the ESCAPE key to the Window

    controller->bind(GLFW_KEY_ESCAPE, [&w](double x, double y) {

        w->close();

    });

    controller->bind(GLFW_KEY_A, [&b](double x, double y) {

        b->action();

    });

	while(!w->shouldClose())
	{

        controller->check(w);

        w->render();

	}

    delete(controller);
    delete(b);

	Gif::unload();
    return 0;

}
