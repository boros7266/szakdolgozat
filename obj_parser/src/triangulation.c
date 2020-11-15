#include <stdio.h>
#include "triangulation.h"

int write_to_file_triangular(char* filename, Model* model)
{
    FILE* triangular_file = fopen(filename, "w");
    if (triangular_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return false;
    }
	write_to_file_triangular_vertices(triangular_file,model);
	write_to_file_triangular_texture_vertices(triangular_file,model);
	write_to_file_triangular_normals(triangular_file,model);
	write_to_file_triangular_triangles (triangular_file,model);
   	polygon_triangulation(triangular_file,model);
	return true;
}

void write_to_file_triangular_vertices (FILE* file, Model* model)
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

void write_to_file_triangular_texture_vertices (FILE* file, Model* model)
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

void write_to_file_triangular_normals (FILE* file, Model* model)
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

void write_to_file_triangular_triangles (FILE* file, Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	for (i = 0; i < model->n_triangles; ++i) {
	fprintf(file,"f ");
	for (k = 0; k < 3; ++k) {
	vertex_index = model->triangles[i].points[k].vertex_index;
	texture_index = model->triangles[i].points[k].texture_index;
	normal_index = model->triangles[i].points[k].normal_index;
	fprintf(file,"%i/%i/%i ",vertex_index,texture_index,normal_index);
	}
	fprintf(file,"\n");
    }
}


void polygon_triangulation(FILE* file,Model* model)
{
int i,k;
int v, vt, vn;
	for (i = 0; i < model->n_quads; ++i) {
	fprintf(file,"f ");
		for (k = 0; k < 3; ++k) {
	v = model->quads[i].points[k].vertex_index;
	vt = model->quads[i].points[k].texture_index;
	vn = model->quads[i].points[k].normal_index;
	fprintf(file,"%d/%d/%d ",v,vt,vn);
	}
	fprintf(file,"\n");
	}
	polygon_triangulation_extra(file,model);
}
void polygon_triangulation_extra(FILE* file,Model* model)
{
int i,k;
int v, vt, vn;
	for (i = 0; i < model->n_quads; ++i) {
	fprintf(file,"f ");
		for (k = 0; k < 3; ++k) {
	if (k==0){
	v = model->quads[i].points[k].vertex_index;
	vt = model->quads[i].points[k].texture_index;
	vn = model->quads[i].points[k].normal_index;	
	fprintf(file,"%d/%d/%d ",v,vt,vn);
	}
	else if(k==1){
	v = model->quads[i].points[k+1].vertex_index;
	vt = model->quads[i].points[k+1].texture_index;
	vn = model->quads[i].points[k+1].normal_index;	
	fprintf(file,"%d/%d/%d ",v,vt,vn);
	}
	else if(k==2){
	v = model->quads[i].points[k+1].vertex_index;
	vt = model->quads[i].points[k+1].texture_index;
	vn = model->quads[i].points[k+1].normal_index;	
	fprintf(file,"%d/%d/%d ",v,vt,vn);
		}
	}
	fprintf(file,"\n");
	}
}
