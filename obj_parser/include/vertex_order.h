#ifndef VERTEX_ORDER_H
#define VERTEX_ORDER_H

#include "model.h"
#include "normal_vertex.h"
#include "texture_vertex.h"
#include "vertex.h"
#include "triangle.h"
#include "quad.h"

int write_to_file_craw_order(char* filename,Model* model);

void change_vertex_order (Model* model);

#endif /* VERTEX_ORDER_H */
