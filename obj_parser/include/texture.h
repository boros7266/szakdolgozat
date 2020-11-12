#ifndef TEXTURE_H
#define TEXTURE_H

#include <string.h>
#include <SOIL/SOIL.h>
#include <GL/glut.h>

typedef GLubyte Pixel[3];

GLuint load_texture(char* filename);

#endif /* TEXTURE_H */
