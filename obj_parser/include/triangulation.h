#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

int write_to_file_triangular(char* filename,Triangle* triangle, Model* model);

void write_to_file_triangular_vertices (FILE* file, Model* model);

void write_to_file_triangular_texture_vertices (FILE* file, Model* model);

void write_to_file_triangular_normals (FILE* file, Model* model);

void write_to_file_triangular_triangles (FILE* file, Model* model);

void polygon_triangulation(FILE* file,Triangle* triangle,Model* model);

void polygon_triangulation_extra(FILE* file,Triangle* triangle,Model* model);

#endif /* TRIANGULATION_H */
