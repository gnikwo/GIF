/**
 * Button class implementation
 */

#include "Button.h"

#include <iostream>

// Includes GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;
using namespace GIF;

Button::Button(): Element()
{

    addPoint(vec3(-0.5, -0.5, 0.0));
    addPoint(vec3(-0.5,  0.5, 0.0));
    addPoint(vec3( 0.5, -0.5, 0.0));

    addPoint(vec3(-0.5,  0.5, 0.0));
    addPoint(vec3( 0.5,  0.5, 0.0));
    addPoint(vec3( 0.5, -0.5, 0.0));

}


Button::~Button()
{



}
