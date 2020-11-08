#ifndef TEXTURE_BOX_H
#define TEXTURE_BOX_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TextureBox
{
    double min_u;
    double max_u;
    double min_v;
    double max_v;
}TextureBox;

void calc_texture_box(Model* model,TextureBox* texture_box);

void print_texture_box(TextureBox* texture_box);

#endif /* TEXTURE_BOX_H */
