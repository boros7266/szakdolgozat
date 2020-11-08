#ifndef TEXTURE_H
#define TEXTURE_H

#include <string.h>
#include <SOIL/SOIL.h>
#include <GL/glut.h>

typedef GLubyte Pixel[3];

typedef struct Texture
{
    int width;
    int height;
}Texture;


void load_texture(char* filename, Texture* texture);

#endif /* TEXTURE_H */
