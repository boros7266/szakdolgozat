#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

int write_to_file_triangular(char* filename, Model* model);

void convert_quads_to_triangles(Model* model);

void create_arrays_triangulation(Model* model);

#endif /* TRIANGULATION_H */
