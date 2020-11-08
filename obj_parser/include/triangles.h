#ifndef TRIANGLES_H
#define TRIANGLES_H

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

int is_numeric(char c);

int read_triangle(Triangle* triangle, const char* text);

#endif /* TRIANGLES_H */
