#ifndef TEXTURE_VERTICLES_H
#define TEXTURE_VERTICLES_H

#include <string.h>
#include <stdlib.h>
typedef struct TextureVertex
{
    double u[99999][0];
    double v[99999][1];
}TextureVertex;

void texture_coords(struct TextureVertex* texturevertex);

#endif /* TEXTURE_VERTICLES_H */
