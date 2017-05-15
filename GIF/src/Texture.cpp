/**
 * Texture class implementation
 */

#include "Texture.h"

#include <iostream>

using namespace std;
using namespace GIF;

Texture::Texture(string name): m__id(), m__name(name)
{



}


Texture::~Texture()
{



}


void Texture::load()
{

    SOIL_load_OGL_texture(
        (char *)(m__name.c_str()),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

}

