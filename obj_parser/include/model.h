#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>

#define geometric_vertices 	"^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*" 		//List of geometric vertices
#define vertex_normals          "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of texture coordinates
#define texture_coordinates     "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of vertex normals
#define face_elements           "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //Polygonal face elements
#define space_vertices          "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //Parameter space vertices
#define triangles		"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){3}[\\ ]*$"		//Parameter triangle
#define polygons		"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){4}[\\ ]*"		//Parameter quads

#define BUFFER_SIZE 1024

#define TRUE 1
#define FALSE 0

typedef struct Vertex
{
    double x[99999][0];
    double y[99999][1];
    double z[99999][2];
}Vertex;

typedef struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_spaces;
    int n_faces;
    int n_triangles;
    int n_polygons;
}Model;


int load_model(char* filename,struct Model* model);

void init_model_counters(struct Model* model);

void n_coords(FILE* file, struct Model* model);

void print_model_info(const struct Model* model);

void print_bounding_box(struct Model*model,struct Vertex* vertex);

#endif /* MODEL_H */
