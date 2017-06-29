#version 120

varying vec2 uv;

uniform sampler2D diffuse;

void main()
{

    gl_FragColor = texture2D(diffuse, uv);

}
