#version 120

varying vec2 uv;

uniform sampler2D diffuse_1;
uniform sampler2D diffuse_2;

uniform int pressed;
uniform vec3 clickColor;

void main()
{


    if(pressed > 0)

        gl_FragColor = texture2D(diffuse_2, uv);

    else

        gl_FragColor = texture2D(diffuse_1, uv);

}
