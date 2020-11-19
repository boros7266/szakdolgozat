#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "model.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct FacePoint
{
    int vertex_index;
    int texture_index;
    int normal_index;
} FacePoint;

typedef struct Triangle
{
    struct FacePoint points[3];
} Triangle;

/**
 * Read triangle data.
 */
int read_triangle(Triangle* triangle, const char* text);

#endif /* TRIANGLE_H */
