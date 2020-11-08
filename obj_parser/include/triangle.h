#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <model.h>


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


int read_triangle(Triangle* triangle, const char* text);

#endif /* TRIANGLE_H */
