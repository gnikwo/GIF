#version 120

varying vec2 uv;

uniform sampler2D diffuse_1;
uniform sampler2D diffuse_2;

uniform int pressed;
uniform vec3 clickColor;

void main()
{

    gl_FragData[0] = vec4(clickColor / 255.0, 1.0);

}
