#include <iostream>
#include <string>

#include <GIF.h>

using namespace std;
using namespace GIF;

int main(int argc, char** argv)
{

    Window* w = Gif::init();

	while(1)
	{

        w->render();

	}

    return 0;

}
