#ifndef QUAD_H
#define QUAD_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "triangle.h"


typedef struct Quad
{
    struct FacePoint points[4];
} Quad;


int read_quad(Quad* Quad, const char* text);

#endif /* QUAD_H */