#ifndef NORMAL_VERTICES_H
#define NORMAL_VERTICES_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NormalVertex
{
    double x;
    double y;
    double z;
}NormalVertex;

int is_numeric(char c);

int read_normal(NormalVertex* normal, const char* text);

#endif /* NORMAL_VERTICES_H */
