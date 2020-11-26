#ifndef TEXTURE_H
#define TEXTURE_H

#include <string.h>

#include <SOIL/SOIL.h>
#include <GL/glut.h>

/**
 * Represents red green blue.
 */
typedef GLubyte Pixel[3];

/**
 * Load texture from file and returns with the texture name.
 */
GLuint load_texture(char* filename);

/**
 * Initialize model texture.
 */
void initialize_texture();

#endif /* TEXTURE_H */
