#include "write_to.h"

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
    else if (model->n_quads > 0)
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
        x = model->vertices[i].x;
	fprintf(file,"v ");
	fprintf(file,"%lf ",x);
        y = model->vertices[i].y;
	fprintf(file,"%lf ",y);
        z = model->vertices[i].z;
	fprintf(file,"%lf\n",z);
 	}
	fprintf(file,"\n");
}

void write_to_file_texture_vertices (FILE* file, Model* model)
{
	int i;
	double u, v;
	for (i = 1; i < model->n_texture_vertices; ++i) {
        u = model->texture_vertices[i].u;
	fprintf(file,"vt ");
	fprintf(file,"%lf ",u);
        v = model->texture_vertices[i].v;
	fprintf(file,"%lf\n",v);
	}
	fprintf(file,"\n");
}

void write_to_file_normals (FILE* file, Model* model)
{
	int i;
	double x, y, z;
	for (i = 1; i < model->n_normals; ++i) {
	x = model->normals[i].x;
        fprintf(file,"vn ");
	fprintf(file,"%lf ",x);
        y = model->normals[i].y;
	fprintf(file,"%lf ",y);
        z = model->normals[i].z;
	fprintf(file,"%lf\n",z);
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
	fprintf(file,"%i",vertex_index);
	fprintf(file,"/");
	texture_index = model->triangles[i].points[k].texture_index;
	fprintf(file,"%i",texture_index);
	fprintf(file,"/");
	normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%i",normal_index);
	fprintf(file," ");
	}
	fprintf(file,"\n");
    }
}

void write_to_file_quads (FILE* file, Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	for (i = 0; i < model->n_triangles; ++i) {
	fprintf(file,"f ");
	for (k = 0; k < 4; ++k) {
	vertex_index = model->triangles[i].points[k].vertex_index;
	fprintf(file,"%i",vertex_index);
	fprintf(file,"/");
	texture_index = model->triangles[i].points[k].texture_index;
	fprintf(file,"%i",texture_index);
	fprintf(file,"/");
	normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%i",normal_index);
	fprintf(file," ");
	}
	fprintf(file,"\n");
    }
}
