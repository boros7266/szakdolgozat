#include "write_obj.h"

#include <stdio.h>
#include <stdbool.h>

int write_to_file(char* filename, Model* model)
{
    FILE* output_file = fopen(filename, "w");
    if (output_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return false;
    }
	write_to_file_vertices(output_file,model);
	write_to_file_texture_vertices(output_file,model);
	write_to_file_normals(output_file,model);
    if (model->n_triangles > 0)
	{
	write_to_file_triangles(output_file,model);
	}
    if (model->n_quads > 0)
	{
	write_to_file_quads(output_file,model);
	}
	return true;
}
void write_to_file_vertices (FILE* file, Model* model)
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

void write_to_file_texture_vertices (FILE* file, Model* model)
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

void write_to_file_normals (FILE* file, Model* model)
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

void write_to_file_triangles (FILE* file, Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	for (i = 0; i < model->n_triangles; ++i) {
	fprintf(file,"f ");
	for (k = 0; k < 3; ++k) {
	vertex_index = model->triangles[i].points[k].vertex_index;
	texture_index = model->triangles[i].points[k].texture_index;
	normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",vertex_index,texture_index,normal_index);
	}
	fprintf(file,"\n");
    }
}

void write_to_file_quads (FILE* file, Model* model)
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
