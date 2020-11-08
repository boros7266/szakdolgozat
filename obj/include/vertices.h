#ifndef VERTICES_H
#define VERTICES_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex
{
    double x;
    double y;
    double z;
}Vertex;

int is_numeric(char c);

int read_vertex(Vertex* vertex, const char* text);

#endif /* VERTICES_H */
