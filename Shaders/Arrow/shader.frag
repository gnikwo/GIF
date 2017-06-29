#version 120

varying vec2 uv;

uniform vec3 color;
uniform vec3 pressedColor;

uniform int pressed;
uniform vec3 clickColor;

void main()
{


    if(pressed > 0)

        gl_FragColor = vec4(pressedColor, 1.0);

    else

        gl_FragColor = vec4(color, 1.0);

}
