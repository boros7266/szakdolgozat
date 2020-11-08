#ifndef TEXTURE_VERTEX_H
#define TEXTURE_VERTEX_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <model.h>

typedef struct TextureVertex
{
    double u;
    double v;
}TextureVertex;


int read_texture_vertex(TextureVertex* texture_vertex, const char* text);

#endif /* TEXTURE_VERTEX_H */
