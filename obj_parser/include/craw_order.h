#ifndef CRAW_ORDER_H
#define CRAW_ORDER_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

int write_to_file_craw_order(char* filename,Triangle* triangle, Model* model);

void write_to_file_craw_order_vertices (FILE* file, Model* model);

void write_to_file_craw_order_texture_vertices (FILE* file, Model* model);

void write_to_file_craw_order_normals (FILE* file, Model* model);

void write_to_file_craw_order_quads (FILE* file, Model* model);

void write_to_file_craw_order_triangles (FILE* file,Triangle* triangle, Model* model);

#endif /* CRAW_ORDER_H */
