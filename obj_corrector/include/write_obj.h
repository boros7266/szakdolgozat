#ifndef WRITE_OBJ_H
#define WRITE_OBJ_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Write to file function.
 */
int write_to_file(char* filename, Model* model);

/**
 * Write to file vertex data.
 */
void write_to_file_vertices (FILE* file, Model* model);

/**
 * Write to file texture vertex data.
 */
void write_to_file_texture_vertices (FILE* file, Model* model);

/**
 * Write to file normal vertex data.
 */
void write_to_file_normals (FILE* file, Model* model);

/**
 * Write to file triangle data.
 */
void write_to_file_triangles (FILE* file, Model* model);

/**
 * Write to file quad data.
 */
void write_to_file_quads (FILE* file, Model* model);

#endif /* WRITE_OBJ_H */

