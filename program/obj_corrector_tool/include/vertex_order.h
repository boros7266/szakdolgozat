#ifndef VERTEX_ORDER_H
#define VERTEX_ORDER_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

/**
 * Change vertex order function.
 */
void change_vertex_order(Model* model);

/**
 * Change the order of vertices.
 */
void changing_vertex_order(Model* model);

#endif /* VERTEX_ORDER_H */
