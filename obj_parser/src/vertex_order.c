#include <stdio.h>
#include "vertex_order.h"

#include <stdbool.h>

void change_vertex_order(Model* model)
{
	printf("\nChange ..\n");
		changing_vertex_order (model);
	printf("Print model info: ..\n");
		print_model_info(model);
	printf("\nVerices orders have changed!\n");
}

void changing_vertex_order (Model* model)
{
	int i, k;
	int vertex,texture;
	for (i = 0; i < model->n_triangles; ++i) {
	for (k = 0; k < 3; ++k) {
	if (k==0){
	model->triangles[i].points[k].vertex_index = model->triangles[i].points[k].vertex_index;
	model->triangles[i].points[k].texture_index = model->triangles[i].points[k].texture_index;
	model->triangles[i].points[k].normal_index = model->triangles[i].points[k].normal_index;
	}
	else if (k==1){
	vertex = model->triangles[i].points[k].vertex_index;
	texture =model->triangles[i].points[k].texture_index;
	model->triangles[i].points[k].vertex_index = model->triangles[i].points[k+1].vertex_index;
	model->triangles[i].points[k].texture_index = model->triangles[i].points[k+1].texture_index;
	
	}
	else if (k==2){
	model->triangles[i].points[k].vertex_index = vertex;
	model->triangles[i].points[k].texture_index = texture;
	}
	}
    }
}
