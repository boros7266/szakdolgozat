#include <stdio.h>
#include "model.h"
#include "bounding_box.h"
#include "vertex.h"


void calc_bounding_box(Model* model,BoundingBox* bounding_box)
{
    int i;
    double x, y, z;

    if (model->n_vertices == 0) {
        return;
    }

    bounding_box->min_x = model->vertices[0].x;
    bounding_box->max_x = model->vertices[0].x;
    bounding_box->min_y = model->vertices[0].y;
    bounding_box->max_y = model->vertices[0].y;
    bounding_box->min_z = model->vertices[0].z;
    bounding_box->max_z = model->vertices[0].z;

    for (i = 0; i < model->n_vertices; ++i) {
        x = model->vertices[i].x;
        y = model->vertices[i].y;
        z = model->vertices[i].z;
        if (x < bounding_box->min_x) {
            bounding_box->min_x = x;
        }
        else if (x > bounding_box->max_x) {
            bounding_box->max_x = x;
        }
        if (y < bounding_box->min_y) {
            bounding_box->min_y = y;
        }
        else if (y > bounding_box->max_y) {
            bounding_box->max_y = y;
        }
        if (z < bounding_box->min_z) {
            bounding_box->min_z = z;
        }
        else if (z > bounding_box->max_z) {
            bounding_box->max_z = z;
        }
    }
}
void print_bounding_box(BoundingBox* bounding_box)
{
    printf("Bounding box:\n");
    printf("x in [%lf, %lf]\n", bounding_box->min_x, bounding_box->max_x);
    printf("y in [%lf, %lf]\n", bounding_box->min_y, bounding_box->max_y);
    printf("z in [%lf, %lf]\n\n", bounding_box->min_z, bounding_box->max_z);
}
