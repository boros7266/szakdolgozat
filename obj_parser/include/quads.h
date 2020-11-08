#ifndef QUADS_H
#define QUADS_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "triangles.h"


typedef struct Quad
{
    struct FacePoint points[4];
} Quad;


int read_quad(Quad* Quad, const char* text);

#endif /* QUADS_H */
