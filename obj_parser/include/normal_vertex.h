#ifndef NORMAL_VERTEX_H
#define NORMAL_VERTEX_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <model.h>


typedef struct NormalVertex
{
    double x;
    double y;
    double z;
}NormalVertex;


int read_normal(NormalVertex* normal, const char* text);

#endif /* NORMAL_VERTEX_H */
