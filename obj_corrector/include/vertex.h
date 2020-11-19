#ifndef VERTEX_H
#define VERTEX_H

#include "model.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex
{
    double x;
    double y;
    double z;
}Vertex;

/**
 * Read vertex data.
 */
int read_vertex(Vertex* vertex, const char* text);

#endif /* VERTEX_H */
