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

    Button* b = new Button([](){
            cout << "plop" << endl;
    });

    b->load();

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

	Gif::unload();
    return 0;

}
