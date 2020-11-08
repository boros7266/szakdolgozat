#ifndef TEXTURE_VERTICES_H
#define TEXTURE_VERTICES_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TextureVertex
{
    double u;
    double v;
}TextureVertex;

int is_numeric(char c);

int read_texture_vertex(TextureVertex* texture_vertex, const char* text);

#endif /* TEXTURE_VERTICES_H */
