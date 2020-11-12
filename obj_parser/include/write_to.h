#ifndef WRITE_TO_H
#define WRITE_TO_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int write_to_file(char* filename, Model* model);

void write_to_file_vertices (FILE* file, Model* model);

void write_to_file_texture_vertices (FILE* file, Model* model);

void write_to_file_normals (FILE* file, Model* model);

void write_to_file_triangles (FILE* file, Model* model);

void write_to_file_quads (FILE* file, Model* model);

#endif /* WRITE_TO_H */

