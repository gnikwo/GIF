#version 120

attribute vec3 in_Vertex;
attribute vec2 in_TextCoord0;

uniform mat4 projection;
uniform mat4 model;

varying vec2 uv;

void main()
{

    gl_Position = projection * model * vec4(in_Vertex, 1);

    uv = in_TextCoord0;

}
