#ifndef NORMAL_VERTEX_H
#define NORMAL_VERTEX_H

#include "model.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct NormalVertex
{
    double x;
    double y;
    double z;
}NormalVertex;

/**
 * Read normal vector data.
 */
int read_normal(NormalVertex* normal, const char* text);

#endif /* NORMAL_VERTEX_H */
