#include <stdio.h>
#include "texture.h"
#include <SOIL/SOIL.h>
#include <GL/glut.h>

void load_texture(char* filename, Texture* texture)
{
    GLuint texture_name;
    Pixel* image = (Pixel*)SOIL_load_image(filename, &texture->width, &texture->height, 0, SOIL_LOAD_RGB);

    /*glBindTexture(GL_TEXTURE_2D, texture_name);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (Pixel*)image);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    */
    printf("\nTexture name:\t%s\n", filename);
    printf("Width:\t%d\n",texture->width);
    printf("Height:\t%d\n\n",texture->height);
    return ;
}
