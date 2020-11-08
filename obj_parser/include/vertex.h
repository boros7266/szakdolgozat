#ifndef VERTEX_H
#define VERTEX_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <model.h>

typedef struct Vertex
{
    double x;
    double y;
    double z;
}Vertex;


int read_vertex(Vertex* vertex, const char* text);

#endif /* VERTEX_H */
