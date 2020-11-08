#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BoundingBox
{
    double min_x;
    double min_y;
    double min_z;
    double max_x;
    double max_y;
    double max_z;
}BoundingBox;


void calc_bounding_box(Model* model,BoundingBox* bounding_box);

void print_bounding_box(BoundingBox* bounding_box);

#endif /* BOUNDING_BOX_H */
