#ifndef QUAD_H
#define QUAD_H

#include "triangle.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Quad
{
    struct FacePoint points[4];
} Quad;

/**
 * Read quad data.
 */
int read_quad(Quad* Quad, const char* text);

#endif /* QUAD_H */
