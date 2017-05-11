#include <iostream>
#include <string>

#include <GIF.h>
#include <Button.h>

using namespace std;
using namespace GIF;

int main(int argc, char** argv)
{

    Window* w = Gif::init();

    Button* b = new Button();
    b->load();

    w->addElement(b);

	while(1)
	{

        w->render();

	}

    return 0;

}
