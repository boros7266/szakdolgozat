#ifndef NORMAL_VERTICLES_H
#define NORMAL_VERTICLES_H

#include <string.h>
#include <stdlib.h>
typedef struct NormalVertex
{
    double x[99999][0];
    double y[99999][1];
    double z[99999][2];
}NormalVertex;

void normal_coords(struct NormalVertex* normalvertex);

#endif /* NORMAL_VERTICLES_H */
