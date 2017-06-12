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

Button::Button(): Element(), m__action(), m__pressed(false)
{

    addPoint(vec3( 0.0, -1.0, 0.0));
    addPoint(vec3( 0.0,  0.0, 0.0));
    addPoint(vec3( 1.0, -1.0, 0.0));

    addUV(vec2( 0.0, 0.0));
    addUV(vec2( 0.0, 1.0));
    addUV(vec2( 1.0, 0.0));

    addPoint(vec3( 0.0,  0.0, 0.0));
    addPoint(vec3( 1,  0.0, 0.0));
    addPoint(vec3( 1.0, -1.0, 0.0));

    addUV(vec2( 0.0, 1.0));
    addUV(vec2( 1.0, 1.0));
    addUV(vec2( 1.0, 0.0));

    addIntUniform("pressed", &(m__pressed));

}


void Button::action()
{

    m__pressed = !m__pressed;

    if(m__action)
        m__action();

}
