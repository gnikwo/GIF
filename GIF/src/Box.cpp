/**
 * Box class implementation
 */

#include "Box.h"

#include <iostream>

// Includes GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;
using namespace GIF;

Box::Box(): Element()
{

    Shader* shader = new Shader("Box");
    shader->load();

    setShader(shader);

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

}

