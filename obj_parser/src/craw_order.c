#include <stdio.h>
#include "craw_order.h"

#include <stdbool.h>

int write_to_file_craw_order(char* filename,Triangle* triangle, Model* model)
{
    FILE* craw_order_file = fopen(filename, "w");
    if (craw_order_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return false;
    }
	write_to_file_craw_order_vertices(craw_order_file,model);
	write_to_file_craw_order_texture_vertices(craw_order_file,model);
	write_to_file_craw_order_normals(craw_order_file,model);
	write_to_file_craw_order_quads (craw_order_file,model);
	write_to_file_craw_order_triangles (craw_order_file,triangle,model);
	return true;
}

void write_to_file_craw_order_vertices (FILE* file, Model* model)
{
	int i;
	double x, y, z;
	for (i = 1; i < model->n_vertices; ++i) {
	fprintf(file,"v ");
        x = model->vertices[i].x;
        y = model->vertices[i].y;
        z = model->vertices[i].z;
	fprintf(file,"%lf %lf %lf\n",x,y,z);
 	}
	fprintf(file,"\n");
}

void write_to_file_craw_order_texture_vertices (FILE* file, Model* model)
{
	int i;
	double u, v;
	for (i = 1; i < model->n_texture_vertices; ++i) {
	fprintf(file,"vt ");
        u = model->texture_vertices[i].u;
        v = model->texture_vertices[i].v;
	fprintf(file,"%lf %lf\n",u,v);
	}
	fprintf(file,"\n");
}

void write_to_file_craw_order_normals (FILE* file, Model* model)
{
	int i;
	double x, y, z;
	for (i = 1; i < model->n_normals; ++i) {
	fprintf(file,"vn ");
	x = model->normals[i].x;
        y = model->normals[i].y;
        z = model->normals[i].z;
	fprintf(file,"%lf %lf %lf\n",x,y,z);
 	}
	fprintf(file,"\n");
}

void write_to_file_craw_order_quads (FILE* file, Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	for (i = 0; i < model->n_quads; ++i) {
	fprintf(file,"f ");
	for (k = 0; k < 4; ++k) {
	vertex_index = model->quads[i].points[k].vertex_index;
	texture_index = model->quads[i].points[k].texture_index;
	normal_index = model->quads[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",vertex_index,texture_index,normal_index);
	}
	fprintf(file,"\n");
    }
}

void write_to_file_craw_order_triangles (FILE* file,Triangle* triangle, Model* model)
{
	int i, k;
	for (i = 0; i < model->n_triangles; ++i) {
	fprintf(file,"f ");
	for (k = 0; k < 3; ++k) {
	if (k==0){
	triangle->points[k].vertex_index = model->triangles[i].points[k].vertex_index;
	triangle->points[k].texture_index = model->triangles[i].points[k].texture_index;
	triangle->points[k].normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",triangle->points[k].vertex_index,triangle->points[k].texture_index,triangle->points[k].normal_index);
	}
	else if (k==1){
	triangle->points[k].vertex_index = model->triangles[i].points[k+1].vertex_index;
	triangle->points[k].texture_index = model->triangles[i].points[k+1].texture_index;
	triangle->points[k].normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",triangle->points[k].vertex_index,triangle->points[k].texture_index,triangle->points[k].normal_index);
	}
	else if (k==2){
	triangle->points[k].vertex_index = model->triangles[i].points[k-1].vertex_index;
	triangle->points[k].texture_index = model->triangles[i].points[k-1].texture_index;
	triangle->points[k].normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",triangle->points[k].vertex_index,triangle->points[k].texture_index,triangle->points[k].normal_index);
	}
	}
	fprintf(file,"\n");
    }
}
