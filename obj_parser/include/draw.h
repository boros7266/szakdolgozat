#ifndef DRAW_H
#define DRAW_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

void draw_model(Model* model);

void draw_triangles(Model* model);

void draw_quads(Model* model);

#endif /* DRAW_H */

