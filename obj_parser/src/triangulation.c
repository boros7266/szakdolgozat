#include <stdio.h>
#include "triangulation.h"

#include <stdbool.h>

int write_to_file_triangular(char* filename, Model* model)
{
    FILE* triangular_file = fopen(filename, "w");
    if (triangular_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return false;
    }
	printf("\nCreate ..\n");
		create_arrays_triangulation(model);
	printf("Convert ..\n");
   		convert_quads_to_triangles(model);
	printf("Print model info ..\n");
		print_model_info(model);
	return true;
}

void convert_quads_to_triangles(Model* model)
{
	int i,k,x,y;
	y = model->n_quads;
	x = model->n_quads*2;
	for (i = 0; i < y; ++i) {
		for (k = 0; k < 3; ++k) {
	model->triangles[i].points[k].vertex_index  = model->quads[i].points[k].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i].points[k].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i].points[k].normal_index;
		}
	model->n_triangles++;
	}
	for (i = y; i < x; ++i) {
		for (k = 0; k < 3; ++k) {
	if (k==0){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y].points[k].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y].points[k].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y].points[k].normal_index;
	}
	else if(k==1){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y].points[k+1].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y].points[k+1].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y].points[k+1].normal_index;	
	}
	else if(k==2){
	model->triangles[i].points[k].vertex_index  = model->quads[i-y].points[k+1].vertex_index;
	model->triangles[i].points[k].texture_index = model->quads[i-y].points[k+1].texture_index;
	model->triangles[i].points[k].normal_index = model->quads[i-y].points[k+1].normal_index;
		}
	}
	model->n_faces++;
	model->n_triangles++;
	model->n_quads--;
	}
}

void create_arrays_triangulation(Model* model)
{
    model->triangles =(Triangle*)malloc((model->n_quads*2+model->n_triangles) * sizeof(Triangle));
}
