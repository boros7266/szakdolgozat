#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

/**
 * Triangulation function.
 */
void triangulation_of_quads(Model* model);

/**
 * Rewrite triangles.
 */
void rewriting_triangles(Model* model);

/**
 * Convert quads into triangles.
 */
void converting_quads_to_triangles(Model* model);

/**
 * Allocate memory for triangles and extra triangles.
 */
void create_arrays_triangles(Model* model);

#endif /* TRIANGULATION_H */
