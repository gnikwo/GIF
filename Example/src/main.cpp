#include <iostream>
#include <string>
#include <functional>

#include <GIF.h>
#include <Button.h>
#include <Box.h>
#include <Controller.h>

#include "LeftArrow.h"
#include "RightArrow.h"

using namespace std;
using namespace GIF;

int main(int argc, char** argv)
{


    Window* w = Gif::init();

    Gif::createTexture("default", "power.png");
    Gif::createTexture("pressed", "power_red.png");
    Gif::createTexture("background", "background.png");
    Gif::createTexture("rocket", "rocket.png");

    Button* power = (Button*) Gif::addElement("Power", new Button());

    power->load();
    power->addTexture("diffuse_1", "default");
    power->addTexture("diffuse_2", "pressed");


    Box* back = (Box*) Gif::addElement("Background", new Box());
    back->load();
    back->addTexture("diffuse", "background");
    back->setSize(glm::vec2(1280, 768));

    LeftArrow* left = (LeftArrow*) Gif::addElement("Left", new LeftArrow());
    left->load();
    left->setColor(glm::vec3(0.0));
    left->setPressedColor(glm::vec3(0.8, 0.0, 0.0));

    RightArrow* right = (RightArrow*) Gif::addElement("Right", new RightArrow());
    right->load();
    right->setColor(glm::vec3(0.0));
    right->setPressedColor(glm::vec3(0.8, 0.0, 0.0));

    Box* player = (Box*) Gif::addElement("Player", new Box());
    player->load();
    player->addTexture("diffuse", "rocket");

    w->addElement(power);
    w->addElement(back);
    w->addElement(left);
    w->addElement(right);
    w->addElement(player);

    w->bindPress(GLFW_KEY_ESCAPE, [&w]() {

        w->close();

    });

    power->bindPress(GLFW_KEY_SPACE, [&power]() {

        power->action();

    });


    int leftKey = GLFW_KEY_A;
    int rightKey = GLFW_KEY_D;

    left->bindPressing(leftKey, [&left]() {

        left->action();

    });

    right->bindPressing(rightKey, [&right]() {

        right->action();

    });


    float a = 0;
    float x = 0;

    float playerPos = 590;

    power->setAction([&a, &power]() {

        a = 1;
        power->unbind();

    });

    left->setAction([&playerPos]() {

        playerPos -= 10;

    });

    right->setAction([&playerPos]() {

        playerPos += 10;

    });

    //screen size: 1280x763
    float offset = 0;

	while(!w->shouldClose())
	{

        offset = a ? (0.001*(x*x*x*x) - 5*x) : offset;
        x += a ? 0.7 : 0;

        power->setPos(glm::vec3(590, offset + 431, 0.1));

        back->setPos(glm::vec3(0, offset + 763, 0));
        left->setPos(glm::vec3(206, offset - 600, 0.3));
        right->setPos(glm::vec3(974, offset - 600, 0.3));

        player->setPos(glm::vec3(playerPos, offset - 400, 0.2));

        if(offset >= 763){

            a = 0;

            offset = 763;

        }

        w->check(w);
        w->clickCheck();
        power->check(w);
        left->check(w);
        right->check(w);

        w->render();

        left->setPressed(false);
        right->setPressed(false);

	}

	Gif::unload();
    return 0;

}
