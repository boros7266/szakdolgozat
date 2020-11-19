#include "triangulation.h"

#include <stdio.h>

void triangulation_of_quads(Model* model)
{
	if (model->n_quads != 0){
	printf("Convert ..\n");
		rewriting_triangles(model);
   		converting_quads_to_triangles(model);
	printf("Print model info ..\n");
		print_model_info(model);
	printf("\nQuads converted to Triangles!\n");
	}
	else{
	printf("\nThere is no Quad in the Object!\n");
	}
}

void rewriting_triangles(Model* model)
{
	int i, k;
	int vertex[model->n_triangles][3];
	int texture[model->n_triangles][3];
	int normal[model->n_triangles][3];
	for (i = 0; i < model->n_triangles; ++i) {
	for (k = 0; k < 3; ++k) {
	vertex [i][k] = model->triangles[i].points[k].vertex_index;
	texture [i][k] = model->triangles[i].points[k].texture_index;
	normal [i][k] = model->triangles[i].points[k].normal_index;
	}
    }
	create_arrays_triangles(model);
	for (i = 0; i < model->n_triangles; ++i) {
	for (k = 0; k < 3; ++k) {
	model->triangles[i].points[k].vertex_index = vertex [i][k];
	model->triangles[i].points[k].texture_index = texture [i][k];
	model->triangles[i].points[k].normal_index = normal [i][k];
	}
    }
}

void converting_quads_to_triangles(Model* model)
{
	int i,k,x,y,z;
	y = model->n_quads;
	z = model->n_triangles;
	x = (model->n_quads*2);
	for (i = z; i < (z+y); ++i) {
		for (k = 0; k < 3; ++k) {
	model->triangles[i].points[k].vertex_index  = model->quads[i-z].points[k].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-z].points[k].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-z].points[k].normal_index;
		}
	model->n_triangles++;
	}
	for (i = (y+z); i < (x+z); ++i) {
	model->n_faces++;
	model->n_triangles++;
	model->n_quads--;
		for (k = 0; k < 3; ++k) {
	if (k==0){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y-z].points[k].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y-z].points[k].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y-z].points[k].normal_index;
	}
	else if(k==1){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y-z].points[k+1].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y-z].points[k+1].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y-z].points[k+1].normal_index;	
	}
	else if(k==2){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y-z].points[k+1].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y-z].points[k+1].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y-z].points[k+1].normal_index;
		}
	}
	}
}

void create_arrays_triangles(Model* model)
{
    model->triangles =(Triangle*)malloc(((model->n_quads*2)+model->n_triangles) * sizeof(Triangle));
}
