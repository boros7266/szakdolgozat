#include <stdio.h>
#include "model.h"
#include "texture_box.h"
#include "texture_vertex.h"

void calc_texture_box(Model* model,TextureBox* texture_box)
{
    int i;
    double u, v;

    if (model->n_texture_vertices == 0) {
        return;
    }

    texture_box->min_u = model->texture_vertices[0].u;
    texture_box->max_u = model->texture_vertices[0].u;
    texture_box->min_v = model->texture_vertices[0].v;
    texture_box->max_v = model->texture_vertices[0].v;

    for (i = 0; i < model->n_texture_vertices; ++i) {
        u = model->texture_vertices[i].u;
        v = model->texture_vertices[i].v;
        if (u < texture_box->min_u) {
            texture_box->min_u = u;
        }
        else if (u > texture_box->max_u) {
            texture_box->max_u = u;
        }
        if (v < texture_box->min_v) {
            texture_box->min_v = v;
        }
        else if (v > texture_box->max_v) {
            texture_box->max_v = v;
        }
    }
	
    print_texture_box(texture_box);
}

void print_texture_box(TextureBox* texture_box)
{
    printf("Texture box:\n");
    printf("u in [%lf, %lf]\n", texture_box->min_u, texture_box->max_u);
    printf("v in [%lf, %lf]\n", texture_box->min_v, texture_box->max_v);
}
